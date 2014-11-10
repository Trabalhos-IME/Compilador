%{
	#include <stdio.h>
        #include <stdlib.h>
        #include "type_analisys.h"
        #include "lexical.h"
	#include "scope.h"
        #include "code_generation.h"

	#include "utils.h"

	extern int yylex( void );
	
	int yyerror( char *s)
	{
            fprintf( stderr, "Erro bison: %s \n", s);
            return 1;
	}

        pobject p, t, t1, t2;
        int l, l1, l2, n, s, globalIndex = 0;

        FILE* f ;
%}


%union {
        int boolean;
        int tokenSecundario;
        t_attrib attributedSymbol;
}




%token BOOLEAN
%token BREAK
%token CHAR
%token DO
%token ELSE
%token <boolean> T_FALSE
%token IF
%token INTEGER
%token STRING
%token <boolean> T_TRUE
%token VAR
%token WHILE

%left ASSIGN
%token COLON
%token COMMA
%left NOT_EQUAL
%left LESS_THAN
%left GREATER_THAN
%left LESS_OR_EQUAL
%left GREATER_OR_EQUAL
%left EQUAL_EQUAL

%left AND
%left OR
%left PLUS
%left MINUS
%left TIMES
%left DIVIDE

%token SEMICOLON

%token LEFT_BRACES
%token RIGHT_BRACES
%token LEFT_SQUARE
%token RIGHT_SQUARE
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS
%token NOT

%token <tokenSecundario> CHARACTER
%token <tokenSecundario> STRINGVAL
%token <tokenSecundario> ID
%token <tokenSecundario> NUMERAL

%token _EOF
%token UNKNOWN


%type <attributedSymbol> TP E F LI IDD IDU TRUE_ FALSE_ CHR STR NUM ME MT MW

%right RIGHT_PARENTHESIS ELSE

%%

PROGRAM: OPEN LDE _EOF /* close*/    {
                                        EndBlock();
                                        fclose(f);
                                        YYACCEPT;
                                     }
;

OPEN: /*empty*/ {
                    f = fopen("compiled_code.txt", "w");
                    NewBlock();
                }
;


LDE:	LDE DE
|	DE
;
/*Declaracao Externa pode ser uma Decalaracao de Variavel (DV)*/
DE:		DV
|		BLOCK
;
/*Declaracao de Variaveis e dada por:  var x, y, ..., z: integer; */
DV:		VAR LI COLON TP SEMICOLON   {
                                                p = $2._.LI.list;
                                                t = $4._.TP.type;
                                                while( p != NULL && p->eKind == NO_KIND_DEF_)
                                                {
                                                    p->eKind = VAR_;
                                                    p->_.Var.pType = t;

                                                    p->_.Var.nSize = $4._.TP.size;
                                                    p->_.Var.nIndex = globalIndex++;
                                                    p = p->pNext;
                                                }
                                            }
;
/*Lista de Identificadores e separada por virgula*/
LI:		LI COMMA IDD    {
                                    $3._.IDD.obj->pNext = $1._.LI.list;
                                    $$._.LI.list = $3._.IDD.obj;
                                }
|		IDD { $$._.LI.list = $1._.IDD.obj; }
;
/*Tipos permitidos: integer, char, boolean e string. Nao e possivel definir novos tipos*/
TP:		INTEGER { $$._.TP.type = pInt;
                          $$._.TP.size = 1;
                        }
|		CHAR    { $$._.TP.type = pChar;
                          $$._.TP.size = 1;
                        }
|		BOOLEAN { $$._.TP.type = pBool;
                          $$._.TP.size = 1;
                        }
|		STRING  { $$._.TP.type = pString;
                          $$._.TP.size = 1;
                        }
;
/**Bloco inicia em { e termina em } com uma lista de statements no interior*/
BLOCK:  NB LEFT_BRACES LS RIGHT_BRACES
;

/* Marcador semantico para tratamento de novo bloco*/
NB: 
{
	NewBlock();
}
;

/*Uma lista de statements recebe um statement ou outra lista de statement*/
LS:		S LS1
;
LS1:	S LS1
|		
;

MT: /*empty*/
                {
                    $$._.MT.label = newLabel();
                    fprintf(f, "\tTJMP_FW L%d\n", $$._.MT.label);
                }

;

ME: /*empty*/
                {
                    l2 = newLabel();
                    l1 = l2 - 1;
                    $$._.ME.label = l2;
                    fprintf(f, "\tTJMP_FW L%d\nL%d\n", l2, l1);
                }
;

MW: /*empty*/
                {
                    l = newLabel();
                    $$._.MW.label = l;
                    fprintf(f, "L%d\n", l);
                }
;
                /*if(x) statement*/
S:		IF LEFT_PARENTHESIS E  RIGHT_PARENTHESIS MT S     {
                                                                    t = $3._.E.type;
                                                                    l = $5._.MT.label;
                                                                    if(!CheckTypes(t, pBool))
                                                                    {
                                                                        Error(ERR_BOOL_TYPE_EXPECTED);
                                                                    }
                                                                    fprintf(f, "L%d:\n", l);
                                                                }
                /*if e else: if(x) statement; else statement*/
|		IF LEFT_PARENTHESIS E  RIGHT_PARENTHESIS MT S ELSE ME S    {
                                                                            t = $3._.E.type;
                                                                            l = $8._.ME.label;
                                                                            if(!CheckTypes(t, pBool))
                                                                            {

                                                                                Error(ERR_BOOL_TYPE_EXPECTED);
                                                                            }
                                                                            fprintf(f, "L%d:\n", l);
                                                                        }
                /*Laco while: while(x) statement;*/
|		WHILE MW LEFT_PARENTHESIS E RIGHT_PARENTHESIS MT S   {

                                                                        t = $4._.E.type;

                                                                        l1 = $2._.MW.label;
                                                                        l2 = $6._.MT.label;
                                                                        if(!CheckTypes(t, pBool))
                                                                        {

                                                                            Error(ERR_BOOL_TYPE_EXPECTED);
                                                                        }
                                                                        fprintf(f, "\tJMP_BW L%d\nL%d\n", l1, l2);
                                                                    }

|		BLOCK
		{ 
			EndBlock();  
		}

                /*Expressao*/
|		E SEMICOLON                                     {
                                                                    fprintf(f, "\tPOP\n");
                                                                }
                /*comando break;*/
|		BREAK SEMICOLON                                 {
                                                                    fprintf(f, "\tTJMP_FW L\n");

                                                                }
                /*Declaracao de variavel*/
|		DV
;

                /*Expressao e seus operadores logicos e aritmeticos*/
E:		E AND F                                 {
                                                            CheckTypesForLogicalOperations($1, $3);
                                                            $$._.E.type = pBool;
                                                            fprintf(f, "\tAND\n" );
                                                        }
|		E OR F                                  {
                                                            CheckTypesForLogicalOperations($1, $3);
                                                            $$._.E.type = pBool;
                                                            fprintf(f, "\tOR\n");
                                                        }
|		E LESS_THAN F                           {
                                                            CheckTypesForArithmeticsOperations($1, $3);
                                                            $$._.E.type = pBool;
                                                            fprintf(f, "\tLT\n");
                                                        }
|		E GREATER_THAN F                        {
                                                            CheckTypesForArithmeticsOperations($1, $3);
                                                            $$._.E.type = pBool;
                                                            fprintf(f, "\tGT\n");
                                                        }
|		E LESS_OR_EQUAL F                       {
                                                            CheckTypesForArithmeticsOperations($1, $3);
                                                            $$._.E.type = pBool;
                                                            fprintf(f, "\tLE\n");
                                                        }
|		E GREATER_OR_EQUAL F                    {
                                                            CheckTypesForArithmeticsOperations($1, $3);
                                                            $$._.E.type = pBool;
                                                            fprintf(f, "\tGE\n");
                                                        }
|		E EQUAL_EQUAL F                         {
                                                            CheckTypesForArithmeticsOperations($1, $3);
                                                            $$._.E.type = pBool;
                                                            fprintf(f, "\tEQ\n");
                                                        }
|		E NOT_EQUAL F                           {
                                                            CheckTypesForArithmeticsOperations($1, $3);
                                                            $$._.E.type = pBool;
                                                            fprintf(f, "\tNE\n");
                                                        }
|		E PLUS F 				{
                                                            CheckTypesForArithmeticsOperations($1, $3);
                                                            $$._.E.type = $1._.F.type;
                                                            fprintf(f, "\tADD\n");
                                                        }
|		E MINUS F                               {
                                                            CheckTypesForArithmeticsOperations($1, $3);
                                                            $$._.E.type = $1._.F.type;
                                                            fprintf(f, "\tSUB\n");
                                                        }
|		E TIMES F                               {
                                                            CheckTypesForArithmeticsOperations($1, $3);
                                                            $$._.E.type = $1._.F.type;
                                                            fprintf(f, "\tMUL\n");
                                                        }
|		E DIVIDE F                              {
                                                            CheckTypesForArithmeticsOperations($1, $3);
                                                            $$._.E.type = $1._.F.type;
                                                            fprintf(f, "\tDIV\n");

                                                        }
|		F                                       {
                                                            $$._.E.type = $1._.F.type;
                                                        }
;

F:		NOT F                                   {
                                                            if(!CheckTypes($2._.F.type, pBool))
                                                            {
                                                               Error(ERR_BOOL_TYPE_EXPECTED);
                                                            }
                                                            $$._.F.type = $2._.F.type;
                                                            fprintf(f, "\tNOT\n");
                                                        }
|		TRUE_                                    {
                                                            $$._.F.type = pBool;
                                                            n = $1._.TRUE.val;
                                                            fprintf(f, "\tLOAD_CONST %d\n", n);
                                                        }
|		FALSE_                                   {
                                                            $$._.F.type = pBool;
                                                            n = $1._.FALSE.val;
                                                            fprintf(f, "\tLOAD_CONST %d\n", n);
                                                        }
|		CHR                                     {
                                                            $$._.F.type = pChar;
                                                            n = $1._.CHR.pos;
                                                            fprintf(f, "\tLOAD_CONST %d\n", n);
                                                        }
|		STR                                     {
                                                            $$._.F.type = pString;
                                                            n = $1._.STR.pos;
                                                            fprintf(f, "\tLOAD_CONST %d\n", n);
                                                        }
|		NUM                                     {
                                                            $$._.F.type = pInt;
                                                            n = $1._.NUM.pos;
                                                            fprintf(f, "\tLOAD_CONST %d\n", n);
                                                        }
|		IDU                                     {
                                                            p = $1._.IDU.obj;
                                                            if(p->eKind != VAR_ )
                                                            {
                                                                if(p->eKind != UNIVERSAL_)
                                                                   Error(ERR_KIND_NOT_VAR);
                                                                $$._.F.type = pUniversal;
                                                            }
                                                            else
                                                            {
                                                                $$._.F.type = $1._.IDU.obj->_.Var.pType;
                                                                n = p->_.Var.nIndex;
                                                                fprintf(f, "\tLOAD_VAR %d\n", n);
                                                            }
                                                        }

|               IDU LEFT_SQUARE E RIGHT_SQUARE        {

                                                            p = $1._.IDU.obj;

                                                            if (!CheckTypes($3._.E.type, pInt))
                                                            {
                                                                    Error(ERR_INDEX_INVALID);
                                                            }

                                                            if( p-> eKind != VAR_ )
                                                            {
                                                                    Error(ERR_KIND_NOT_VAR);
                                                            }
                                                            else
                                                            {
                                                                t = p->_.Var.pType;

                                                                if (t!= pString)
                                                                {
                                                                  if ( t-> eKind != UNIVERSAL_ )
                                                                  Error(ERR_TYPE_STRING_EXPECTED);
                                                                }
                                                                else
                                                                {
                                                                 n = p->_.Var.nIndex;

                                                                 fprintf(f,"\tCHAR_AT %d\n", n);
                                                                }
                                                            }
                                                            $$._.F.type = pChar;
                                                        }

|		IDU ASSIGN E                            {
                                                            p = $1._.IDU.obj;
                                                            if(p->eKind != VAR_)
                                                            {
                                                                Error(ERR_KIND_NOT_VAR);
                                                                $$._.F.type = pUniversal;
                                                            }
                                                            else
                                                            {
                                                                t1 = p->_.Var.pType;
                                                                t2 = $3._.E.type;


                                                                if(!CheckTypes(t1, t2))
                                                                {
                                                                   Error(ERR_TYPE_MISMATCH);
                                                                }
                                                                $$._.F.type = t2;


                                                                fprintf(f, "\tDUP\n\tSTORE_VAR %d\n", p->_.Var.nIndex);

                                                            }
                                                        }
;

IDD: ID
	{
                $$._.IDD.name = $1;
		object *p;
                        if( (p= SearchCurrentLevel($1)) != NULL)
                        {
                                Error(ERR_REDECL);
                        }
			else
                        {
                                p = Define($1);
                        }
		p->eKind = NO_KIND_DEF_;
                $$._.IDD.obj = p;
	}
;



IDU: ID
        {
                $$._.IDD.name = $1;
		object *p;
                        if( (p= SearchAllSymbolTable($1)) == NULL)
			{
                                Error(ERR_NOT_DECL);
                                p = Define($1);
			}

                $$._.IDD.obj = p;
	}
;
;

TRUE_:	T_TRUE { $$._.TRUE.type = pBool;
               $$._.TRUE.val = 1;
             }
             // 1 equivale a true
;

FALSE_:	T_FALSE { $$._.FALSE.type = pBool;
                $$._.FALSE.val = 0;
              }
              // 0 equivale a false
;

CHR:	CHARACTER { $$._.CHR.type = pChar;
                    $$._.CHR.pos = $1;
                    $$._.CHR.val = getCharConst($1);
                  }
;

STR:	STRINGVAL { $$._.STR.type = pString;
                    $$._.STR.pos = $1;
                    $$._.STR.val = getStringConst($1);
                  }
                  //TODO: investigar alocacao de memoria da string
;

NUM:	NUMERAL { $$._.NUM.type = pInt;
                  $$._.NUM.pos = $1;
                  $$._.NUM.val = getIntConst($1);
                }
;

%%

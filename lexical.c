#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "lexical.h"


t_const constants[MAX_CONSTS];
char*   namesTable[MAX_NAMES];
int numNames = 0;
int numConstants = 0;

int tokenSecundario = -1;

//vetor de palavras reservadas
char* keyWords[] = {
    "boolean", "break", "char", "do", "else", "false", "if",
    "integer", "string", "true", "var", "while"

};

t_token reservedTokens[] = {
    BOOLEAN, BREAK, CHAR, DO, ELSE, T_FALSE, IF,
    INTEGER, STRING, T_TRUE, VAR, WHILE
};

char nextChar = '\x20';
//hash_table myHash;

FILE *fileToCompile;


/*********** Begin Function Definitions *************/

/**
	Adiciona uma constante do tipo caractere no vetor de constantes
	@param c O caractere a ser adicionado
	@return int A posicao do vetor em que a constante foi armazenada
*/
int addCharConst(char c){
	t_const charConstant;
	charConstant.type = 0;
	charConstant._.cVal = c;
	constants[numConstants] = charConstant;

	return numConstants++;
}
/**
	Adiciona uma constante do tipo inteiro no vetor de constantes
	@param n O inteiro a ser adicionado
	@return int A posicao do vetor em que a constante foi armazenada
*/
int addIntConst(int n){
	t_const intConstant;
	intConstant.type = 1;
	intConstant._.nVal = n;
	constants[numConstants] = intConstant;

	return numConstants++;
}
/**
	Adiciona uma constante do tipo string no vetor de constantes
	@param s A string a ser adicionada 
	@return int A posicao do vetor em que a constante foi armazenada
*/
int addStringConst(char *s){
	t_const stringConstant;
	stringConstant.type = 2;
	MYSTRDUP(stringConstant._.sVal, s);
	constants[numConstants] = stringConstant;

	return numConstants++;
}

/**
	Recupera o valor de uma constante caractere a partir de sua posicao no vetor de constantes
*/
char getCharConst(int n){
	return constants[n]._.cVal;
}

/**
	Recupera o valor de uma constante inteira a partir de sua posicao no vetor de constantes
*/
int getIntConst(int n){
	return constants[n]._.nVal;
}

/**
	Recupera o valor de uma constante string a partir de sua posicao no vetor de constantes
*/
char *getStringConst(int n){
	return constants[n]._.sVal;
}


/**
	Verifica se uma determinada palavra pertence ao conjunto de palavras reservadas da linguagem.
	@param name A palavra que deseja-se verificar
	@return t_token O token da palavra reservada representada ou o token ID
*/
t_token searchKeyWord(char* name, int begin, int end){
     if(begin <= end){
		int middle = (end + begin)/2;

        int result = strcmp(name, keyWords[middle]);
          if(result == 0){
              return (t_token) middle;
          }
          else 
          	if(result < 0)
          	{
              return searchKeyWord(name, begin, middle-1);

          	}
          	else
            {
                return searchKeyWord(name, middle+1, end);
            }
     }
     else
       return ID;
}

/**
	Funcao para converter uma cadeia de caracteres numericos em um unico numero inteiro
*/
int fromStringToInt(char *str)
{
    int result = 0;
 
    // Iterate through all characters of input string and update result
    for (int i = 0; str[i] != '\0'; ++i)
        result = result*10 + str[i] - '0';
 
    
    return result;
}

/**
	Insere ou busca identificadores na tabela de nomes
	@param name O identificador que deseja-se buscar ou inserir
	@return int O valor correspondente ao token secundario do identificador
*/
int searchName(char* name){
	/*int location;

	struct mystruct *data  = hash_retrieve(name, &myHash);

	if(data == 0)
		location = hash_insert(struct my_struct *data, &myHash);*/

	//return location;
    int i;
    for(i = 0; i < numNames; i++)
    {
        if( !strcmp(name, namesTable[i]))
        {
            return i;
        }
    }

   MYSTRDUP(namesTable[numNames++], name);


    return (numNames-1);
}

/**
	Le um caractere do arquivo de entrada
*/
char readChar(){ //TODO check where to open the file

	char ch;
	ch = fgetc(fileToCompile);
	return ch;
}

/**
	Implementacao do automato finito do analisador lexico
*/
t_token nextToken(){

	t_token token;
    //int tokenSecundario;

    //Pula espacos em branco
	while(isspace(nextChar))
	{
		nextChar = readChar();
	}
    //le alfa numericos
	if( isalpha(nextChar) )
	{
		char text[MAX_ID_LEN+1];
		int i = 0;
		do
		{
			text[i++] = nextChar;
			nextChar = readChar();
		}
		while( isalnum(nextChar) || nextChar == '_');
		text[i] = '\0';

        printf("%s\n", text); //DEBUG

        token = searchKeyWord(text, 0, KEYWORDS_LEN);
		if(token == ID)
		{
            tokenSecundario = searchName(text);
        }
        else
        {
            //preciso fazer esse mapeamento porque a enumeracao criada pelo bison nao inicia em 0.
            //O valor retornado por searchKeyWord considera apenas a posicao dentro do vetor
            token = token + RESERVED_OFFSET; //mapping
        }
	}
	else
    //Se for digito
	if (isdigit(nextChar) )
	{

		char numeral[MAX_NUM_LEN+1];
		int i = 1;
		do
		{
			numeral[i++] = nextChar;
			nextChar = readChar();
		}
		while( isdigit(nextChar) );
		numeral[i] = '\0';

        token = NUMERAL;    //constante numerica
		tokenSecundario = addIntConst( fromStringToInt(numeral) );
	}
	else
    //Se inicia por aspas duplas
	if (nextChar == '"')
	{

		char string[MAX_STR_LEN+1];
        int i = 0;
		do
		{
			string[i++] = nextChar;
			nextChar = readChar();
		}
        while(nextChar != '"'); //le as aspas de encerramento
        string[i++] = nextChar;
        string[i] = '\0';

        nextChar = readChar();

        token = STRINGVAL;     //constante do tipo string
		tokenSecundario = addStringConst(string);
	}
	else
	switch(nextChar)
	{
        printf("TO NO SWITCH\n");
        //Se inicia por aspas simples
		case '\'':
			nextChar = readChar();
            token = CHARACTER;  //constante caractere
			tokenSecundario = addCharConst(nextChar);
			nextChar = readChar(); //le o ' de fechamento
			nextChar = readChar();
			break;
		case '=':
			nextChar = readChar();
			if( nextChar == '=')
			{
				token = EQUAL_EQUAL;
				nextChar = readChar();
			}
			else
			{
				token = ASSIGN;
			}
			break;
		case ':':
			nextChar = readChar();
			token = COLON;
			break;
		case ';':
			nextChar = readChar();
            token = SEMICOLON;
			break;
		case ',':
			nextChar = readChar();
			token = COMMA;
			break;
		case '[':
			nextChar = readChar();
			token = LEFT_SQUARE;
			break;
		case ']':
			nextChar = readChar();
			token = RIGHT_SQUARE;
			break;
		case '{':
			nextChar = readChar();
			token = LEFT_BRACES;
			break;
		case '}':
			nextChar = readChar();
			token = RIGHT_BRACES;
			break;
		case '(':
			nextChar = readChar();
			token = LEFT_PARENTHESIS;
			break;
		case ')':
			nextChar = readChar();
			token = RIGHT_PARENTHESIS;
			break;
		case '&':
			nextChar = readChar();
			token = AND;
			break;
		case '|':
			nextChar = readChar();
			token = OR;
			break;
		case '<':
			nextChar = readChar();
			if( nextChar == '=')
			{
				token = LESS_OR_EQUAL;
				nextChar = readChar();
			}
			else
			{
				token = LESS_THAN;
			}
			break;
		case '>':
			nextChar = readChar();
			if( nextChar == '=')
			{
				token = GREATER_OR_EQUAL;
				nextChar = readChar();
			}
			else
			{
				token = GREATER_THAN;
			}
			break;
		case '+':
            nextChar = readChar();
            /*if( nextChar == '+')
			{
				token = PLUS_PLUS;
				nextChar = readChar();
			}
			else
            {*/
				token = PLUS;
            //}
			break;
		case '-':
			nextChar = readChar();
            /*if( nextChar == '-')
			{
				token = MINUS_MINUS;
				nextChar = readChar();
			}
			else
            {*/
				token = MINUS;
            //}
			break;
		case '*':
			nextChar = readChar();
			token = TIMES;
			break;
		case '/':
			nextChar = readChar();
			token = DIVIDE;
			break;
        /*case '.':
			nextChar = readChar();
			token = DOT;
            break;*/
		case '!':
			nextChar = readChar();
			if( nextChar == '=')
			{
				token = NOT_EQUAL;
				nextChar = readChar();
			}
			else
			{
				token = NOT;
			}
			break;
		default:
            if(nextChar == EOF)
                token = _EOF;
            else
                token = UNKNOWN;
	}
    //printf("Token da Vez: %u\n", token);
	return token;
	printf("END TOKEN\n");
}
/**
 * @brief yylex
 * Funcao que sera chamada pelo parser. Proxy pra nextToken.
 * @return
 */
int yylex(void)
{
        t_token token_lido = nextToken();

        printToken(token_lido); //DEBUG

        switch(token_lido)
        {
        case ID :
        case NUMERAL:
        case STRINGVAL:
        case CHARACTER:
        case BOOLEAN:
                yylval.tokenSecundario = tokenSecundario;
                break;
        case _EOF:
            fclose(fileToCompile);
            break;
        default:
                yylval.tokenSecundario = 0;
                break;
        }

        return token_lido;
}

void printToken(t_token token)
{
    switch (token) {
    case BOOLEAN:
        printf("BOOLEAN");
        break;
    case BREAK:
        printf("BREAK");
        break;
    case CHAR:
        printf("CHAR");
        break;
    case DO:
        printf("DO");
        break;
    case T_FALSE:
        printf("FALSE");
        break;
    case IF:
        printf("IF");
        break;
    case INTEGER:
        printf("INTEGER");
        break;
    case STRING:
        printf("STRING");
        break;
    case T_TRUE:
        printf("TRUE");
        break;
    case VAR:
        printf("VAR");
        break;
    case WHILE:
        printf("WHILE");
        break;
    case ASSIGN:
        printf("ASSIGN");
        break;
    case COLON:
        printf("COLON");
        break;
    case COMMA:
        printf("COMMA");
        break;
    case NOT_EQUAL:
        printf("NOT_EQUAL");
        break;
    case LESS_THAN:
        printf("LESS_THAN");
        break;
    case GREATER_THAN:
        printf("GREATER_THAN");
        break;
    case LESS_OR_EQUAL:
        printf("LESS_OR_EQUAL");
        break;
    case GREATER_OR_EQUAL:
        printf("GREATER_OR_EQUAL");
        break;
    case EQUAL_EQUAL:
        printf("EQUAL_EQUAL");
        break;
    case AND:
        printf("AND");
        break;
    case OR:
        printf("OR");
        break;
    case PLUS:
        printf("PLUS");
        break;
    case MINUS:
        printf("MINUS");
        break;
    case TIMES:
        printf("TIMES");
        break;
    case DIVIDE:
        printf("DIVIDE");
        break;
    case SEMICOLON:
        printf("SEMICOLON");
        break;
    case LEFT_BRACES:
        printf("LEFT_BRACES");
        break;
    case RIGHT_BRACES:
        printf("RIGHT_BRACES");
        break;
    case LEFT_SQUARE:
        printf("LEFT_SQUARE");
        break;
    case RIGHT_SQUARE:
        printf("RIGHT_SQUARE");
        break;
    case LEFT_PARENTHESIS:
        printf("LEFT_PARENTHESIS");
        break;
    case RIGHT_PARENTHESIS:
        printf("RIGHT_PARENTHESIS");
        break;
    case NOT:
        printf("NOT");
        break;
    case CHARACTER:
        printf("CHARACTER");
        break;
    case STRINGVAL:
        printf("STRINGVAL");
        break;
    case ID:
        printf("ID");
        break;
    case NUMERAL:
        printf("NUMERAL");
        break;
    case _EOF:
        printf("EOF");
        break;
    case UNKNOWN:
        printf("UNKNOWN");
        break;
    default:
        printf("Deveria dar erro de analise lexica");
        break;
    }
    printf("\n");
}

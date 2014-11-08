#ifndef _LEXICAL_H
#define _LEXICAL_H

#include <stdio.h>
#include "hash.h"
#include "utils.h"
#include "type_analisys.h"
#include "parser.tab.h"


/**
	t_token Enumeracao com todos os tokens possiveis para a linguagem.
	Contem palavras reservadas, simbolos, tokens regulares e o token desconhecido
*/
/*typedef enum {
	//palavras reservadas
	ARRAY, BOOLEAN, BREAK, CHAR, CONTINUE, DO, ELSE, FALSE, FUNCTION, IF,
	INTEGER, OF, STRING, STRUCT, TRUE, TYPE, VAR, WHILE,

	//simbolos
	ASSIGN, COLON, SEMI_COLON, COMMA, EQUAL_EQUAL, LEFT_SQUARE, RIGHT_SQUARE,
	LEFT_BRACES, RIGHT_BRACES, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, AND,
	OR, LESS_THAN, GREATER_THAN, LESS_OR_EQUAL, GREATER_OR_EQUAL, NOT_EQUAL,
	PLUS, PLUS_PLUS, MINUS, MINUS_MINUS, TIMES, DIVIDE, DOT, NOT, 

	//tokens regulares
	CHARACTER, NUMERAL, STRINGVAL, ID,
	//token desconhecido
	UNKNOWN

} t_token;*/

typedef enum yytokentype t_token;

/**
	Estrutura capaz de representar uma constante da linguagem.
	Constantes podem ser ...
*/
typedef struct {

	unsigned short type;
	union {
		char cVal; // type 0
		int nVal; // type 1
		char* sVal; // type 2
	} _;

} t_const;


int addCharConst(char c);
int addIntConst(int n);
int addStringConst(char *s);

char getCharConst(int n);
int getIntConst(int n);
char *getStringConst(int n);

t_token searchKeyWord(char* name, int begin, int end);
int searchName(char* name);

int fromStringToInt(char* string);

char readChar();
t_token nextToken();
int tokenSecundario;


// Variables declaration
extern t_const constants[MAX_CONSTS];
extern char*   namesTable[MAX_NAMES];
extern int numConstants;
//vetor de palavras reservadas
extern  char* keyWords[];
extern char nextChar;
//extern hash_table myHash;
extern FILE *fileToCompile;

#endif


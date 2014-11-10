#include "lexical.h"
#include "parser.tab.h"

extern int yyparse();
extern FILE *f;

int main(int argc, char** argv)
{
	printf("Start\n");
    if(argc < 1)
        fileToCompile = fopen("teste_string.txt", "r");
    else
        fileToCompile = fopen(argv[1], "r");
    if(!yyparse())
        printf("Compilou legal\n");
    else
        printf("Houve erros de compilacao\n");

	return 0;
}

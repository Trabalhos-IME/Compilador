#include "lexical.h"
#include "parser.tab.h"

extern int yyparse();
extern FILE *f;

int main(int argv, char** argc)
{
	printf("Start\n");
	
	fileToCompile = fopen("teste.txt", "r");
    f = fopen("compiled_code.txt", "w");
    /*t_token t = nextToken();
	while( nextChar != EOF)
	{
		printf("%d\n", t);
		t = nextToken();
    }*/
    if(!yyparse())
            printf("Compilou legal\n");
    else
        printf("Mostre-me os erros\n");


	fclose(fileToCompile);
    fclose(f);

	return 0;
}

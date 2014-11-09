#include <stdlib.h>
#include "scope.h"


pobject SymbolTable[MAX_NEST_LEVEL];
pobject SymbolTableLast[MAX_NEST_LEVEL];
int numCurrentLevel = -1;

/**
	Funcao que acrescenta um nivel de escopo na tabela de simbolos
*/
int NewBlock()
{
	SymbolTable[++numCurrentLevel] = NULL;
	SymbolTableLast[numCurrentLevel] = NULL;
	return numCurrentLevel;
}

/**
  Funcao que finaliza o bloco de escopo corrente. A liberacao dos elementos do escopo finalizado nao ocorre neste momento
*/
int EndBlock()
{
	return --numCurrentLevel;
}
/**
    Funcao que insere identificadores na tabela de simbolos
*/
pobject Define(int aName)
{
	pobject obj = (pobject) malloc(sizeof(object));

	obj->nName = aName;
	obj->pNext = NULL;

	if(SymbolTable[numCurrentLevel] == NULL)
	{
		SymbolTable[numCurrentLevel] = obj;
	}
	else
	{
		SymbolTable[numCurrentLevel]->pNext = obj;
	}
    SymbolTableLast[numCurrentLevel] = obj;

	return obj;
}

/**
	Busca um identificador no nivel corrente
*/
pobject SearchCurrentLevel(int aName)
{
	pobject obj = SymbolTable[numCurrentLevel];

	while(obj != NULL)
	{
		if( obj->nName == aName)
		{
			break;
		}
		else
		{
			obj = obj->pNext;
		}
	}
    return obj;
}
/**
 * @brief SearchAllSymbolTable
 * Funcao que procura por um indentificador em todos os niveis da tabela de simbolos
 * @param aName token secundario do identificador que deseja-se buscar
 * @return Referencia para o identificador na tabela de simbolos ou NULL caso ele nao seja encontrado
 */
pobject SearchAllSymbolTable(int aName)
{
	int i;
	pobject obj = NULL;

    for( i = numCurrentLevel; i >= 0; --i)
    {
        obj = SymbolTable[i];
        while( obj != NULL)
        {
            if(obj->nName == aName)
            {
                break;
            }
            else
            {
                obj = obj->pNext;
            }

        }
        if(obj != NULL)
            break;
    }
    return obj;
}



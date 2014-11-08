#ifndef _SCOPE_H
#define _SCOPE_H

#include <stdio.h>
#include "utils.h"
#include "type_analisys.h"

extern pobject SymbolTable[MAX_NEST_LEVEL];
extern pobject SymbolTableLast[MAX_NEST_LEVEL];
extern int numCurrentLevel;






int NewBlock();
int EndBlock();
pobject SearchCurrentLevel(int aName);
pobject SearchAllSymbolTable(int aName);
pobject Define(int aName);

#endif

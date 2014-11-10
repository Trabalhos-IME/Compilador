#ifndef _UTILS_H
#define _UTILS_H

//#include "type_analisys.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONSTS      256 //magic number
#define MAX_NEST_LEVEL  32
#define MAX_STR_LEN     256
#define MAX_NUM_LEN     256
#define MAX_ID_LEN      256
#define MAX_NAMES       256
#define KEYWORDS_LEN    11
#define RESERVED_OFFSET BOOLEAN


#define ERR_BOOL_TYPE_EXPECTED      88
#define ERR_TYPE_MISMATCH           777
#define ERR_INT_TYPE_EXPECTED       998
#define ERR_TYPE_STRING_EXPECTED    222
#define ERR_KIND_NOT_VAR            556
#define ERR_REDECL                  234
#define ERR_NOT_DECL                567
#define ERR_INDEX_INVALID           909


// Macro para alocar memoria e copiar uma string (deep copy)
#define MYSTRDUP(dest,source) strcpy(dest = (char*) malloc(strlen(source)+1),source)

void Error(int code);



#endif

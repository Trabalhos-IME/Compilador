#include "utils.h"

void Error(int code)
{
    char *error_message;
    switch (code) {
    case ERR_REDECL:
        MYSTRDUP(error_message, "Erro de redeclaracao");
        break;
    case ERR_NOT_DECL:
        MYSTRDUP(error_message, "Identificador nao declarado");
        break;
    case ERR_BOOL_TYPE_EXPECTED:
        MYSTRDUP(error_message, "Tipo booleano esperado");
        break;
    case ERR_INT_TYPE_EXPECTED:
        MYSTRDUP(error_message, "Tipo inteiro esperado");
        break;
    case ERR_KIND_NOT_VAR:
        MYSTRDUP(error_message, "Kind nao e o de uma variavel");
        break;
    case ERR_TYPE_MISMATCH:
        MYSTRDUP(error_message, "Erro de incompatibilidade de tipo");
        break;
    case ERR_TYPE_STRING_EXPECTED:
        MYSTRDUP(error_message, "Tipo string esperado");
        break;
    case ERR_INDEX_INVALID:
        MYSTRDUP(error_message, "Indice invalido");
    default:
        MYSTRDUP(error_message, "Erro desconhecido");
        break;
    }

    printf("%s\n", error_message);
    free(error_message);
}


void debugPrint(FILE *f, char *msg)
{
    fprintf(f, "%s", msg);
}

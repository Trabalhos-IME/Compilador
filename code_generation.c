#include "code_generation.h"


/**
  Gera labels unicos
 */
int newLabel()
{
    static int labelNo = 0;
    return labelNo++;
}

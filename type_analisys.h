#ifndef _TYPE_ANALISYS_H
#define _TYPE_ANALISYS_H

#include <stdio.h>
#include "utils.h"

#define IS_TYPE_KIND(k) ( (k) == SCALAR_TYPE_ )

/**
  Enumeracao com os kinds dos tipo de dados
*/

typedef enum {
    NO_KIND_DEF_ = -1, VAR_, SCALAR_TYPE_, UNIVERSAL_

} t_kind;

typedef struct object
{
    int nName;
    struct object *pNext;
    t_kind eKind;

    union{
      struct{
          struct object *pType;
          int nIndex;
          int nSize;
      } Var;
    }_;

} object, *pobject;


typedef struct t_attrib
{
    union
    {
      struct {
        pobject type;
        int size;
      } TP, E, F;

      struct{
        pobject list;
      } LI;

      struct{
        int name;
        pobject obj;
      } IDD, IDU;

      struct{
          pobject type;
          int val;
      } TRUE, FALSE;

      struct{
          pobject type;
          int pos;
          char val;
      } CHR;

      struct {
          pobject type;
          int pos;
          char* val;
      } STR;

      struct{
         pobject type;
         int pos;
         int val;
      } NUM;

      struct{
          int label;
      } MT, ME, MW;
    }_;

} t_attrib;


extern object int_;
extern pobject pInt;

extern object char_ ;
extern pobject pChar;

extern object bool_;
extern pobject pBool;

extern object string_ ;
extern pobject pString ;

extern object universal_ ;
extern pobject pUniversal ;

/**
  Verifica se dois tipos sao compativeis por nome
*/
int CheckTypes(pobject type1, pobject type2);
int CheckTypesForLogicalOperations(t_attrib op1, t_attrib op2);
int CheckTypesForArithmeticsOperations(t_attrib op1, t_attrib op2);

#endif

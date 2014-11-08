#include "type_analisys.h"


object int_ = { -1, NULL, SCALAR_TYPE_};
pobject pInt = &int_;

object char_ = { -1, NULL, SCALAR_TYPE_};
pobject pChar = &char_;

object bool_ = { -1, NULL, SCALAR_TYPE_};
pobject pBool = &bool_;

object string_ = { -1, NULL, SCALAR_TYPE_};
pobject pString = &string_;

object universal_ = { -1, NULL, SCALAR_TYPE_};
pobject pUniversal = &universal_;


int CheckTypes(pobject type1, pobject type2)
{
    if(type1 == type2)
        return 1; /*true*/
    else
    {
    if( type1 == pUniversal || type2 == pUniversal)
        return 1;
    else
    {
    if( type1->eKind == UNIVERSAL_ || type2->eKind == UNIVERSAL_)
        return 1;
    }
    }
    return 0; /*false*/
}

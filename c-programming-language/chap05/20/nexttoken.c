#include "gettoken.h"
#include "nexttoken.h"
#include "global.h"

int nexttoken(void)
{
    int type;

    type = gettoken();
    prevtoken = YES;

    return type;
}

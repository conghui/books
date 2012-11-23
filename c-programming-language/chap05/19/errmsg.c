#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "errmsg.h"
#include "global.h"

void errmsg(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    prevtoken = YES;
    va_end(ap);
}

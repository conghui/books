#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "error.h"

void error(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    exit(EXIT_FAILURE);
    va_end(ap);
}

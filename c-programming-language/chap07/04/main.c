#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT    100

int minscanf(char *fmt, ...)
{
    va_list ap;
    char *p;
    char localfmt[LOCALFMT];
    char *sval;
    int *ival;
    unsigned *uval;
    double *dval;

    i = 0;             /* index for localfmt array              */
    va_start(ap, fmt); /* make ap points to the 1st unnamed arg */

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            localfmt[i++] = *p; /* collect chars */
            continue;
        }

        localfmt[i++] = '%';
        while (*(p+1) && !isalpha(*(p+1))) {
            localfmt[i++] = *++p;
        }

        localfmt[i++] = *(p+1); /* format letter */
        localfmt[i] = '\0';

        switch (*++p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int *);
                scanf(localfmt, ival);
                break;
            case 'o':
            case 'x':
            case 'X':
            case 'u':
                uval = va_arg(ap, unsigned *);
                scanf(localfmt, uval);
                break;
            case 'd':
                dval = va_arg(ap, double *);
                scanf(localfmt, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf(localfmt, sval);
                break;
            default:
                scanf(localfmt);
                break;
        }
        i = 0;
    }

    va_end(ap);
}

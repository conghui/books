#ifndef GETOP_H
#define GETOP_H

#include <ctype.h>
#include "getch.h"

#define NUMBER  '0' /* signal that a number was found */
#define NAME 'n'    /* signal that a name was found */

int getop(char *s);
#endif

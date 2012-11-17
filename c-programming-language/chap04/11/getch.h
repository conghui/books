#ifndef GETCH_H
#define GETCH_H

#include <stdio.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int c);

#endif

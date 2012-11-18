#include <stdio.h>
#include <stdlib.h>

#include "ungets.h"
#include "getop.h"
#include "stack.h"

#define MAXOP 100 /* max size of operand or operator */

int main(int argc, char **argv)
{
    char   s[MAXOP];
    double op2;

    while (--argc > 0) {
        ungets(" ");
        ungets(*++argv);

        switch (getop(s)) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
            case '*':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 == 0) {
                    fprintf(stderr, "error: zero divisor\n");
                    return -1;
                }
                push(pop() / op2);
                break;
            default:
                fprintf(stderr, "error: unknown command %s\n", s);
                argc = 1;   /* next step is to jump out of while loop */
                break;
        }
    }

    printf("\t%.8g\n", pop());  /* print the result */

    return 0;
}

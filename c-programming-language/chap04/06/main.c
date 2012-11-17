#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "getop.h"
#include "stack.h"

#define MAXOP   100
#define ALPHA_SIZE 26   /* the size of alphabetic A-Z */

void zeroArray(void *arr, size_t siz, size_t type_siz);

int main()
{
    int type, var = 0;
    double op2, v;
    char s[MAXOP];
    double variable[ALPHA_SIZE];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push(fmod(pop(), op2));
                }
                else {
                    perror("zero divisor");

                }
                break;
            case '=':
                pop();
                if (var >= 'A' && var <= 'Z') {
                    variable[var - 'A'] = pop();
                }
                else {
                    fprintf(stderr, "error: no variable name\n");
                }
                break;
            case '\n':
                v = pop();
                printf("\t%.8g\n", v);
                break;
            default:
                if (type >= 'A' && type <= 'Z') {
                    push(variable[type - 'A']);
                }
                else if (type == 'V') {
                    push(v);
                }
                else {
                    printf("error: unknown command %s\n", s);
                }
                break;
        }
        
        var = type;
    }

    return 0;
}

void zeroArray(void *arr, size_t siz, size_t type_siz)
{
    memset(arr, 0, siz * type_siz);
}

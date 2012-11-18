#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

static double buf[STACK_SIZE]; /* buffer of the stack           */
static double *ptop = buf;     /* point to the top of the stack */

/**
 * @brief push element n to stack
 *
 * @param n the element to be pushed
 */
void push(double n)
{
    if (ptop == buf + STACK_SIZE) { /* full */
        fprintf(stderr, "cannot push %f, the stack is full\n", n);
        exit(EXIT_FAILURE);
    }

    *ptop++ = n;
}

/**
 * @brief pop an element from stack
 *
 * @return the popped elemen
 */
double pop(void)
{
    if (ptop == buf) { /* empty */
        fprintf(stderr, "can not pop element, the stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return *--ptop;
}

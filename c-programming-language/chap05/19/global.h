#ifndef GLOBAL_H

#define GLOBAL_H

#define MAXTOKEN 100    /* max # of char in a token */
extern char token[];
extern char name[];
extern char out[];
extern int tokentype;
extern int prevtoken;

enum {NO, YES};
enum {NAME, PARENS, BRACKETS};

#endif /* end of include guard: GLOBAL_H */

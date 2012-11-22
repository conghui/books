#ifndef GLOBAL_H

#define GLOBAL_H

#define NUMERIC 1   /* numeric sort */
#define DECR    2   /* sort in decrease order */
#define FOLD    4   /* fold upper and lower case */
#define DIR     8   /* directory order */
#define LINES   100 /* max # of lines to be sorted */

#include <stdlib.h>

extern int pos1;
extern int pos2;
extern unsigned char option;

#endif /* end of include guard: GLOBAL_H */

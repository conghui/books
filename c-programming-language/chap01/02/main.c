#include <stdio.h>

/* If the character next to the backslash character '\' is not the 
 * specified character, the behavior is undefined. */

int main(void)
{
    printf("hello, world\y"); /* undefined behavior */
    printf("hello, world\7"); /* undefined behavior */
    printf("hello, world\?"); /* undefined behavior */

    return 0;
}

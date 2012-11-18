#include <stdlib.h>
#include <stdio.h>

#include "entab.h"
#include "tabpos.h"

/**
 * @brief replace strings of blanks with tabs and blanks
 *
 * @param tab array of stop tab
 */
void entab(char *tab)
{
   int c;
   int pos;
   int nb = 0;                                    /* # of blanks necessary */
   int nt = 0;                                    /* # of tabs necessary   */

   for (pos = 1; (c = getchar()) != EOF; pos++) {
       if (c == ' ') {
           if (tabpos(pos, tab) == NO) {
               ++nb;                              /* increase # of blanks  */
           }
           else {
               nb = 0;                            /* reset # of blanks     */
               ++nt;                              /* increse # of tabs     */
           }
       }
       else {
           for (; nt > 0; nt--) {
               putchar('\t');                     /* output tab(s)         */
           }

           if (c == '\t') {
               nb = 0;                            /* forget the blanks     */
           }
           else {
               for (; nb > 0; nb--) {
                   putchar(' ');                  /* output blanks         */
               }
           }

           putchar(c);

           if (c == '\n') {
               pos = 0;
           }
           else if (c == '\t') {
               while (tabpos(pos, tab) != YES) {
                   pos++;
               }
           }
       }
   }
}

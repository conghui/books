#include <ctype.h>

#include "error.h"
#include "readargs.h"
#include "global.h"


void readargs(int argc, const char **argv)
{
    int c;

    const char *progname = argv[0];

    while (--argc > 0 && ((c = (*++argv)[0]) == '-' || c == '+'))
    {
        if (c == '-' && !isdigit(*(argv[0] + 1)))
        {
            while ((c = *++argv[0]) != '\0')
            {
                switch (c)
                {
                    case 'n':
                        option |= NUMERIC;
                        break;

                    case 'r':
                        option |= DECR;
                        break;

                    case 'd':
                        option |= DIR;
                        break;

                    case 'f':
                        option |= FOLD;
                        break;

                    default:
                        error("usage: %s -dfrn [+pos1] [-pos2]\n", progname);
                        break;
                }
            }
        }
        else if (c == '-')
        {
            pos2 = atoi(argv[0] + 1);
        }
        else if ((pos1 = atoi(argv[0] + 1)) < 0)
        {
            error("usage: %s -dfrn [+pos1] [-pos2]\n", progname);
        }
    }

    if (argc || pos1 > pos2)
    {
        error("usage: %s -dfrn [+pos1] [-pos2]\n", progname);
    }
}

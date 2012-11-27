#include "iobuf.h"
#include <unistd.h>
#include <fcntl.h>

#define PERMS 0666

FILE _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
    {0, (char *)0, (char *)0, _READ, 0},
    {0, (char *)0, (char *)0, _WRITE, 1},
    {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2}
};

int fseek(FILE *fp, long offset, long origin) {
    unsigned nc; /* # of char to flush */
    long rc = 0; /* return code */

    if (fp->flag & _READ) {
        if (origin == 1) { /* from current position ? */
            offset -= fp->cnt;  /* remember chars in buffer */
        }
        rc      = lseek(fp->fd, offset, origin);
        fp->cnt = 0;
    }
    else if (fp->flag & _WRITE) {
        if ((nc = fp->ptr - fp->base) > 0) {
            if (write(fp->fd, fp->base, nc) != nc)
                rc = -1;
        }
        if (rc != -1) {
            rc = lseek(fp->fd, offset, origin);
        }
    }

    return (rc == -1) ? -1 : 0;
}

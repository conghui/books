#include "iobuf.h"
#include <unistd.h>
#include <fcntl.h>

#define PERMS 0666

FILE _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
    {0, (char *)0, (char *)0, _READ, 0},
    {0, (char *)0, (char *)0, _WRITE, 1},
    {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2}
};

int _flushbuf(int x, FILE *fp)
{
    unsigned nc;        /* # of chars to flush  */
    int      bufsize;   /* size of buffer alloc */

    if (fp < _iob || fp >= _iob + OPEN_MAX) {
        return EOF; /* invalid pointer */
    }

    if ((fp->flag & (_WRITE | _ERR)) != _WRITE) {
        return EOF;
    }

    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

    if (fp->base == NULL) { /* no buffer yet */
        if ((fp->base = malloc(bufsize)) == NULL) {
            fp->flag |= _ERR;
            return EOF; /* can get buffer       */
        }
    }
    else {              /* buffer already exist */
        nc = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, nc) != nc) {
            fp->flag |= _ERR;
            return EOF;
        }
    }

    fp->ptr = fp->base; /* begining of buffer */
    *fp->ptr++ = (char) x;
    fp->cnt = bufsize - 1;
    return x;
}

int fclose(FILE *fp)
{
    int rc;     /* return code */
    if ((rc = fflush(fp)) != EOF) {
        free(fp->base);
        fp->base = NULL;
        fp->ptr = NULL;
        fp->cnt = 0;
        fp->flag &= ~(_READ | _WRITE);
    }

    return rc;
}

int fflush(FILE *fp)
{
    int rc = 0;

    if (fp < _iob || fp >= _iob + OPEN_MAX) {
        return EOF; /* invalid pointer */
    }

    if (fp->write & _WRITE) {
        rc = _flushbuf(0, fp);
    }

    fp->ptr = fp->base;
    fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

    return rc;
}

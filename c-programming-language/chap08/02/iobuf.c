#include "iobuf.h"
#include <unistd.h>
#include <fcntl.h>

#define PERMS 0666

FILE _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
    {0, (char *)0, (char *)0, _READ, 0},
    {0, (char *)0, (char *)0, _WRITE, 1},
    {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2}
};

FILE *fopen(const char *name, const char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
        return NULL;
    }

    for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
        if (fp->flag.is_read == 0 && fp->flag.is_write == 0) {
            break;             /* found free slots */
        }
    }

    if (fp == _iob + OPEN_MAX)
        return NULL;           /* no free slots    */

    if (*mode == 'w') {
        fd = creat(name, PERMS);
    }
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1) {
            fd = creat(name, PERMS);
            lseek(fd, 0L, SEEK_END);
        }
    }
    else {
        fd = open(name, O_RDONLY, 0);
    }

    if (fd == -1) {
        return NULL;    /* couldn't access name */
    }

    fp->fd            = fd;
    fp->cnt           = 0;
    fp->base          = NULL;
    fp->flag.is_unbuf = 0;
    fp->flag.is_buf   = 1;
    fp->flag.is_err   = 0;

    if (*mode == 'r') { /* read mode */
        fp->flag.is_read  = 1;
        fp->flag.is_write = 0;
    }
    else  { /* write mode */
        fp->flag.is_read  = 0;
        fp->flag.is_write = 1;
    }

    return fp;
}

int _fillbuf(FILE *fp)
{
    int bufsize;

    if (fp->flag.is_read == 0 ||
         fp->flag.is_eof == 1 ||
         fp->flag.is_err == 1) 
    {
        return EOF;
    }

    bufsize = (fp->flag.is_unbuf == 1) ? 1 : BUFSIZ;

    if (fp->base == NULL) {  /* no buffer yet */
        if ((fp->base = malloc(busize)) == NULL) 
            return EOF;
    }
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);

    if (--fp->cnt < 0) {
        if (fp->cnt == -1) {
            fp->flag.is_eof = 1;
        }
        else {
            fp->flag.is_err = 1;
        }

        fp->cnt = 0;
        return EOF;
    }

    return (unsigned char) *fp->ptr++;
}

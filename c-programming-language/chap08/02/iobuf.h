#ifndef IOBUF_H

#define IOBUF_H

#define NULL     0
#define EOF      (-1)
#define BUFSIZ   1024
#define OPEN_MAX 20

struct flag_field {
    unsigned is_read   : 1;
    unsigned is_write  : 1;
    unsigned is_unbuf  : 1;
    unsigned is_buf    : 1;
    unsigned is_eof    : 1;
    unsigned is_err    : 1;
};

typedef struct _iobuf {
    int   cnt;    /* remaining chars     */
    char *ptr;    /* points to next char */
    char *base;   /* points to buffer    */
    struct flag_field   flag;   /* file access mode    */
    int   fd;     /* file decriptor      */
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])

enum _flags {
    _READ  = 01,  /* read only     */
    _WRITE = 02,  /* write only    */
    _UNBUF = 04,  /* non-buffer    */
    _EOF   = 010, /* end of file   */
    _ERR   = 020  /* error in file */
};

int _fillbuf(FILE *fp);
int _flushbuf(int, FILE *);

#define feof(p) \
    (((p)->flag & _EOF) != 0)

#define ferror(p) \
    (((p)->flag & _ERR) != 0)

#define fileno(p) \
    ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 \
     ? (unsigned char) *(p)->ptr++ : _fillbuf(p))

#define putc(x, p) (--(p)->cnt >= 0 \
        ? *(p)->ptr++ = (x) : _flushbuf((x), p))

#define getchar()   getc(stdin)
#define putchar(x)  putc((x), stdout)


#endif /* end of include guard: IOBUF_H */

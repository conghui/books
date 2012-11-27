#include <sys/stat.h>

void dirwalk(const char *dir, void (*fcn)(char *));

void fsize(const char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%5u %6o %3u %8ld %s\n", stbuf.st_ino,
            stbuf.st_mode, stbuf.st_nlink, stbuf.st_size, name);
}

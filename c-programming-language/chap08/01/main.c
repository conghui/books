#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void error(const char *fmt, ...);
void filecopy(int ifd, int ofd);

int main(int argc, const char *argv[])
{
    int fd;

    if (argc == 1) {
        filecopy(STDIN_FILENO, STDOUT_FILENO);
    }
    else {
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY)) == -1) {
                error("cat: cannot open %s");
            }
            else {
                filecopy(fd, STDOUT_FILENO);
                close(fd);
            }
        }
    }
    return 0;
}

void filecopy(int ifd, int ofd)
{
    ssize_t nread;
    char buf[BUFSIZ];

    while ((nread = read(ifd, buf, BUFSIZ)) > 0) {
        if (write(ofd, buf, nread) != nread) {
            error("cat: write error");
        }
    }
}

static void error(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
    va_end(ap);
}

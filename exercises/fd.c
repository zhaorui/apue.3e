#include "apue.h"
#include <fcntl.h>

const char *path="/etc/passwd";
int oflags = O_RDONLY;

int main(int argc, char **argv)
{
    int fd1, fd2, fd3;
    fd1 = open(path, oflags);
    fd2 = dup(fd1);
    fd3 = open(path, oflags);
    fcntl(fd1, F_SETFD, 1);
    printf("fd1 fd2 fd3: %i %i %i\n", fd1, fd2, fd3);

    int f1, f2, f3;
    f1 = fcntl(fd1, F_GETFD, 0);
    f2 = fcntl(fd2, F_GETFD, 0);
    f3 = fcntl(fd3, F_GETFD, 0);
    printf("FD flag  f1 f2 f3: %i %i %i\n", f1, f2, f3);

    set_fl(fd1, O_APPEND);
    f1 = fcntl(fd1, F_GETFL, 0);
    f2 = fcntl(fd2, F_GETFL, 0);
    f3 = fcntl(fd3, F_GETFL, 0);
    printf("FS flag  f1 f2 f3: %i %i %i\n", f1, f2, f3);
    get_fl(fd1);
    get_fl(fd2);
    get_fl(fd3);
    return 0;
}

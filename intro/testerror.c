#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
        int err_num = atoi(argv[1]);
	fprintf(stderr, "%s\n", strerror(err_num));
	errno = err_num;
	perror(argv[0]);
	exit(0);
}

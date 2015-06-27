#include "apue.h"

int main (int argc, char **argv)
{
    long num = open_max();
    printf("%ld\n", num);
}

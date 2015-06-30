#include <stdio.h>

int main(int argc, char** argv)
{
    FILE *fp = fopen("bigfile", "w+");
    char ch = 'a';
    int i = 0;

    for (; i < 600000; ch++, i++){
        fputc(ch, fp);
        if (ch == 'z')
            ch = 'a';
    }
    return 0;
}

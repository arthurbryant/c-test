#include "a.c"
#include <stdio.h>

int main()
{
    char *p = "1234567890";
    char *r;
    int *q;
    q = (int*)p;
    ++q;
    r = q;
    printf("%s\n", r);

    return 0;
}

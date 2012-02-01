#include <stdlib.h>
#include <stdio.h>

void err_sys(const char *str)
{
    printf("%s\n", str);
    exit(-1);
}

#include <stdio.h>
#include <time.h>
#include "apue.h"

int main()
{
    double d = 100.1234;
    int max = 2;
    printf("%10.*f\n", max, d);
    //printf("%d\n", i);
    int ret;
    if(printf("%dqde%112\n") == -1)
        err_sys("printf error");
    printf("%s\n", "abcd%%%d%q123");

    return 0;
}

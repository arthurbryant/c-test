#include <stdio.h>
#include <stdlib.h>
#include "apue.h"

static void charattime(char *str)
{
    char *ptr;
    int c;
    setbuf(stdout, NULL);
    ptr = str;
    while((c = *ptr++) != 0)
        putc(c, stdout);
}

int main()
{
    pid_t pid;
    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)
        charattime("child output\n");
    else
        charattime("parent output\n");

    return 0;
}

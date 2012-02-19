#include <stdio.h>
#include <stdlib.h>
#include "apue.h"

int main()
{
    pid_t pid;
    printf("parent group id: %d\n", getpgrp());
    printf("parent id: %d\n", getpid());
    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)
    {
        printf("child group id: %d\n", getpgrp());
    }

    return 0;
}

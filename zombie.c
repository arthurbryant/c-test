#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "apue.h"

static pid_t p;

int main()
{
    pid_t pid;
    pid_t pid2;

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)
    {
        if((pid2 = fork()) < 0)
            err_sys("fork error two");
        else if(pid2 == 0)
        {
            sleep(2);
            p = getpid();
            printf("zombie child id is %d\n", p);
        }
        else
        {
            printf("parent id is %d\n", getpid());
        }
    }
    else
    {
        system("ps -s");
    }
    
    return 0;
}

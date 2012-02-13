#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "apue.h"

int main()
{
    pid_t pid;

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)
    {
        if((pid = fork()) < 0)
            err_sys("child fork error");
        else if(pid == 0)
        {
            sleep(5);
            exit(2);
        }
        _exit(0);
    }
    system("ps");
    
    return 0;
}

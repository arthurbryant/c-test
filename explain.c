#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "apue.h"

int main()
{
    pid_t pid;

    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid == 0)
    {
        if(execl("/root/workspace/c-test/testinterp", "testinterp", "argv1", "argv2", (char *)0) < 0)
        {
            err_sys("execl error");
        }

    }
    if(waitpid(pid, NULL, 0) < 0)
    {
        err_sys("wait error");
    }

    return 0;
}

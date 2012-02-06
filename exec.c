#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    char *env_list[] = {"USER=test", "PATH=/home/test", NULL};
    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)
    {
        if(execle("/root/workspace/c-test/echoargv", "r", "arg1", "arg2", (char *)0, env_list) < 0)
            err_sys("execle error");
    }
    if(waitpid(pid, NULL, 0) < 0)
        err_sys("waitpid error");
    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)
    {
        if(execlp("/root/workspace/c-test/echoargv", "pth", "arg1", (char *)0) < 0)
            err_sys("execlp error");
    }

    printf("end of parent\n");

    return 0;
}

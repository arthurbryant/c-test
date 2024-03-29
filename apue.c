#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void err_sys(const char *str)
{
    printf("%s\n", str);
    exit(-1);
}
void pr_exit(int status)
{
    if(WIFEXITED(status))
    {
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    }
    else if(WIFSIGNALED(status))
    {
        printf("abnormal termination, signal number=%d %s\n", WTERMSIG(status), 
        #ifdef WCOREDUMP
                WCOREDUMP(status) ? "generate core file" : "");
        #else
                "");
        #endif
    }
    else if(WIFSTOPPED(status))
    {
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
    }
}

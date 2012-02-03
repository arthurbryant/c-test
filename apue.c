#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void err_sys(const char *str)
{
    printf("%s\n", str);
    exit(-1);
}
void pr_extit(int status)
{
    if(WIFEXITED(status))
    {
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    }
}

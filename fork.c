#include<sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int global = 1;

int main()
{
    pid_t pid;
    int var = 10;

    /*此时仅有一个进程*/
    printf("before fork\n");
    if((pid = vfork()) < 0)
    {
        printf("fork error\n");
        return -1;
    }
    /*此时已经有两个进程在同时运行*/
    if(pid==0)
    {
        ++var;
        ++global;
        fclose(stdout);    
        exit(0);
    }

    printf("pid=%d, global=%d, val=%d\n", getpid(), global, var);

    return 0;
}

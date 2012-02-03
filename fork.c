#include<sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int global = 1;

int main()
{
    pid_t pid;
    int var = 10;

    /*��ʱ����һ������*/
    printf("before fork\n");
    if((pid = vfork()) < 0)
    {
        printf("fork error\n");
        return -1;
    }
    /*��ʱ�Ѿ�������������ͬʱ����*/
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

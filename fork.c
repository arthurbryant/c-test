/* fork_test.c */
#include<sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;

    /*��ʱ����һ������*/
    pid=fork();
    /*��ʱ�Ѿ�������������ͬʱ����*/
    if(pid<0)
        printf("error in fork!");
    else if(pid==0)
        printf("I am the child process, my process ID is %d\n",getpid());
    else
        printf("I am the parent process, my process ID is %d\n",getpid());

    return 0;
}

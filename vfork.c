#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fork_test()
{
    pid_t pid;
    if((pid = vfork()) < 0)
    {
        printf("vfork error\n");
        return;
    }
    if(pid == 0)
    {
        printf("vfork child in fork_test\n");
    }
    else
    {
        printf("vfork parent in fork_test\n");
    }
}
void f2()
{
    char buf[1000];
    int i;
    for(i = 0; i < sizeof(buf); ++i)
    {
        buf[i] = 0;
    }
}
int main()
{
    int result;
    printf("before fork_test\n");
    fork_test(); 
    f2();
    printf("after fork_test\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    system("pwd");
    printf("errno=%d\n", errno);
    if(chroot("/home/") < 0)
    {
        printf("errno=%d\n", errno);
        printf("change root error\n");
        return -1;
    }
    else
    {
        system("pwd");
    }

    return 0;
}

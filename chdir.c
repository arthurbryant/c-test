#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char * argv[])
{
    int count = 230;
    char name[] = "abcdefghijklmnopqrstuvwxyz";
    //long len = (count * strlen(name)) + 1000;
    //long len = 100;
    //printf("len = %d\n", len);
    long len = 1000 + count * 26;
    char buf[len];
    printf("PATH_MAX=%d\n", PATH_MAX);
    int i;
    for(i = 0; i < count; ++i)
    {
        if(mkdir(name, 0x777) < 0)
        {
            printf("create %s error\n", name);
            return -1;
        }
        
        if(chdir(name) < 0)
        {
            printf("change dir to %s error\n", name);
            return -1;
        }
    if(getcwd(buf, len) < 0)
    {
        printf("errno=%d\n", errno);
        if(errno == ERANGE)
        {
            perror("not enough space for store path");
        }
        printf("getcwd error\n");
        return -1;
    }
    printf("%s\n%d\n", buf, strlen(buf));
    }
    printf("success\n");

    return 0;
}

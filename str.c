#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
    /*
    char str[PATH_MAX-24];
    char buf[PATH_MAX];
    int i;
    for(i = 0; i < PATH_MAX-24; ++i)
        str[i] = 'a';
    //str[PATH_MAX-24-1] = '\0';
    if(mkdir(str, 0x770) < 0)
    {
        printf("mkdir error\n");
        return -1;
    }
    if(getcwd(buf, PATH_MAX) < 0)
    {
        printf("getcwd error\n");
        return -1;
    }
    printf("%s\n", buf);
    */
    char str3[] = "abcd";
    printf("len=%d, %s\n", sizeof(str3), str3);

    return 0;
}

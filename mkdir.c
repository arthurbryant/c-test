#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int j = 254;
    char name[257];
    int count = 256;
    for(j = 0; j < 254; ++j)
    {
        name[j] = 'b';
    }
    for(j = 254; j <= count; ++j)
    {
        name[j] = 'b';
        name[j+1] = '\0';
        printf("%d\n", j+1);
        if(mkdir(name, 0x777) < 0)
        {
            printf("mkdir error\n");
            return -1;
        }
        printf("create success\n");
    }

    return 0;
}

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void copy(char *file1, char *file2)
{
    int fd1, fd2;
    if((fd1 = open(file1, O_RDONLY)) < 0)
    {
        printf("open %s error\n", file1);
    }
    if((fd2 = open(file2, O_RDWR)) < 0)
    {
        printf("open %s error\n", file2);
    }
    char c;
    while(read(fd1, &c, 1) == 1)
    {
        if(c == '\0')
            continue;
        if(write(fd2, &c, 1) != 1)
        {
            printf("write error\n");
            return;
        }
    }
    close(fd1);
    close(fd2);
}
int main()
{
    copy("test", "test.copy");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int fd;
    if((fd = open("test", O_RDWR)) < 0)
    {
        printf("open error\n");
        return -1;
    }
    char buf[] = "test hole";
    if(write(fd, buf, sizeof(buf)) != sizeof(buf))
    {
        printf("write error\n");
        return -1;
    }
    if(lseek(fd, 1024, SEEK_SET) == -1)
    {
        printf("seek error\n");
        return -1;
    }
    if(write(fd, buf, sizeof(buf)) != sizeof(buf))
    {
        printf("write error\n");
        return -1;
    }
    close(fd);

    return 0;
}

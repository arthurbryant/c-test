#include <stdio.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
    int fd;
    
    if((fd = open("aa", O_RDWR)) < 0)
    {
	printf("open error\n");
	return -1;
    }
    char buf[] = "new content\n";
    char buf1[] = "hello, world\n";
    char buf2[20];
    int count;
    if(write(fd, buf, sizeof(buf)) != sizeof(buf))
    {
	printf("write error\n");
    }
    if(lseek(fd, 0, SEEK_SET) == -1)
    {
	printf("seek error\n");
    }
    if(read(fd, buf2, sizeof(buf2)) < 0)
    {
	printf("read error\n");
    }
    printf("%s\n", buf2);
    if(lseek(fd, 1024, SEEK_SET) == -1)
    {
	printf("seek error\n");
    }
    if(write(fd, buf1, sizeof(buf1)) != sizeof(buf1))
    {
	printf("write error\n");
    }

    return 0;
}

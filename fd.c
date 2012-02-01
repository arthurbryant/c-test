#include <stdio.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
    int fd, fd1, fd2;
    if((fd = open("aa", O_RDONLY) < 0))
    {
	printf("open file error");
	return -1;
    }
    fd2 = dup(fd);
    if((fd1 = open("a.c", O_RDWR) < 0))
    {
	printf("open file error");
	return -1;
    }
    printf("%d\n", fd);
    printf("%d\n", fd1);
    printf("%d\n", fd2);
    getchar();

    return 0;
}

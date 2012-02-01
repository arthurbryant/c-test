#include <stdio.h>
#include <fcntl.h>

void print_file_flag(int fd)
{
    int val;
    if((val = fcntl(fd, F_GETFL, 0)) < 0)
    {
	printf("get file flag error\n");
	return;
    }
    printf("%d\n", val);
    switch(val & O_ACCMODE)
    {
	case O_RDONLY:
	    printf("read only");
	    break;
	case O_WRONLY:
	    printf("write only");
	    break;
	case O_RDWR:
	    printf("read write");
	    break;
	default:
	    printf("unknow access mode");
	    break;
    }
    if(val & O_APPEND)
    {
	printf(", append");
    }
    if(val & O_NONBLOCK)
    {
	printf(", nonblocking");
    }
#if defined(O_SYNC)
    if(val & O_SYNC)
    {
	printf(", synchronous writes");
    }

#endif
# if !defined(_POSIX_C_SOURCE) && O_FSYNC
    if(val & O_FSYNC)
    {
	printf(", synchronous writes");
    }
#endif
    printf("\n");
}

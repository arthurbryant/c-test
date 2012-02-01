#include <stdio.h>
#include <utime.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
    int i;
    struct stat statbuf;
    struct utimbuf timebuf;
    for(i = 1; i < argc; ++i)
    {
    	if(stat(argv[i], &statbuf) < 0)
	{
	    printf("stat error\n");
	    return -1;
	}
	int fd;
	if((fd = open(argv[1], O_RDWR | O_TRUNC)) < 0)
	{
	    printf("open error\n");
	    continue;
	}
	close(fd);
	timebuf.actime = statbuf.st_atime;
	timebuf.modtime = statbuf.st_mtime;
	if(utime(argv[1], &timebuf) < 0)
	{
	    printf("utime error\n");
	    continue;
	}
    }
    

    return 0;
}

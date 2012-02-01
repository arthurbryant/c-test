#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char * argv[])
{
    struct stat statinfo;
    if(stat("a.c", &statinfo) < 0)
    {
	printf("stat error\n");
	return -1;
    }
    printf("nlink=%d, gid=%d, uid=%d\n", statinfo.st_nlink, statinfo.st_gid, statinfo.st_uid);
    int i;
    char *ptr;
    for(i = 1; i < argc; ++i)
    {
	printf("%s: ", argv[i]);
	if(lstat(argv[i], &statinfo) < 0)
	{
		printf("lstat error\n");
		continue;
	}
	if(S_ISREG(statinfo.st_mode))
	    ptr = "reg";
	else if(S_ISDIR(statinfo.st_mode))
	    ptr = "dir";
	else if(S_ISCHR(statinfo.st_mode))
	    ptr = "char";
	else if(S_ISBLK(statinfo.st_mode))
	    ptr = "block";
	else if(S_ISLNK(statinfo.st_mode))
	    ptr = "link";
	else if(S_ISFIFO(statinfo.st_mode))
	    ptr = "fifo";
	else if(S_ISSOCK(statinfo.st_mode))
	    ptr = "socket";
	else
	    ptr = "*** unknown mode ***";
    }
    printf("%s file\n", ptr);

    return 0;
}

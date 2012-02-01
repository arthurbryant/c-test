#include <stdio.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
    int fd;

    char filename[] = "a.c";
    if((fd = open(filename, O_CREAT | O_EXCL)) < 0)
    {
	printf("Can not create %s\n", filename);
    }
    

    return 0;
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX 512

int main(int argc, char * argv[])
{
    if(symlink("a.c", "a.c.link") < 0)
    {
	printf("create sys link error\n");
	return -1;
    }
    char buf[MAX];
    if(readlink("a.c.link", buf, MAX) < 0)
    {
	printf("read link error\n");
	return -1;
    }
    printf("%s\n", buf);

    return 0;
}

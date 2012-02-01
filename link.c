#include <stdio.h>

int main(int argc, char * argv[])
{
    int flag;
    if(link("/home/arthur/undo", "/home/arthur/workspace/c-test/und") == -1)
    {
	printf("link error\n");
	return -1;
    }
    if(unlink("/home/arthur/workspace/c-test/un") == -1)
    {
	printf("unlink error\n");
	return -1;
    }

    return 0;
}

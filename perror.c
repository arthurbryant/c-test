#include <stdio.h>

int main(int argc, char * argv[])
{
	int i = 0;
	if(5/0)
		perror(argv[0]);
	//printf("success\n");

    return 0;
}

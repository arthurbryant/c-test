#include <stdio.h>

int main(int argc, char * argv[])
{
    system("pwd");
    if(chdir("/tmp") < 0)
    {
	printf("change dir error\n");
	return -1;
    }
    system("pwd");
    printf("change dir to /tmp\n");

    return 0;
}

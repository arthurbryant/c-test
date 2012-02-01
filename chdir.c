#include <stdio.h>
#include <limits.h>

int main(int argc, char * argv[])
{
    system("pwd");
    if(chdir("/home/arthur") < 0)
    {
	printf("change dir error\n");
	return -1;
    }
    system("pwd");
    printf("change dir to /home/arthur\n");
    
    char buf[PATH_MAX];
    getcwd(buf, PATH_MAX);
    printf("cwd=%s\n", buf);

    return 0;
}

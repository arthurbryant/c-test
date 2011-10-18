#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("call execl");
    sleep(1);
    execl("/bin/echo", " ", NULL); 
    printf("error!\n");
    return 0;
}

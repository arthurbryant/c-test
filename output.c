#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("call execl"); 
    sleep(1); 
    execl("/bin/ls", "ls", "-a", NULL); 
    printf("error!\n");

    return 0;
}

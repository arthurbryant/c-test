#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 4096

int main()
{
    char buffer[MAX];
    int n;
    while((n = read(STDIN_FILENO, buffer, MAX)) > 0)
    {
        if(write(STDOUT_FILENO, buffer, n) != n)
        {
            perror("write error");
            exit(-1);
        }
    }
    if(n < 0)
    {
        perror("read error");
        exit(-1);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main()
{
    char line[MAX];
    int fd;
    if(fgets(line, MAX, stdin) == NULL)
    {
        perror("fgets error");
        exit(-1);
    }
    fd = mkstemp(line);

    return 0;
}

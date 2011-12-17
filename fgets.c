#include <stdio.h>

#define MAXLINE 4

int main(int argc, char * argv[])
{
    char buf[MAXLINE];
    FILE *fp = fopen("data", "r");

    while(fgets(buf, MAXLINE, fp) != NULL)
    {
        if(fputs(buf, stdout) ==  EOF)
            perror("fputs error");
        fflush(NULL);
        sleep(1);
    }

    return 0;
}

#include <stdio.h>
#include <time.h>

#define MAXLINE 200

int main(int argc, char * argv[])
{
    char buf[MAXLINE];
    /*
    FILE * fp = freopen("data", "a+", stdout);
    printf("so you can add here\n");
    fclose(fp);
    */
    FILE *f = fopen("data", "r+");
    while(fgets(buf, MAXLINE, f) != NULL)
        if(fputs(buf, stdout) == EOF)
            perror("output error");

    return 0;
}

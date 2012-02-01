#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int main()
{
    char fname[MAXLINE];
    char line[MAXLINE];
    printf("%s\n", tmpnam(NULL));
    tmpnam(fname);
    printf("%s\n", fname);
    FILE * fp; 
    if((fp = tmpfile()) == NULL)
    {
        perror("create temp file error");
        exit(-1);
    }
    fputs("what a great day!\n", fp);
    rewind(fp);
    if(fgets(line, MAXLINE, fp) == NULL)
    {
        perror("read file error");
        exit(-1);
    }
    fputs(line, stdout);

    return 0;
}

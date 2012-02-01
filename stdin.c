#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    /*
    char *filename = "data";
    FILE * f = freopen(filename, "r", stdin);
    if(NULL == f)
    {
        perror("");
    }
    char c;
    while(scanf("%c", &c) != EOF)
        printf("%c", c);
   fclose(f); 
    */
    int res;
    if((res = lseek(STDIN_FILENO, 10, SEEK_SET)) == -1)
    {
        err_sys("lseek stdin error");
    }
    else
    {
        printf("success\n");
    }


    return 0;
}

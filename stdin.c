#include <stdio.h>

int main(int argc, char * argv[])
{
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

    return 0;
}

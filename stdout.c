#include <stdio.h>

int main(int argc, char * argv[])
{
    char * filename = "output";
    FILE * f = freopen(filename, "w", stdout);
    if(NULL == f)
        perror("not exist\n");
    char * str = "very good";
    printf("%s\n", str);
    fclose(f);

    return 0;
}

#include <stdio.h>

int main(int argc, char * argv[])
{
    int i;
    i = printf("");
    printf("%d\n", i);   
    i = printf("abc\n");
    printf("%d\n", i);   
    i = printf(NULL);
    return 0;
}

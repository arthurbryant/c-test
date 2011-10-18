#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char *p = "abcd";
    int a = 12;
    int * i = &a;

    size_t len = strlen(p);
    printf("%d\n", sizeof(p));
    //printf("%d\n", len);
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(int));
    printf("%d\n", 1<<31);
    int m, n = 1;
    for(m = 0; m < 31; ++m)
        n *= 2;
    printf("%d\n", n-1);

    return 0;
}

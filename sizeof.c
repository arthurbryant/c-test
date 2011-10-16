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

    return 0;
}

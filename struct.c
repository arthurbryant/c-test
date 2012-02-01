#include <stdio.h>

struct test
{
    long a:4;
    int b;
    char c;
};
int main(int argc, char * argv[])
{
    printf("%d\n", sizeof(struct test));
    

    return 0;
}

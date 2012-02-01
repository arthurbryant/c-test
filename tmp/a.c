#include <stdio.h>
#include <limits.h>

int main()
{
    int a = 12;
    int b = (a & 0x7) << 5;
    a << 1;

    printf("%d\n", b);
    printf("%d\n", a);
    return 1;
}

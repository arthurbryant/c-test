#include <stdio.h>

int main()
{
    unsigned char c = 0;
    while(c < 256)
    {
        printf("%d\t", c++);
    }

    return 0;
}

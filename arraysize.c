#include <stdio.h>
#include <stdlib.h>

void f(int ch[256])
{
    if(NULL == ch)
        return;
    memset(ch, 0, sizeof(int)*256);
    int i;
    for(i = 0; i < 256; ++i)
        printf("%d\t", ch[i]);
}
int main(int argc, char * argv[])
{
    int arr[256];
    f(arr);

    return 0;
}

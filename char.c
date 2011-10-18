#include <stdio.h>
#include <stdlib.h>

void findAToZ(char c[], int arr[256])
{
    if(c == NULL || arr == NULL)
        return;
    int i = 0;
    memset(arr, 0, sizeof(int)*256);
    while(*c != '\0')
    {
        printf("%c\n", *c);
        ++arr[*c++];
    }
    for(i = 0; i < 256; ++i)
        printf("%d\t", arr[i]);
}

int main()
{
    char *c = "百度abc";
    int arr[256];
    findAToZ(c, arr);

    return 0;
}

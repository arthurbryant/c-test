#include <stdio.h>
#include <string.h>

int strlcpy(char *dst, const char *src, size_t n)
{
    if(dst == NULL || src == NULL)
        return -1;
    char *d = dst;
    const char *s = src;
    if(n > 0)
    {
        while(--n != 0)
        {
            if((*d++ = *s++) == '\0')
                break;
        }
    }
    if(n == 0)
    {
        *d = '\0';
        while(*s++);
    }
    return s-src-1;
}
int main(int argc, char * argv[])
{
    char a[5];
    int len = sizeof(a)/sizeof(char);
    //strlcpy(a, "abcdef", len);
    //strcpy(a, "hello, world");
    int count;
    count = strlcpy(a, "hello, world", 5);
    printf("%s %d\n", a, count);

    return 0;
}

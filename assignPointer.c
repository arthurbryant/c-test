#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char * str = "abc";
    char * tmp = NULL;
    memmove(tmp, str, strlen(str)+1);
    printf("%c\n", *tmp);

    return 0;
}

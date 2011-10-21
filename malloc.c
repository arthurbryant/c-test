#include <stdio.h>
#include <stdlib.h>

char * returnLocal(char *s)
{
    s = malloc(sizeof(char)*4);
    s = "abc";

    return s;
}
/*
char * f()
{
    char *l = returnLocal();

    return l;
}
*/
int main(int argc, char * argv[])
{
    char *s;
    s = returnLocal(s);
    if(s != NULL)
        printf("not null\n");
    printf("%s\n", s);
    /*
    s = "abcd";
    printf("%s\n", s);
    s = "abcdef";
    printf("%s\n", s);
    char *s1 = NULL;
    s1 = f();
    //s1 = "abc";
    printf("%s\n", s1);
    if(s1 != NULL)
        printf("not null\n");
    */
    return 0;
}

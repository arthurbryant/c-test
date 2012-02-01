#include <stdio.h>

#define doit(name) print_r(#name, name)
#define MAX 100

void print_r(char *, int);

int main()
{
    doit(MAX);

    return 0;
}
void print_r(char *str, int s)
{
    printf("%s=%d\n", str, s);
}

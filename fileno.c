#include <stdio.h>

int main()
{
    int num;
    FILE * fp;

    num = fileno(stdin);
    printf("%d\n", num);
    num = fileno(stdout);
    printf("%d\n", num);
    num = fileno(stderr);
    printf("%d\n", num);
    fp = fopen("a.c", "r");
    printf("%d\n", fp);

    return 0;
}

#include <stdio.h>

#define MAXSIZE 200

int main()
{
    char input[MAXSIZE];
    fgets(input, MAXSIZE, stdin);
    puts(input);
    gets(input);
    puts(input);

    return 0;
}

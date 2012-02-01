#include <stdio.h>
#include <stdlib.h>

static void f();

int main(int argc, char* argv[])
{
    char buffer[10];
    itoa(argc, buffer, 10);
    setenv("argc", buffer, 0);
    f();
    return 0;
}

static void f()
{
    char *ch;
    ch = getenv("argc");
    printf("%s\n", ch);
}

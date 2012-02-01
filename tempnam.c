#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        printf("Usage: a.out <dir> <prefix>\n");
        exit(-1);
    }
    printf("%s\n", tempnam(argv[1][0] != ' ' ? argv[1] : NULL, argv[2][0] != ' ' ? argv[2] : NULL));

    return 0;
}

#include <stdio.h>

int main()
{
    printf("start here\n"); 
    gotohere:
    printf("goto start\n");
    if(getchar() == 'a')
        goto gotohere;
    else
        printf("done\n");

    return 0;
}

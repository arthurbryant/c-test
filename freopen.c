#include <stdio.h>

int main(int argc, char * argv[])
{
    FILE *fp = freopen("data", "r", stdin);
    
    char str[100];
    while(scanf("%s", str) != EOF)
        printf("%s\n", str);        
    

    return 0;
}

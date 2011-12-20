#include <stdio.h>
#include <time.h>

int main()
{
    int len, len2;
    int i;
    printf("arthur\n%n", &len);
    printf("%d\n", len);
    scanf("%d%n", &i, &len2);
    printf("%d, %d\n", i, len2);

    return 0;
}

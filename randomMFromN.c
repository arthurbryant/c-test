#include <stdio.h>
#include <assert.h>
#include <time.h>

void randomMFromN(int n, int m)
{
    assert((m > 0) && (n > 0));

    int i; 
    srand(time(NULL));
    for(i = 0; i < n; ++i)
    {
        if((rand() % (n-i)) < m)
        {
            printf("%d\t", i);
            --m;
        }
    }
    printf("\n");
}
int main(int argc, char * argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    randomMFromN(n, m);

    return 0;
}

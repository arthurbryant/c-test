#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[])
{
    time_t t;
    t = time(NULL);
    long int t1 = 0x7fffffff;
    long int duration = t1-t;
    int year = duration / (2400*24*365);
    int furture = year + 2011;
    printf("%d\n", sizeof(size_t));
    printf("%ld\n", t1);
    printf("furturn = %d\n", furture);

    return 0;
}

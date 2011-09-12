#include <stdio.h>

#define ISUNSIGNED(a) ((a >= 0) && ((~a) >= 0))
#define ISUN(type) ((type)0 - 1 > 0)

int main(int argc, char * argv[])
{
	unsigned int i = 9;
	unsigned int a = 0;
	int j = -9;
	int k = 9;
	
	printf("%d, %d, %d, %d\n", ISUNSIGNED(i), ISUNSIGNED(a), ISUNSIGNED(j), ISUNSIGNED(k));
	printf("%d, %d, %d, %d\n", ISUN(unsigned long), ISUN(unsigned int), ISUN(short), ISUN(int));
	unsigned int m = (unsigned int )0 - 1 ;
	printf("%u\n", m);

    return 0;
}

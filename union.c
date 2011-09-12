#include <stdio.h>

union
{
	char a[14];
	int i;
}u;

int main()
{
	int *p = (int *)&(u.a[1]);
	*p = 17;
	printf("%d\n", *p);
   	printf("%d\n", sizeof(u));

    return 0;
}

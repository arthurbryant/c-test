#include <stdio.h>

void fun(int a[])
{
	printf("\n%d\n", sizeof(a));
	printf("\n%d\n", sizeof(a[0]));
	printf("%x\n", &a);
	printf("%x\n", a);
	printf("%x\n", &a[0]);
	printf("%x\n", &a[1]);
}
void g(int *a)
{
	printf("%x\n", &a);
	printf("%x\n", a);
	printf("%x\n", &a[0]);
	printf("%x\n", &a[1]);
	printf("%x\n", ++a);
}

int main()
{
	int a[10] = {0};
	fun(a);
	printf("\n");
	g(a);
	printf("\n%x\n", &a);
	printf("\n%d\n", sizeof(a));
	printf("\n%d\n", sizeof(a[0]));
	printf("%x\n", a);
	printf("%x\n", &a[0]);
	printf("%x\n", &a[1]);
	printf("%x\n", a+1);
    return 0;
}

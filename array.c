#include <stdio.h>


int main()
{
	int ap[2][3][5];
	int (*r)[5] = ap[0];
	int (*t) = ap[0][0];

	int a[2];
	int p;
	printf("%x\n", &a[1]);
	printf("%x\n", &p);
	printf("%d\n", sizeof(ap));
	printf("%d\n", sizeof(ap[0]));

	printf("%x\n", r);
	printf("%x\n", ++r);

	printf("%x\n", t);
	printf("%x\n", ++t);

    return 0;
}

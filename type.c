#include <stdio.h>

union
{
	double d;
	float f;
}u;

int main()
{
	u.f = 10.0;
	printf("%f\n", u.d);

	u.d = 10.0;
	printf("%f\n", u.f);


    return 0;
}

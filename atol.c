#include <stdio.h>

long atol(char *str)
{
	char *p = str;
	long result = 0;
	int flag = 0;
	switch(*p)
	{
		case '-':
			 flag = 1;
			 /* No break here*/
		case '+':
			 ++p;
			 break;
	}
	while(*p >= '0' && *p <= '9')
	{
		int n;
		n = *p - '0';
		if(flag)
			n = -n;
		result = result * 10 + n;
		++p;
	}

	return result;
}
int main()
{
	char *str = "-+123";
	long l = atol(str);
	printf("%ld\n", l);

    return 0;
}

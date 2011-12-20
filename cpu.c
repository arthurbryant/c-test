#include <stdio.h>

int main()
{
	for(;;)
	{
		for(int i = 0; i < 96000000; ++i);
		sleep(10);
	}
	return 0;
}

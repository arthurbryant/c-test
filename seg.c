#include <stdio.h>
#include <signal.h>

void seg_and_bus_handler(int s)
{
	if(SIGSEGV == s)
	{
		printf("You access the wrong memory\n");
	}
	else if(SIGBUS == s)
	{
		printf("Bus access error\n");
	}
}
int main()
{
  	signal(SIGSEGV, seg_and_bus_handler); 
   	signal(SIGBUS, seg_and_bus_handler); 
	int *p = 0;
	*p = 4;

    return 0;
}

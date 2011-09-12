#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf buf;

void signal_handler(int s)
{
	if(SIGINT == s)
 		printf("Do not interrupt the program\n");
	longjmp(buf, 1);
}

/* Register signal handler */
void init()
{
	signal(SIGINT, signal_handler);
}
int main()
{
	init();
	if(setjmp(buf))
	{
		printf("back in main\n");
		return 0;
	}
	else
		printf("init\n");
	while(1);

    return 0;
}

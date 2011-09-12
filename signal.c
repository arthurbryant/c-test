#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf buf;

void signal_handler()
{
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
	setjmp(buf);
	printf("init\n");
	while(1);

    return 0;
}

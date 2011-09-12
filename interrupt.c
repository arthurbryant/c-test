#include <stdio.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stropts.h>

void signal_handler(int s)
{
	int c;
	c = getchar();
	printf("%c\n", c);
	if('q' == c)
	{
		system("stty sane");
		exit(0);
	}
}
int main()
{
   	sigset(SIGPOLL, signal_handler); 
	ioctl(0, I_SETSIG, S_RDNORM);
	system("stty raw -echo");
	while(1);

    return 0;
}

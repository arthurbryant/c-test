#include <stdio.h>
#include <setjmp.h>

jmp_buf buf; 

int main()
{
	setjmp(buf);	
	printf("init");

	char ch;
	while(ch = getchar())
	{
		if(ch == '@')
			longjmp(buf, 1);
		else
			printf("%c", ch);
	}

	return 0;
}

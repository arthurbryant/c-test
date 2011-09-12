#include <stdio.h>
#include <string.h>

#define BUFSIZE 4 

static char buf[BUFSIZE];
static char *bufptr = buf;

static void flushbuf()
{
	char *p = buf;
	while(p != bufptr)
	{
		putchar(*p++);
	}
	bufptr = buf;
	printf("\n");
}

void bufwrite(char *p, int n)
{
	while(--n >= 0)
	{
		if(bufptr >  &buf[BUFSIZE-1])
			flushbuf();
		*bufptr++ = *p++;
	}
}

int main()
{
	char * str = "abcdefghi";
   	bufwrite(str, strlen(str)); 
	flushbuf();

    return 0;
}

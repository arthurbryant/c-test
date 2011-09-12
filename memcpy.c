#include <stdio.h>
#include <string.h>

#define BUFSIZE 4 

static char buf[BUFSIZE];
static char *bufptr = buf;

static void memcp(char *src, char *dest, int n)
{
	while(--n >= 0)
		*dest++ = *src++;
}

static void flushbuf()
{
	int i = 0;
	char *p = buf;
	while(p != bufptr)
		putchar(*p++);
	printf("\n");
	bufptr = buf;
}
void bufwrite(char *p, int n)
{
	int k = 0;
	int rem = (buf + BUFSIZE) - bufptr;	
	while(n > 0)
	{
		if(bufptr == &buf[BUFSIZE])
			flushbuf();
		k = n > rem ? rem : n;	
		memcp(p, bufptr, k);
		p += k;
		bufptr += k;
		n -= k;
	}	
	flushbuf();
}
int main()
{
	char *str = "abcdefghijk";    
	int length = strlen(str);
	printf("%d\n", length);
	bufwrite(str, length);

    return 0;
}

#include <stdio.h>

#define PRINTLINE printf("\n")
#define PRINTPAGE printf("\n\n\n");

#define NROW 4
#define NCOLUMN 4
#define BUFSIZE ((NROW-1) * NCOLUMN)

static char buf[BUFSIZE];
static char *bufptr = buf;

static void printnum(int n)
{
	printf("%d\t", n);
}

void print(int n)
{
	static int row = 0;
	if(bufptr == &buf[BUFSIZE])	
	{
		char *p;
		for(p = buf + row; p < bufptr; p += NROW)
		{
			printnum(*p);
		}
		printnum(n);
		PRINTLINE;
		if(++row == NROW)
		{
			PRINTPAGE;
			row = 0;
			bufptr = buf;
		}
	}
	else
	{
		*bufptr++ = n;
	}
}

void flushbuf()
{
	int row = 0;
	char *p;
	while(row < NROW)
	{
		for(p = buf + row; p < bufptr; p += NROW)
		{
			printnum(*p);
		}
		PRINTLINE;
		++row;
	}
}
int main()
{
	int i = 0;
	while(i < 40)
	{
		print(i);
		++i;
	}
	flushbuf();

    return 0;
}

#include "header.h"

int get_token(char * substr)
{
	if(substr == NULL)
	{
		printf("substr is NULL\n");
		exit(-1);
	}
	int offset = 0;
	char *p = substr;
	int i = 0;
	int flag = 0;
	if(*p != '\0')
	{
		while(isdigit(*p) || isalpha(*p))
		{
			this.type = 'c';
			this.string[i++] = *p;
			++p;
			flag = 1;
		}
		if(flag == 1)
		{
			this.string[i] = '\0';
			stack[top_stack++] = this;
		}
		if(*p == '*' || *p == '(' || *p == ')' || *p == '[' || *p == ']')
		{
			this.type = *p;
			this.string[0] = '\0';
			stack[top_stack++] = this;
			++p;
		}
		offset = p - substr;
		return offset; 
	}
	else
	{
		printf("At the end of the string\n");
		return offset;
	}
}

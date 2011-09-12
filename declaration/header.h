#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAXTOKENLEN 32
#define MAXTOKENS 16

struct token
{
	char type;
	char string[MAXTOKENLEN];
};

static int top = 0;
struct token stack[MAXTOKENS];
struct token present;


char get_token(char * decl)
{
	if(decl == NULL)
	{
		printf("Error declaration\n");
		exit(-1);
	}
	char type;
	char * p = decl;
	char token[MAXTOKENLEN];
	struct token temp;
	int i  = 0;
	int isWord = 0;
	while(*p != '\0')
	{
		while(*p++ == ' ');
		while(isdigit(*p) || isalpha(*p))
		{
			token[i++] = *p;					
			isWord = 1;
		}
		if(isWord == 1)
		{
			type = classify_word(token);
			temp.type = type;
			temp.string = token;
			stack[top++] = temp;

			return type;
		}
		if(*p == '*' || *p == '(' || *p == ')' || *p == '[' || *p == ']')
		{
			type = *p;
			temp.type = type;
			temp.string = '\0';
			stack[top++] = token;
			++p;
			return type;
		}
	}
}
void read_to_first_identifier()
{
	char type = get_token();	

	if(type == 'i')
	{
		if(top >= 1)
		{
			printf("identifier is %s", stack[top-1].string );
			--top;
		}
		else
			printf("Stack overflow");
	}
	get_token();
}
void deal_with_declaration()
{

}
#endif

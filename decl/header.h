#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

#define MAXTOKENLEN 32
#define MAXTOKENS 32

struct token
{
	char type;
	char string[MAXTOKENLEN];
};
struct token this;
struct token stack[MAXTOKENS];

int top_stack = 0;

/* 
 * Get one token from the string and push it in the stack 
 * Return the length of the string
 */
int get_token(char * substr);

#endif

#include <stdio.h>

#include "header.h"

int main()
{
	//read_to_first_identifier()
	//deal_with_declaration()
	char * str = "char* const * (*next)()";
	get_token(str);

	return 0;
}

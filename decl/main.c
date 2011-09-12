#include "header.h"

int main()
{
	char *str = "char * const* (*next)()";
	int position = 0;
	position = get_token(str);
	printf("position = %d\n", position);

	return 0;
}

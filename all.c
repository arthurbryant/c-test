#include <stdio.h>

void
printAll (char *str)
{
	char *tmp = str;

	if (NULL == str)
	{
		perror ("str is null");
	}
	else
	{
		tmp = str;
		if (*str)
		{
			printf ("%c\t", *tmp);
			if (*++str)
			{
				printf ("%c", *tmp);
				printAll (str);
			}
		}
	}
}
int
main (int argc, char *argv[])
{
	char *str = "ab";

	printAll (str);

	return 0;
}

#include <stdio.h>

int main()
{
	FILE * fp = fopen("a.c", "r+");
	if(NULL == fp)
		perror("Error: cannot open file");
	char array[128];
	char *p = array;
	int count = 0;
	while((1 == fread(p, sizeof(char), 1, fp)) && (count < 128))
	{
		++p;
		++count;
		//fseek(fp, 0L, 1);
	}
	//printf("%d\n", count);
	int i = 0;
	for(i = 0; i < 128; ++i)
		printf("%c", array[i]);

    return 0;
}

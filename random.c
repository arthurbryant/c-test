#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	char str[256];
	char tmp[256];
	FILE *fp = fopen("a.c", "r");
	int rand_max = 0;
	int rand_tmp;
	if(NULL == fp)
		perror("Cannot open file a.c");
	else
	{
		fgets(str, 256, fp);
		++rand_max;
		while(!feof(fp))
		{
			fgets(tmp, 256, fp);
			++rand_max;
			srand(time(NULL));
			rand_tmp = rand() % rand_max + 1;
			if(rand_tmp == rand_max)
			{
				strcpy(str, tmp);
			}
		}
		puts(str);
		fclose(fp);
	}
    return 0;
}

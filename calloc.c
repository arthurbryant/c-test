#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int num = 3;
    long * arr;
    arr = (long*)calloc(num, sizeof(long));
    if(arr == NULL)
    {
	printf("heap overflow\n");
	exit(-1);
    }
    int i;
    for(i = 0; i < num; ++i)
    {
	printf("%ld\n", arr[i]);
    }
    char **ptr;
    ptr = (char**)calloc(num, sizeof(char *));
    for(i = 0; i < num; ++i)
    {
	if(ptr[i] != NULL)
	{
		printf("not null\n");
	}
    else
    {
        printf("null\n");
    }
    }

    return 0;
}

#include <stdio.h>
#include <limits.h>

int main()
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int i = 0;
	int y = 10;
	int j;
	array[i++] += y;
	int length = sizeof(array)/sizeof(int);
	i = length - 1;
	j = 0x01 << (i & 0x7);
	printf("%d\n", array[i >> 2]);
	//printf("%d\n", j);
	
	/*
	for(i = 0; i < length; ++i)
	    printf("%d\n", array[i]);    
*/
    return 1;
}

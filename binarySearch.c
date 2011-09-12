#include <stdio.h>

int * search(int array[], int length, int key)
{
	int mid = length / 2;
	int tmp = array[mid];
	if(tmp == key)
		return &array[mid];
	if(mid)
	{
		if(tmp > key)
			search(array, mid, key);
		else
			search(array + mid + 1, length - mid - 1, key);
	}
	else
		return NULL;
}
int main()
{
   	int array[] = {1, 2, 3, 4};
	int length = sizeof(array) / sizeof(int);
	printf("%d\n", length);
	int key;
	int *p; 
	while(1)
	{
		printf("Please input the number you want to search\n");
		scanf("%d", &key);
		p = search(array, length, key);
		if(NULL == p)
			printf("%d could not find\n\n", key);
		else
			printf("Found key at %d\n\n", p - array);
	}

    return 0;
}

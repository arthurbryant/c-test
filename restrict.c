#include <stdio.h>

void AddFunc(const int* __restrict ipValue, int* __restrict opArray, int len)
{
    int i; 
            for (i=0; i<len; i++)
                                opArray[i] += *ipValue;
}

int main( int argc, char *argv[] )
{
    int i; 
            int array[] = { 1, 2, 3};

                    AddFunc(&array[0], array, sizeof(array)/sizeof(int));

                            for (i=0; i<sizeof(array)/sizeof(int); i++)
                                                printf("array[%d] = %d\n", i, array[i]);

                                    return 0;
}

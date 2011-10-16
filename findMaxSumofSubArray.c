#include <stdio.h>
#include <assert.h>

int max(int x, int y)
{
    return x > y ? x : y;
}
int findMaxSumofSubArray(int arr[], int len)
{
    if(NULL == arr)
        return -1;
    int sum = arr[len-1];
    int start = arr[len-1];
    int i;
    for(i = len-2; i >= 0; --i)
    {
        start = max(arr[i], start+arr[i]);
        sum = max(start, sum);
    }
    return sum;
}

int main(int argc, char * argv[])
{
    int arr[] = {1, -2, 3, 5, -3, 2};
    int len = sizeof(arr) / sizeof(int);

    int arr1[] = {0, -2, 3, 5, -1, 2};
    int len1 = sizeof(arr1) / sizeof(int);

    int arr2[] = {-9, -2, -3, -4, -3};
    int len2 = sizeof(arr2) / sizeof(int);

    assert(findMaxSumofSubArray(arr, len) == 8);
    assert(findMaxSumofSubArray(arr1, len1) == 9);
    assert(findMaxSumofSubArray(arr2, len2) == -2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "link.h"

List insert(List l, int i)
{
    if(NULL == l)
    {
        l = (List)malloc(sizeof(struct node));
        l->data = i;
        l->next = NULL;
    }
    else
    {
	    List n = (List)malloc(sizeof(struct node));
    	n->data = i;
	    n->next = l->next;
        l->next = n;
    }
    return l;
}
List create_list(int arr[], int n)
{
    assert(arr != NULL && n > 0);
	int i;
    List l = (List)malloc(sizeof(struct node));
    l->data = 0;
    l->next = NULL;
	for(i = 0; i < n; ++i)
	{
        l = insert(l, arr[i]);
	}

	return l;
}
void print(List l)
{
    List p = l->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}
void test_link()
{
    List l = NULL;
    l = insert(l, 100);
    print(l);
    int arr[] = {1, 2, 3};
    l = create_list(arr, 3);
    print(l);
}

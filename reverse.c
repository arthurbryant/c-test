#include <stdio.h>
#include "link.h"

List reverse(List l)
{
    if(NULL == l || NULL == l->next)
        return l;
    List p = l->next;
    List q = p->next;
    p->next = NULL;
    List r = NULL;
    while(q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    l->next = p;
    return l;
}
void test_reverse()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    List l = NULL;
    l = create_list(arr1, sizeof(arr1)/sizeof(int));
    print(l);
    l = reverse(l);
    print(l);
}
int main(int argc, char * argv[])
{
    test_reverse();

    return 0;
}

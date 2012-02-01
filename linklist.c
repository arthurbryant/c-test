#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node
{
	int data;
	struct node * next;
	int flag;
};

struct node *init(int i)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->data = i;
	n->flag = 0;
	n->next = NULL;

	return n;
}
struct node *build_list()
{
	int i = 0;
	struct node *root = init(i);
	struct node *r = root;
	struct node *flag;
	for(i = 1; i < MAX; ++i)
	{
		struct node *p = init(i);
		if(2 == i)
			flag = p;
		r->next = p;
		r = p;
	}
	r->next = flag;	

	return root;
}
void display(struct node *root)
{
	struct node *r = root;
	while(r != NULL)
	{
		printf("%d\n", r->data);
		r = r->next; 
	}
}
void test(struct node * root)
{
	struct node *r = root;
	while(r!= NULL)
	{
		if(1 == r->flag)
		{
			printf("circle exist\n");
			return;
		}
		else
		{
			r->flag = 1;
			r = r->next;
		}
			
	}
	printf("no circle\n");
}
void test2(struct node *root)
{
	struct node *array[MAX] = {NULL};
	struct node *r = root;
	while(r != NULL)
	{
		int i = 0;
		while(array[i] != NULL)
		{
			if(array[i] == r)
			{
				printf("circle exist\n");
				return;
			}
			else
			{
				++i;
			}
		}
		if(array[i] == NULL)
		{
			array[i] = r;
			r = r->next;
		}
		else
			perror("error\n");
	}
}
void test3(struct node * root)
{
	int N = MAX;
	struct node *r = root;
	if(NULL == r)
		perror("root is null\n");

	struct node *p = r->next;
	struct node *q;
	while(r)
	{
		int i = 0;
		q = p;
		while(q && (i < N))
		{
			++i;
			if(q == r)
			{
				printf("circle exist\n");
				return;
			}
			else
			{
				q = q->next;
			}
		}
		r = p;
		if(r)
		{
			p = r->next;
			--N;
		}
		else
		{
			printf("no circle\n");
			return;
		}
	}
}
void test4(struct node * root)
{
	struct node *p1 = root;
	struct node *p2 = root;
	if(NULL == root)
		perror("root is null");
	while(p1 && p2)
	{
		p1 = p1->next;
		if(p2->next)
		{
			p2 = p2->next->next;
		}
		else
		{
			printf("no circle\n");
			return;
		}
		if(p1 == p2)
		{
			printf("circle exist\n");
			return;
		}
	}
	printf("no circle\n");
}
int main()
{
	struct node * root;
   	root = build_list();
	
   	display(root);
	//test(root);
	//test2(root);
	//test4(root);

    return 0;
}

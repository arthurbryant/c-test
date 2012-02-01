#ifndef LINK_H
#define LINK_H

struct node
{
	int data;
	struct node * next;
};
typedef struct node* List;

List insert(List , int);
List create_list(int[], int);
void print(List l);
#endif

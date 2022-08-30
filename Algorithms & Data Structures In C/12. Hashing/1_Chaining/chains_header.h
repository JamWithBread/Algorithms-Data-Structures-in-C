// Header file for heap datastructure implementation
// includes linked list logic

#ifndef chains_header_h
#define chains_header_h
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

void SortedInsert(struct Node **H, int x)
{
	struct Node *t, *q = NULL, *p = *H;

	t=(struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;

	if(*H == NULL)
	{
		*H = t;
	}
	else
	{
		while(p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if(p==*H)
		{
			t->next = *H;
			*H = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

void Delete(struct Node **H, int key)
{
	struct Node *p = *H;
	struct Node *last;
	while (p)
	{
		if(key == p->data)
		{
			break;
		}
		else
			last = p;
			p = p->next; 
	}

	if(p == *H)
	{
		//printf("Item to delete is head of LL\n");
		//printf("H->data = %d\n",H->data);
		//printf("p->data  = %d\n",p->data);
		*H = p->next;
		free(p);
	}
	else
	{
		last->next = p->next;
		free(p);
	}
}

struct Node * Search(struct Node *p, int key)
{
	while (p)
	{
		if(key == p->data)
		{
			return p;
		}
		p = p->next; 
	}
	return NULL;
}


#endif /* Chain_header_h */





// Double linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*first=NULL;

void Create(int A[], int n)
{
	struct Node *t, *last;
	int i=0;
	first = (struct Node *)malloc(sizeof(struct Node));
	first -> data = A[i];
	first -> prev = NULL;
	first -> next = NULL;
	last = first;
	for(i=1; i<n; i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t -> data = A[i];
		t -> next = NULL;
		t -> prev = last;
		last -> next = t;
		last = t;
	}
}

void Display(struct Node *p)
{
	while(p)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
}

int Length(struct Node *p)
{
	int x =0;
	while(p)
	{
		x++;
		p=p->next;
	}
	return x;
}

void InsertDLL(struct Node *p, int item, int index)
{
	struct Node *t;
	int i;

	if(index < 0 || index > Length(p))
	{
		return;
	}
	else if(index == 0)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t -> data = item;
		t -> prev = NULL;
		t -> next = first;
		first -> prev = t;
		first = t;
	}
	else
	{
		for(i=0; i<index-1; i++)
		{
			p = p ->next;
		}
		t = (struct Node *)malloc(sizeof(struct Node));
		t -> data = item;
		t -> next = p ->next;
		t -> prev = p;
		if(p->next) {p->next->prev = t;}
		p -> next = t;

	}
}

int DeleteDLL(struct Node *p, int index)
{
	struct Node *q;
	int item=-1,i;

	if(index < 0 || index > Length(p))
	{
		return -1;
	}
	else if(index == 0)
	{
		first = first ->next;
		if(first)first->prev = NULL;
		item = p->data;
		free(p);
	}
	else
	{
		for(i=0; i<index; i++)
		{
			p = p->next;
		}
		p->prev->next = p->next;
		if(p) {p->next->prev = p->prev;}
		item = p->data;
		free(p);
	}
	return item;
}

void ReverseDLL(struct Node *p)
{
	struct Node *temp;
	while(p)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		if(p!=NULL && p->next==NULL)
		{
			first = p;
		}
	}
}

int main(void)
{
	int A[] = {1,2,3,4,5,7,8,9};
	Create(A,8);
	Display(first);
	printf("%d\n", Length(first));

	InsertDLL(first, 55, 3);
	InsertDLL(first, 100, 0);
	Display(first);

	printf("Deleting first node:\n");
	DeleteDLL(first,0);
	Display(first);

	printf("Deleting item at index 2: \n");
	DeleteDLL(first,2);
	Display(first);

	printf("Reversing doubly linked list: \n");
	ReverseDLL(first);
	Display(first);


	return 0;
}


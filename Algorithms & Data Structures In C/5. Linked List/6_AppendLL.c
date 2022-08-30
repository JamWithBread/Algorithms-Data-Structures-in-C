// Append to a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;

}*first = NULL;

struct Node *globallast;

void Create(int A[], int n)
{
	int i;
	struct Node *t, *last;

	first = (struct Node *)malloc(sizeof(struct Node));
	first -> data = A[0];
	first -> next = NULL;

	last = first;

	for(i=1; i<n; i ++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t -> data = A[i];
		t -> next = NULL;
		last -> next = t;
		last = t;
		if(i == n-1)
		{
			globallast = t;
		}
	}
}


void AppendLL(struct Node *p, int element)
{
	struct Node *t;
	t =(struct Node *)malloc(sizeof(struct Node));
	t -> data = element;
	t -> next = NULL;

	// if linked list is empty
	if(first == NULL)
	{
		first = globallast = t;
	}

	else
	{
		globallast -> next = t;
		globallast = t;
	}

}


void Display(struct Node *p)
{
	printf("Elements of linked list consist of: ");
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


int main(void)
{
	int A[5] = {1,2,3,4,5};
	Create(A, 5);
	Display(first);

	int ele;
	printf("Enter element to append to linked list: ");
	scanf("%d", &ele);
	AppendLL(first, ele);
	Display(first);

	return 0;

}
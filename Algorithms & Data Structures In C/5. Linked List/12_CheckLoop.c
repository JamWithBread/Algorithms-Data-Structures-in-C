// checks if linked list contains a loop or is linear

// Display a linked list 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first = NULL; // to implement a linked list a pointer call is needed. This becomes a global pointer
		 // and can be accessed directly or passed into a function
		 // --> see reference in Display() call in main() function

void Create(int A[], int n)
{
	int i;
	struct Node *t, *last;

	first = (struct Node *)malloc(sizeof(struct Node));
	first -> data = A[0];
	first -> next = NULL;
	last = first;

	for(i=1; i<n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t -> data = A[i];
		t -> next = NULL;
		last -> next = t;
		last = t;
	}
}

void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int IsLoop(struct Node *f)
{
	struct Node *p, *q;
	p=q=f;
	do
	{
		p = p->next;
		q = q->next;
		q=q?q->next:q;
	}while(p && q && p!=q);
	if(p==q)
		return 1;
	else
		return 0;
}

int main(void)
{
	int A[] = {3,5,7,10,16};
	Create(A,5);
	Display(first);
	if (IsLoop(first) == 1)
		printf("linked list contains a loop\n");
	else
		printf("Linked list is linear\n");

	return 0;
}
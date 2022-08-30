// Recursive approach for displaying linked list

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

void RecDisplayLL(struct Node *p)
{
	if(p!=NULL)
	{
		printf("%d ", p->data);
		RecDisplayLL(p->next);
	}
	printf("\n");
}

int main(void)
{
	int A[5] = {1,2,3,4,5};
	Create(A,5);
	RecDisplayLL(first);

	return 0;
}






// Counting nodes in a linked list

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

int CountNodes(struct Node *p)
{
	int c=0;
	while(p!=NULL)
	{
		c ++;
		p = p -> next;
	}
	return c;
}

// Recursive just bc
int RSumLL(struct Node *p)
{
	int total = 0;
	if(p==NULL)
	{
		return 0;
	}
	else
		return SumLL(p->next) + p->data;
		
	return total;
}

int main(void)
{
	int result1, result2;
	int A[5] = {1,2,3,4,5};
	Create(A,5);
	RecDisplayLL(first);

	result1 = CountNodes(first);
	result2 = RSumLL(first);
	printf("Linked list is %d nodes large\n", result1);
	printf("Sum of all elements in linked list is %d\n", result2);

	return 0;
}
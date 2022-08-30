// Min and Max elements in a linked list

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

int Max(struct Node *p)
{
	int max = p->data;
	while(p)
	{
		if (max < p -> data)
			max = p -> data;
		p = p -> next;
	}
	return max;
}

int Min(struct Node *p)
{
	int min = p->data;
	while(p)
	{
		if (min > p -> data)
			min = p -> data;
		p = p -> next;
	}
	return min;
}



int main(void)
{
	int A[] = {3,5,7,10,16};
	Create(A,5);
	printf("Max element in linked list is: %d\n", Max(first));
	printf("Min element in linked list is : %d\n", Min(first));

	return 0;
}
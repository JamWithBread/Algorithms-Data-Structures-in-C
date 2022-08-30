// Reverse a linked list

#include <stdio.h>
#include <stdlib.h>




struct Node
{
	int data;
	struct Node *next;

}*first = NULL;

void Create(int A[],int n)
{
	int i;
	struct Node *t, *last;

	first = (struct Node*)malloc(sizeof(struct Node));
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
		printf("%d ", p -> data);
		p = p->next;
	}
	printf("\n");
}
// Method 1 -> copy elements to array and back
void ReverseLL_1(struct Node *p)
{
	int i = 0;
	int *A = (int*)malloc(sizeof(int));
	A[i] = p->data;
	p = p->next;

	while(p!=NULL)
	{
		i++;
		int *B = (int*)realloc(A, (i+1)*sizeof(int));
		A = B;
		A[i] = p->data;
		p = p->next;
	}

	p = first;
	while(p!=NULL)
	{
		p->data = A[i--];
		p = p->next;
	}
}

// Method 2 -> sliding pointers
void ReverseLL_2(struct Node *p)
{
	struct Node *left, *mid, *right;
	right = first;
	mid = NULL;
	left = NULL;
	while(right!=NULL)
	{
		left = mid;
		mid = right;
		right = right->next;
		mid -> next = left;
	}
	first = mid;
}


int main(void)
{
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	Create(A, 10);
	Display(first);
	ReverseLL_1(first);
	Display(first);
	ReverseLL_2(first);
	Display(first);

}
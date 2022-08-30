// Concatenate two linked lists

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;

}*temp = NULL, *first = NULL, *second = NULL;

struct Node* Create(int A[],int n)
{
	int i;
	struct Node *t, *last;

	temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = A[0];
	temp -> next = NULL;
	last = temp;

	for(i=1; i<n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t -> data = A[i];
		t -> next = NULL;
		last -> next = t;
		last = t;

	}
	return temp;
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

struct Node* ConcatLL(struct Node *p, struct Node *q)
{
	while(p->next!=NULL)
	{
		p = p -> next;
	}
	p -> next = q;
	q = NULL;
	return first;
}

int main(void)
{

	int A[] = {1,2,3,4,5};
	int B[] = {6,7,8,9,10};
	first = Create(A,5);
	second = Create(B,5);
	ConcatLL(first, second);
	Display(first);
	


}
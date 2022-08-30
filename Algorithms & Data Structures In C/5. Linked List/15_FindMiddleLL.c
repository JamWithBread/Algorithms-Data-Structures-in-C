// Find the middle node of a linked list

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

int LengthLL(struct Node *p)
{
	int length = 0;
	while(p)
	{
		p = p->next;
		length++;
	}
	return length;
}
// Method 1
int FindMiddleLL_1(struct Node *p)
{
	int length = LengthLL(p);
	int middle = length/2;
	int data, i;

	for(i=0; i<middle; i++)
	{
		p = p->next;
	}
	data = p->data;
	return data;
}

// Method 2: sliding pointers
int FindMiddleLL_2(struct Node *p)
{
	struct Node *q;
	int data;

	q = first;
	while(q)
	{
		q = q->next;
		if(q) {p = p->next;}
		if(q) {q = q->next;}
	}
	data = p -> data;
	return data;
}


int main(void)
{
	int A[] = {3,5,7,10,16};
	Create(A,5);
	Display(first);
	printf("The element in the middle node of the linked list is: %d\n", FindMiddleLL_1(first));
	printf("The element in the middle node of the linked list is: %d\n", FindMiddleLL_2(first));

	return 0;
}
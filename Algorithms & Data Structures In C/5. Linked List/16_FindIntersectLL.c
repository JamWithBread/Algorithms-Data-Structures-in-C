// Find the intersecting points of two linked lists that share some nodes

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*temp = NULL, *first = NULL, *second=NULL; // to implement a linked list a pointer call is needed. This becomes a global pointer
		 // and can be accessed directly or passed into a function
		 // --> see reference in Display() call in main() function

struct Node * Create(int A[], int n)
{
	int i;
	struct Node *t, *last;

	temp = (struct Node *)malloc(sizeof(struct Node));
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

// First two arguments: linked list to be connected to and at what index
// Second two argumentsL linked list to be connected and at what index
void ConnectLL(struct Node *p, int index1, struct Node*q, int index2)
{
	struct Node *temp, *prev;
	int i, length;
	for(i = 0; i < index1; i++)
	{
		p = p->next;
	}

	for(i = 0; i < index2; i++)
	{
		q = q->next;
	}
	temp = q;

	// Free extra nodes of second LL
	length = LengthLL(q);
	for(i = index2; i < length; i++)
	{
		prev = q;
		q = q ->next;
		free(prev);
	}

	//Connect LLs
	temp -> next = p;
}

struct Tuple
{
	int index1;
	int index2;
};

struct Tuple FindIntersectLL(struct Node *p, struct Node *q)
{
	struct Tuple results;
	int i,j;
	int length1, length2;
	length1 = LengthLL(p);
	length2 = LengthLL(q);

	int **A = (int **)malloc(length1*sizeof(int));
	int **B = (int **)malloc(length2*sizeof(int));

	for(i = 0; i<length1; i++)
	{
		A[i] = &p->data;
		//printf("Element %d stored at index %d of A\n", p->data, i);
		p = p->next;
	}

	for(i = 0; i<length2; i++)
	{
		B[i] = &q->data;
		printf("Element %d stored at index %d of B\n", q->data, i);
		q = q->next;
	}
///////////////////
	printf("\nAddresses in array A:\n");
	for(i=0; i < length1; i++)
	{
		printf("Address of element %d: %p\n", i, A[i]);
	}
	printf("Addresses in array B:\n");
	for(j=0; j < length2; j++)
	{
		printf("Address of element %d: %p\n", j, B[j]);
	}
	/////////////

	for(i = length1-1, j = length2-1; i > 0 && j > 0; i--, j--)
	{
		if(A[i] == B[j])
		{
			results.index1 = i-1;
			results.index2 = j-1;
			return results;
		}
	}



	return results;
}

int main(void)
{
	struct Tuple results;
	int A[] = {1,2,3,4,5,6,8,9,10};
	int B[] = {12,34,54};
	first = Create(A,9);
	second = Create(B,3);

	Display(first);
	Display(second);

	
	ConnectLL(first,7,second,2);
	printf("Linked lists connected\n");

	Display(first);
	Display(second);
	results = FindIntersectLL(first, second);
	printf("The linked lists begin to intersect at index %d of first list, index %d of second list\n", results.index1, results.index2);


}







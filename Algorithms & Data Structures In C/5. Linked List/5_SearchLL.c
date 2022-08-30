// Searching a linke list

// Note: binary search does not work here because we can't start in the middle of a linked list
// Improve Searching: can be done by using transposition or 'move to head'. 
	// -> improves search time of frequently searched elements

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
}

// removes node containing searched element from LL, reconnects it as first node, connects gap
//void MoveToHead(struct Node *first, struct Node *p, struct Node *q)
//{
//	q -> next = p -> next;
//	p -> next = first;
//	first = p;
//}

// Linear search with move-to-head improvement
int LinearSearchLL(struct Node *p, int element)
{	
	struct Node *q = NULL;
	int index = -1;
	while(p)
	{
		if(p -> data == element)
		{
			//MoveToHead(first,p,q);
			q -> next = p -> next;
			p -> next = first;
			first = p;
			return index;			
		}
		else
		{
			index ++;
			q = p;
			p = p -> next;
		}
	}
	return -1;
}


int main(void)
{
	int A[] = {3,5,7,10,16};
	Create(A,5);
	int ele, result;

	printf("Enter an element you would like to search for: ");
	scanf("%d", &ele);

	result = LinearSearchLL(first, ele);
	printf("The element you searched for is at index %d\n", result);

	Display(first);

	return 0;
}
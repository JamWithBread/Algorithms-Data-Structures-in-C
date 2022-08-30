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

int CheckSortedLL(struct Node *p)
{
	int i, prev;
	prev = first -> data;
	p = p ->next;
	while (p!=NULL)
	{
		printf("prev = %d, current = %d\n", prev, p->data);
		if(prev > p->data) 
		{
			return 0;
		}
		else 
		{
			prev = p->data;
			p = p->next;
		}
	}
	return 1;
}

int main(void)
{
	int A[] = {3,5,10,7,16};
	Create(A,5);
	Display(first);

	char *sorted;
	if(CheckSortedLL(first))
	{
		sorted = "sorted";
	}
	else
	{
		sorted = "not sorted";
	}

	printf("The linked list is %s\n", sorted);

	return 0;
}



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

int Delete(struct Node *p, int index)
{
	struct Node *q;
	int x=-1, i;

	if (index < 1 || index > CountNodes(p))
	{
		return -1;
	}
	// If deleting first node
	if(index == 1)
	{
		q = first;
		x = first->data;
		first = first->next;
		free(q);
		return x;
	}
	else
	{
		for(i = 0; i< index-1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x=p->data;
		free(p);
		return x;
	}
}

int main(void)
{
	int A[] = {3,5,7,10,16,20,45};
	int index;
	Create(A,7);
	Display(first);

	printf("Enter the index of an elemet to be deleted: ");
	scanf("%d", &index);
	printf("You deleted element %d from linked list\n", Delete(first,index));
	Display(first);

	return 0;
}


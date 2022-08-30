// Insert a new node in a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;

}*first = NULL;

void Create(int A[], int n)
{
	int i;
	struct Node *t, *last;

	first = (struct Node *)malloc(sizeof(struct Node));
	first -> data = A[0];
	first -> next = NULL;

	last = first;

	for(i=1; i<n; i ++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t -> data = A[i];
		t -> next = NULL;
		last -> next = t;
		last = t;
	}
}


void Display(struct Node *p)
{
	printf("Elements of linked list consist of: ");
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

void Insert(struct Node *p, int index, int element)
{
	if (index < 0 || index > CountNodes(first))
	{
		printf("Error: List index out of bounds\n");
		return;
	}
	else if(index == 0)
	{
		struct Node *t;
		t = (struct Node *)malloc(sizeof(struct Node));
		t -> data = element;
		t -> next = first;
		first = t;
	}
	else
	{
		int i;
		struct Node *p;
		struct Node *t;
		t = (struct Node *)malloc(sizeof(struct Node));
		t -> data = element;

		p = first;
		for(i=1; i<index; i++)
		{
			p = p -> next;
		}
		t -> next = p ->next;
		p -> next = t;
	}
}


int main(void)
{
	int A[5] = {1,2,3,4,5};
	Create(A, 5);
	Display(first);

	int ele, index;

	printf("Enter element to insert and at which index\n");
	scanf("%d%d", &ele,&index);

	Insert(first,index, ele);
	Display(first);
}
// Merge two (sorted) linked lists

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*temp = NULL, *first = NULL, *second = NULL, *third=NULL; 


struct Node* Create(int A[], int n)
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

void Merge(struct Node *p, struct Node *q)
{
	struct Node *last;
	if(p->data < q->data)
	{
		third = last = p;
		p = p->next;
		third->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		third->next = NULL;
	}

	while (p&&q)
	{
		if(p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}
	if(p)
		last->next = p;
	if(q)
		last->next = q;
}

int main(void)
{
	int A[] = {3,5,7,10,16};
	int B[] = {1,2,3,4,5,6};
	first = Create(A,5);
	second = Create(B,6);

	printf("First list: ");
	Display(first);

	printf("Second list: ");
	Display(second);

	Merge(first,second);
	printf("Merged linked list: ");
	Display(third);

	return 0;
}
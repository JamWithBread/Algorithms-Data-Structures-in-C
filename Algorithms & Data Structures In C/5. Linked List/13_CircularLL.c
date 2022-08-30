// Circular linked list -> 2 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*Head; // to implement a linked list a pointer call is needed. This becomes a global pointer
		 // and can be accessed directly or passed into a function
		 // --> see reference in Display() call in main() function


// Create circular linked list
void Create(int A[], int n)
{
	int i;
	struct Node *t, *last;

	Head = (struct Node *)malloc(sizeof(struct Node));
	Head -> data = A[0];
	Head -> next = Head;
	last = Head;

	for(i=1; i<n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t -> data = A[i];
		t -> next = last->next;
		last -> next = t;
		last = t;
	}
}


// Display circular linked list
void Display(struct Node *h)
{
	do
	{
		printf("%d ", h->data);
		h = h->next;
	}while(h!=Head);
	printf("\n");
}

void Insert(struct Node *h, int item, int index)
{
	struct Node *t, *last;
	int i;

	// if index is 0, create a new node before head node
	if(index == 0)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = item;
		if(Head == NULL)
		{
			Head = t;
			Head->next=Head;
		}
		else
		{
			while(h->next!=Head)
			{
				h = h->next;
			}
			h->next = t;
			t -> next = Head;
			Head = t;
		}
	}
	else
	{
		for(i=0;i<index;i++)
		{
			last = h;
			h = h->next;
		}
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = item;
		t->next = h;
		last->next = t;

	}
}

int Delete(struct Node *h, int index)
{
	int i, deleted;
	struct Node *last;

	if(index == 0)
	{
		while(h->next!=Head)
		{
			h = h->next;
		}
		deleted = Head->data;
		if(Head==h)
		{
			free(Head);
			Head = NULL;
		}
		else
		{
			h->next = Head->next;
			free(Head);
			Head = h->next;
		}

	}
	else
	{
		for(i=0; i < index; i++)
		{
			last = h;
			h = h->next;
		}
		deleted = h->data;
		last->next = h->next;
		h->next = NULL;
		free(h);
	}
	return deleted;
}

int main(void)
{
	int A[] = {1,2,3,4,5};
	Create(A,5);
	Display(Head);

	Insert(Head,24,3);
	Display(Head);

	Delete(Head,3);
	Display(Head);
	return 0;

}
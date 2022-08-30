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

int main(void)
{
	int A[5] = {1,2,3,4,5};
	struct Node *first;
	first = Create(A,5);

	printf("first: %p\n", first);
	printf("*first: %p\n", (void*)first);
	printf("&first: %p\n", &first);

}






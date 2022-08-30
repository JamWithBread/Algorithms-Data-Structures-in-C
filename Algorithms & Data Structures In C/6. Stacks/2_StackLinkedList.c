// Stack data structure implemented using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
}*top=NULL;

void Push(int x)
{
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));

	if(t==NULL)
	{
		printf("stack is full\n");
	}

	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int Pop()
{
	struct Node *t;
	int x;
	if(top ==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		t  = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}

void Display()
{
	struct Node *p;
	p=top;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


int main(void)
{
	Push(10);
	Push(15);
	Push(22);
	Display();
	printf("Popped: %d\n", Pop());
	Display();
	return 0;

}



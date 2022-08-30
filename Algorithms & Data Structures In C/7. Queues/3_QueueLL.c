// Implementation of queue data structure using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
}*front=NULL, *rear=NULL;

void Enqueue(int x)
{
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	if(t==NULL)
	{
		printf("Heap is full\n");
	}
	else
	{
		t->data=x;
		t->next=NULL;
		if(front==NULL)
		{
			front = t;
			rear = t;
		}
		else
		{
			rear->next = t;
			rear = t;
		}
	}
}

int Dequeue()
{
	int x = -1;
	struct Node *t;

	if(front==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		x = front->data;
		t = front;
		front = front->next;
		free(t);
	}
	return x;
}

void Display()

{
	struct Node *p=front;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}



int main(void)
{

	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
	Enqueue(40);
	Enqueue(50);

	Display();

	printf("Dequeueing: %d\n",Dequeue());
	Display();
}








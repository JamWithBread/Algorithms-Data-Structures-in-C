// Queue using linked list


#ifndef Queue_h
#define Queue_h
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*front = NULL, *rear = NULL;

void Enqueue(int x)
{
	struct Node *t;
	t = (struct Node*)malloc(sizeof(struct Node));
	if(t == NULL)
	{
		printf("Queue is full\n");
	}
	else
	{
		t->data = x;
		t->next = NULL;
		if(front == NULL)
		{
			front = rear = t;
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

	if(front == NULL)
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

int IsEmpty()
{
	return front == NULL;
}

#endif /* Queue_h */






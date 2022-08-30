
#include <stdio.h>
#include <stdlib.h>

// structure for tree nodes
struct Node
{
	struct Node *lchild;
	int data;
	struct Node  *rchild;
};

struct Node *root = NULL;

/// Queue structure & functions ///

struct Queue
{
	int size;
	int front;
	int rear;
	struct Node **Q;
};

void CreateQueue(struct Queue *q, int size)
{
	q->size = size;
	q->front = q->rear = 0;
	q->Q = (struct Node **)malloc(q->size*sizeof(struct Node *));
}

void Enqueue(struct Queue *q, struct Node * x)
{
	if((q->rear+1)%q->size == q->front)
	{
		printf("Queue is Full\n");
	}
	else
	{
		q->rear = (q->rear+1)%q->size;
		q->Q[q->rear] = x;
	}
}

struct Node * Dequeue(struct Queue *q)
{
	struct Node * x = NULL;

	if(q->front == q->rear)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		q->front = (q->front+1)%q->size;
		x = q->Q[q->front];
	}
	return x;
}

int IsEmpty(struct Queue *q)
{
	if (q->front == q->rear)
	{
		return 1;
	}
	return 0;
}

/// Implement Binary Tree ///

void CreateBT()
{
	struct Node *p, *t;
	int x;
	struct Queue q;
	CreateQueue(&q,100);

	printf("Enter root value: ");
	scanf("%d", &x);

	//struct Node *root;
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;

	Enqueue(&q,root);
	while(!IsEmpty(&q))
	{
		p = Dequeue(&q);
		printf("Enter left child of %d: ", p->data);
		scanf("%d", &x);
		if(x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data  = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			Enqueue(&q,t);
		}

		printf("Enter right child of %d: ", p->data);
		scanf("%d", &x);
		if(x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data  = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			Enqueue(&q,t);
		}
	}
}

// Count nodes

int CountNodes(struct Node *p)
{
	int x, y;
	if(p!=NULL)
	{
		x = CountNodes(p->lchild);
		y = CountNodes(p->rchild);
		return x + y + 1;
	}
	return 0;
}

int CountLeafNodes(struct Node *p)
{
	int x,y;
	if(p!=NULL)
	{
		if(p->lchild == NULL && p->rchild == NULL)
		{
			return 1;
		}
		x = CountLeafNodes(p->lchild);
		y = CountLeafNodes(p->rchild);
		return x+y;
	}
	return x;
}

int main(void)
{
	CreateBT();
	printf("There are %d nodes in the tree\n", CountNodes(root));
	printf("There are %d leaf nodes in the tree\n", CountLeafNodes(root));

	return 0;

}
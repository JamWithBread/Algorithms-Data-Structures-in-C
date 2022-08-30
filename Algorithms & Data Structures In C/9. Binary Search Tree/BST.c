// Binary Search Tree Implementation

#include <stdio.h>
#include <stdlib.h>
#include "StackHeader.c"

#define COUNT 10;

struct Node 
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root=NULL;


void Insert(struct Node *t, int key)
{
	struct Node *r,*p;

	// first node
	if(root==NULL)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return;
	}
	while(t!=NULL)
	{
		r = t;
		if(key < t->data)
		{
			t = t->lchild;
		}
		else if(key > t->data)
		{
			t = t->rchild;
		}
		else
		{
			return;
		}
	}
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = key;
	p->lchild = p->rchild = NULL;	

	// r is now pointing at a node with two NULL children

	if(key < r->data)
	{
		r->lchild = p;
	}
	else
	{
		r->rchild = p;
	}
}

// Recursive Insert -> more succinct
struct Node * RInsert(struct Node *p, int key)
{
	struct Node *t = NULL;

	if (p == NULL)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	else if(key < p->data)
	{
		p->lchild = RInsert(p->lchild, key);
	}
	else
	{
		p->rchild = RInsert(p->rchild, key);
	}
	return p;
}

int Height(struct Node *p)
{
	int x,y;
	if (p == NULL)
		return 0;
	else
		x = Height(p->lchild);
		y = Height(p->rchild);
	return x>y?x+1:y+1;
}

struct Node *InOrderPred(struct Node *p)
{
	while(p && p->rchild !=NULL)
	{
		p = p->rchild;
	}
	return p;
}

struct Node *InOrderSucc(struct Node *p)
{
	while(p && p->lchild !=NULL)
	{
		p = p->lchild;
	}
	return p;
}

struct Node * Delete(struct Node *p, int key)
{
	struct Node *q;

	if(p == NULL)
		return NULL;
	if(p->lchild == NULL && p->rchild == NULL)
	{
		if(p==root)
			root = NULL;
		free(p);
		return NULL;
	}

	if(key < p-> data)
		p->lchild = Delete(p->lchild,key);
	else if(key > p->data)
		p->rchild = Delete(p->rchild, key);
	else
	{
		if(Height(p->lchild) > Height(p->rchild))
		{
			q = InOrderPred(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild, q->data);
		}
		else
		{
			q = InOrderSucc(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}
	}
	return p;
}

struct Node * Search(struct Node *t,int key)
{

	while (t!=NULL)
	{
		if(key == t->data)
		{
			return t;
		}
		else if(key < t->data)
		{
			t = t->lchild;
		}
		else
		{
			t = t->rchild;
		}
	}
	return NULL;
}

void InOrder(struct Node *p)
{
	if(p)
	{
		InOrder(p->lchild);
		printf("%d ", p->data);
		InOrder(p->rchild);
	}
}

// Display Function
// ----------------------------------------------------------- +
void Print2DTree(struct Node *p, int space)
{
	if(p==NULL)
	{
		return;
	}
	space += COUNT;

	//Process rightchild
	Print2DTree(p->rchild, space);

	printf("\n");

	int i = COUNT;
	for (; i < space; i++)
	{
		printf(" ");
	}
	printf("%d <\n", p->data);

	//Process left child
	Print2DTree(p->lchild, space);
}

void Print2D(struct Node *root)
{
	//Pass initial space count as 0
	Print2DTree(root,0);
}
// ----------------------------------------------------------- +

// Generating BST from Preorder
// ----------------------------------------------------------- +
void CreateFromPre(int pre[], int n)
{

	struct Stack *stk;
	stk->size = n;
	stk->top = -1;
	stk->S = (struct Node **)malloc(sizeof(struct Node *));

	struct Node *t, *p;
	int i = 0;

	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = pre[i++];
	root->lchild = root->rchild =  NULL;
	p = root;

	printf("p->data is %d\n", p->data);

	Push(stk,p);
	printf("StackTop(stk)->data = %d\n",StackTop(stk)->data);
	while(i<n)
	{	
		printf("i = %d, top = %d\n", i, stk->top);
		printf("First if\n");
		if(pre[i] < p->data)
		{
			printf("INside first if\n");
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = pre[i++];
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			Push(stk,p);
			p=t;
		}
		else
		{
			printf("2nd if\n");
			if(IsEmpty(stk) || (pre[i] > p->data && pre[i] < StackTop(stk)->data))
			{
				printf("Inside second if\n");
				t = (struct Node *)malloc(sizeof(struct Node));
				t->data = pre[i++];
				t->lchild = t->rchild = NULL;
				p->rchild = t;
				p = t;
			}
			
			else
			{ 
				printf("Inside else\n"); 
				p = Pop(stk);
			}
		}
	}
}

int main(void)
{
	int key = 20;
	struct Node *result;

	Insert(root, 10);
	Insert(root,5);
	Insert(root,30);
	Insert(root, 8);
	Insert(root,40);

	RInsert(root,35);
	RInsert(root,1);
	RInsert(root,26);
	RInsert(root,150);
	RInsert(root,15);
	RInsert(root,14);

	InOrder(root);
	printf("\n");

	result = Search(root, key);
	if(result)
	{
		printf("Result of search for element %d was successful\n", key);
	}
	else
	{
		printf("Result of search for element %d was unsuccessful\n", key);
	}

	Print2D(root);

	printf("Deleting the root node:\n");
	Delete(root, root->data);
	Print2D(root);

	printf("\nGenerating tree from preoder list\n");
	int prelist[] = {30,20,10,15,25,40,50,45};
	CreateFromPre(prelist,8);
	Print2D(root);


	

	return 0;
}







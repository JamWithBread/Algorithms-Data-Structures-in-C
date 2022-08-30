// AVL trees and rebalancing

#include <stdio.h>
#include <stdlib.h>

#define COUNT 10;


struct Node 
{
	struct Node *lchild;
	int data;
	int height;
	struct Node *rchild;

}*root = NULL;

int NodeHeight(struct Node *p)
{
	int hl,hr;
	//if p is not NULL and has a left child, evaluates to left child height, otherwise evaluates to 0
	hl = p && p->lchild ? p->lchild->height:0;
	hr = p && p->rchild ? p->rchild->height:0;

	return hl>hr ? hl+1 : hr+1;
}

int BalanceFactor(struct Node *p)
{	
	int hl,hr;
	hl = p && p->lchild!=NULL ? p->lchild->height:0;
	hr = p && p->rchild!=NULL ? p->rchild->height:0;
	return hl-hr;
}

struct Node * LLRotation(struct Node *p)
{
	printf("Calling LL Rotation\n");
	struct Node *pl = p->lchild;
	struct Node *plr = pl->rchild;

	pl->rchild = p; // pr->lchild = p;
	p->lchild = plr; //p->rchild = prl;
	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);

	if(root == p)
	{
		root = pl;
	}

	return pl;
}

struct Node * LRRotation(struct Node *p)
{
	printf("Calling LR rotation\n");
	struct Node *pl = p->lchild; // struct Node *pr = p->rchild;
	struct Node *plr = pl->rchild; // struct Node *prl = pr ->lchild;

	pl->rchild = plr->lchild; // pr->lchild = prl->rchild;
	p->lchild = plr->rchild; // p->rchild = prl->lchild;

	plr->lchild = pl; // prl->lchild = pr;
	plr->rchild = p; // prl ->lchild = p;

	pl->height = NodeHeight(pl); // pr->height = NodeHeight(pr);
	p->height = NodeHeight(p); // p->height = NodeHeight(p);
	plr->height = NodeHeight(plr); //prl->height =NodeHeight(prl;)

	if(root == p)
	{
		root = plr;
	}
	return plr;
}

struct Node * RRRotation(struct Node *p)
{
	printf("Calling RR rotation\n");
	struct Node *pr = p->rchild;
	struct Node *prl = pr->lchild;

	pr->lchild = p;
	p->rchild = prl;
	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);

	if(root == p)
	{
		root = pr;
	}

	return pr;
}

struct Node * RLRotation(struct Node *p)
{
	printf("Calling RL rotation\n");
	struct Node *pr = p->rchild;
	struct Node *prl = pr ->lchild;

	pr->lchild = prl->rchild;
	p->rchild = prl->lchild;

	prl->rchild = pr;
	prl->lchild = p;

	pr->height = NodeHeight(pr);
	p->height = NodeHeight(p);
	prl->height =NodeHeight(prl);

	if(root == p)
	{
		root = prl;
	}
	return prl;
}

struct Node * Rebalance(struct Node *p)
{
	if((BalanceFactor(p) == 2 && p->lchild!=NULL) && BalanceFactor(p->lchild) == 1)
		return LLRotation(p);
	else if((BalanceFactor(p) == 2 && p->lchild!=NULL) && BalanceFactor(p->lchild) == -1)
		return LRRotation(p);
	else if((BalanceFactor(p) == -2 && p->rchild!=NULL) && BalanceFactor(p->rchild) == -1)
		return RRRotation(p);
	else if((BalanceFactor(p) == -2 && p->rchild!=NULL) && BalanceFactor(p->rchild) == 1)
		return RLRotation(p);
	else
		return p;
}

struct Node * RInsert(struct Node *p, int key)
{
	struct Node *t = NULL;

	if (p == NULL)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->height = 1;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if(key < p->data)
	{
		p->lchild = RInsert(p->lchild, key);
	}
	else if(key > p->data)
	{
		p->rchild = RInsert(p->rchild, key);
	}
	else
		return p;

	p->height = NodeHeight(p);

	// Find balance factor and perform rotation if necessary 

	p = Rebalance(p);

	return p;
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
		if(p->lchild->height > p->rchild->height)
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

	p = Rebalance(p);

	return p;
}

// Tree Print Function
//-----------------------------------------------------------+
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

void Print2D(struct Node *p)
{
	Print2DTree(root,0);
}
//-----------------------------------------------------------+

int main(void)
{
	int inlist[8] = {10,20,30,25,28,27,5,10};
	root = RInsert(root,inlist[0]);
	int i = 1;
	while(i<8)
	{
		RInsert(root,inlist[i++]);
		Print2D(root);
		printf("-------------\n");
	}



	printf("root->data = %d\n", root->data);
	//printf("root->rchild->data = %d", root->rchild->data);
	Print2D(root);

	Delete(root,25);
	Print2D(root);

	return 0;


}









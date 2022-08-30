// Parenthesis matching

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
	char data;
	struct Node *next;
}*top=NULL;

void Push(char x)
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

char Pop()
{
	struct Node *t;
	char x;
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

int IsComplement(char *char1, char *char2)
{

	

	if (strcmp(char1,"[") && strcmp(char2,"]"))
	{
		return 1;
	}
	else if(strcmp(char1,"{") && strcmp(char2,"}"))
	{
		return 1;
	}
	else if(strcmp(char1,"(") && strcmp(char2,")"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isBalanced(char *exp)
{
	int i;
	char popped;
	for (i=0; exp[i]!='\0'; i++)
	{
		if(exp[i]=='(' || exp[i] == '{' || exp[i] == '[')
		{
			Push(exp[i]);
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(top==NULL)
			{
				printf("Stack is empty\n");
				return 0;
			}
			popped = Pop();
			if(!IsComplement(&popped,&exp[i]))
			{
				return 0;
			}

		}
	}
	if(top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
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

void Clear(struct Node *p)
{
	struct Node *temp;
	while(p)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
}

int main(void)
{
	//char *exp1 = "((a+b)*(c-d))";
	//char *exp2 = "{([a+b)*[c-d]]/e";
	char *exp3 = "{([a+b]*[c-d])/e}";
	char *exp4 = "((a+b)*(c-d))";
	


	//printf("%d ", isBalanced(exp1));
	//Clear(top);
	//printf("%d ", isBalanced(exp2));
	//Clear(top);
	printf("%d ", isBalanced(exp3));
	Clear(top);
	printf("%d ", isBalanced(exp4));
 
}







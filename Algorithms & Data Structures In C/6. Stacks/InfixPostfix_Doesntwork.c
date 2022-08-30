// Program that converts an infix expression to a postfix expression, and evaluates the postifix expression

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

int CheckPrec(char x)
{
	if (!strcmp(&x,"+") || !strcmp(&x,"-"))
	{
		return 1;
	}
	else if (!strcmp(&x,"*") || !strcmp(&x,"/"))
	{
		return 2;
	}
	else
		return 0;
}

int IsOperand(char x)
{
	if(!strcmp(&x,"+") || !strcmp(&x,"-") || !strcmp(&x,"*") || !strcmp(&x,"/"))
	{
		return 0;
	}
	else
		return 1;
}

void Display()
{
	struct Node *p;
	p=top;
	while(p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

char * InfixToPostfix(char *infix)
{
	int i =0, j =0;
	char *postfix;
	int len = strlen(infix);
	postfix = (char*)malloc((len+2)*sizeof(char));

	while(infix[i]!='\0')
	{
		printf("Status of stack: ");
		Display();

		if(IsOperand(infix[i]))
		{
			postfix[j++] = infix[i++];
		}
		else
		{
			if(top ==NULL)
			{
				printf("stack is empty");
			}

			if(strlen(&top->data) == '\0')
			{
				printf("top has no value\n");
			}
			//printf("Current operator is: %c, operator on stack is: %c\n", infix[i], top->data);
			if(CheckPrec(infix[i]) > CheckPrec(top->data) || strlen(&top->data) == 0)
			{
				printf("reached push of conversion function\n");
				//printf("logic says %c is greater than %c, Pushing\n", infix[i], top->data);
				Push(infix[i++]);
			}
			else
			{
				printf("Reached pop of conversion function\n");
				postfix[j++]=Pop();
			}
		}
	}
	while(top!=NULL)
	{
		postfix[j++] = Pop();
	}
	postfix[j]='\0';
	return postfix;
}

int main(void)
{

	//struct Node *top;
	char *infix = "a+b*c-d/e";
	//top = (struct Node *)malloc((strlen(infix)+2)*sizeof(struct Node));
	Push('#');
	char *char1 = "+";
	char *char2 = "#";
	printf("Check Prec of '#' and '+' yields: %d %d", CheckPrec(*char1), CheckPrec(*char2));

	char *postfix = InfixToPostfix(infix);

	printf("%s", postfix);


}






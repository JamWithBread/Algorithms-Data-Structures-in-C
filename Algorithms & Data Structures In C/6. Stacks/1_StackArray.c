// Implementation of a stack as an array structure

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int size;
	int top;
	int *s;
};

int CheckFull(struct Stack st)
{
	if (st.top == st.size-1)
	{
		printf("Stack overflow ");
		return 1;
	}
	return 0;
}

void Push(struct Stack *st, int item)
{
	if(!CheckFull(*st))
	{
		st->top ++;
		st->s[st->top] = item;
	}
}

void CreateStack(struct Stack *st)
{
	int n,i,item;
	printf("1/3. Enter maximum expected size of stack: ");
	scanf("%d", &st->size);
	st->s = (int*)malloc(st->size*sizeof(int));
	st->top = -1;

	printf("2/3. Enter the # of items to be pushed now: ");
	scanf("%d", &n);
	printf("3/3. Enter items to be added to the stack (LIFO): ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &item);
		Push(st,item);
	}
}

void DisplayStack(struct Stack *st)
{
	printf("Stack from top to bottom:\n");
	int i;
	i = st->top;
	while(i > -1)
	{
		printf("%d ", st->s[i]);
		i--;
	}
	printf("\n");
}

int Pop(struct Stack *st)
{
	int x = -1;
	if(st->top != -1)
	{
		x = st->s[st->top];
		st->top--;
	}
	else
	{
		printf("Stack underflow");
	}
	return x;
}

// shows item at given index in stack (top to bottom, index 0 = top element)
int Peek(struct Stack st, int index)
{
	int item = -1;
	if(st.top - index < 0)
	{
		printf("Invalid index\n");
	}
	else{
		index = st.top - index;
		item = st.s[index];
	}
	return item;
}

int StackTop(struct Stack st)
{
	if(st.top == -1)
	{
		printf("Stack is empty");
		return -1;
	}
	else
	{
		return st.s[st.top];
	}
}


int main(void)
{
	struct Stack st;
	CreateStack(&st);

	Push(&st, 3);
	Push(&st, 6);
	Push(&st, 9);
	Push(&st, 12);
	Push(&st, 15);
	DisplayStack(&st);
	Pop(&st);
	DisplayStack(&st);

	printf("Item at index 100 is %d\n", Peek(st,100));
}








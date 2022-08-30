// Stack header file for use in other programs that want to store node addresses

#ifndef Stack_h
#define Stack_h


// stack that will store node addresses in an array
struct Stack
{
	int size;
	int top;
	struct Node **S;
};

void CreateStack(struct Stack *st, int size)
{
	st->size = size;
	st->top = -1;
	st->S = (struct Node **)malloc(st->size*sizeof(struct Node*));
}

void Push(struct Stack *st, struct Node *x)
{
	if(st->top == st->size-1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		st->top++;
		st->S[st->top] = x;
	}
}

struct Node * Pop(struct Stack *st)
{
	struct Node * x = NULL;

	if(st->top == -1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		x = st->S[st->top--];
	}
	return x;
}

int IsEmptyStack(struct Stack st)
{
	if(st.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int IsFullStack(struct Stack st)
{
	if(st.top == st.size-1)
	{
		return 1;
	}
	return 0;
}

#endif /* Stack_h */





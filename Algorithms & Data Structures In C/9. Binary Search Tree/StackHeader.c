// Header file with stack functionality -> Implemented using  LL

struct Stack 
{
	int size;
	int top;
	struct Node **S;
}*top=NULL;


int CheckFull(struct Stack st)
{
	if (st.top == st.size-1)
	{
		printf("Stack overflow ");
		return 1;
	}
	return 0;
}

void Push(struct Stack *stk, struct Node *x)
{
	if(!CheckFull(*stk))
	{
		stk->top ++;
		stk->S[stk->top] = x;
	}
}

struct Node * Pop(struct Stack *st)
{
	struct Node *x = NULL;
	if(st->top != -1)
	{
		x = st->S[st->top];
		st->top--;
	}
	else
	{
		printf("Stack underflow");
	}
	return x;
}

struct Node * StackTop(struct Stack *st)
{
	if(st->top == -1)
	{
		printf("Stack is empty");
		return NULL;
	}
	else
	{
		return st->S[st->top];
	}
}

int IsEmpty(struct Stack *st)
{
	if (st->top ==-1)
	{
		//printf("Stack underflow ");
		return 1;
	}
	return 0;
}


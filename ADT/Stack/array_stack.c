#include "array_stack.h"

Stack CreateStack(int MaxElements)
{
	Stack S;

	if(MaxElements < MinStackSize)
	{
		fprintf(stderr, "Stack size if too small");
	}

	S = malloc(sizeof(struct StackRecord));

	if(S == NULL)
	{
		fprintf(stderr, "Out of Space!!!");
	}

	S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
	if(S->Array == NULL)
	{
		fprintf(stderr, "Out of Space!!!");
	}
	
	S->Capacity = MaxElements;
	MakeEmpty(S);
	
	return S;
}

void DisposeStack(Stack S)
{
	if(S != NULL)
	{
		free(S->Array);
		free(S);
	}
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity - 1;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if(IsFull(S))
	{
		fprintf(stderr, "Full Stack");
	}
	else 
	{
		S->Array[++S->TopOfStack] = X;
	}
}

ElementType Top(Stack S)
{
	if(!IsEmpty(S))
	{
		return S->Array[S->TopOfStack];
	}
	fprintf(stderr, "Empty Stack");
	return 0;
}

void Pop(Stack S)
{
	if(IsEmpty(S))
	{
		fprintf(stderr, "Empty Stack");
	}
	else 
	{
		S->TopOfStack--;
	}
}

ElementType TopAndPop(Stack S)
{
	if(!IsEmpty(S))
	{
		return S->Array[S->TopOfStack--];
	}
	fprintf(stderr, "Empty Stack");
	return 0;
}

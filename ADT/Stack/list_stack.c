#include "list_stack.h"

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S;
	S = malloc(sizeof(struct Node));

	if( S == NULL)
		fprintf(stderr, "Out of space !!!");

	S->Next == NULL;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S)
{
	if (S == NULL)
		fprintf(stderr, "Must use CreateStack first");
	else 
		while(!IsEmpty(S))
			Pop(S);
}

void Push(ElementType X, Stack S)
{
	PtrToNode TmpCell;

	TmpCell = (PtrToNode)malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		fprintf(stderr, "Out of space !!!");
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

ElementType Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->Element;
	fprintf(stderr, "Empty Stack");
	return 0;
}

void Pop(Stack S)
{
	PtrToNode FirstCell;
	if(IsEmpty(S))
		fprintf(stderr, "Empty Stack");
	else
	{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}

void DisposeStack(Stack S)
{
	MakeEmpty(S);
	free(S);
}

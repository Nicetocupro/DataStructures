#include<stdio.h>
#include<stdlib.h>

#ifndef _Stack_h 

typedef void *ElementType;
struct Node;
typedef struct Node *PtrToNode; 
typedef PtrToNode Stack;

struct Node{
	ElementType Element;
	PtrToNode Next;
};

int isEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif 

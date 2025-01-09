#include "avlTree.h"

static int Height(Position P)
{
	if(P == NULL)
		return -1;
	else 
		return P->Height;
}

static int UpdateHeight(Position P)
{
	if(P == NULL)
		return -1;
	else
	{
		P->Height = Max(UpdateHeight(P->Right), UpdateHeight(P->Left)) + 1
		return P->Height;
	}
}

static int Max(int a, int b)
{
	return a > b ? a : b;
}

/* 左单旋 */
static Position SingleRotateWithLeft(Position K2)
{
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	
	return K1;
}

/* 右单旋 */
static Position SingleRotateWithRight(Position K2)
{
	Position K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	
	return K1;
}

static Position DoubleRotateWithLeft(Position K1)
{
	Position K3 = K1->Left;
	Position K2 = K3->Right;

	K1->Left = K2->Left;
	K3->Right = K2->Right;

	K2->Left = K3;
	K2->Right = K1;

	return K2;
}

static Position DoubleRotateWithRight(Position K1)
{
	
	Position K3 = K1->Right;
	Position K2 = K3->Left;

	K1->Right = K2->Right;
	K3->Left = K2->Left;

	K2->Right = K3;
	K2->Left = K1;

	return K2;
}

AvlTree MakeEmpty(AvlTree T)
{
	if(T == NULL)
		return T;
	else 
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
		return T;
	}
}

Position Find(ElementType X, AvlTree T)
{
	if(T == NULL)
	{
		fprintf(stderr, "Not Find");
		return NULL;
	}
	else if(X > T->Element)
		return Find(X, T->Right);
	else if(X < T->Element)
		return Find(X, T->Left);
	else 
		return T;
}

Position FindMin(AvlTree T)
{
	if(T == NULL)
		return T;
	Position TmpCell = T;
	while(TmpCell->Left != NULL)
		TmpCell = TmpCell->Left;

	return TmpCell;
}

Position FindMax(AvlTree T)
{
	if(T == NULL)
		return T;
	Position TmpCell = T;
	while(TmpCell->Right != NULL)
		TmpCell = TmpCell->Right;

	return TmpCell;
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if(T == NULL)
	{
		T = malloc(sizeof(struct AvlNode));
		if(T == NULL)
			fprintf(stderr, "Out of space!!!");
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if(X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if(Height(T->Left) - Height(T->Right) == 2)
		{
			if(X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if(X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if(Height(T->Right) - Height(T->Left) == 2)
		{
			if(X > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

AvlTree Delete(ElementType X, AvlTree T)
{
	if(T == NULL)
	{
		return NULL;
	}
	else if(X < T->Element)
	{
		T->Left = Delete(X, T->Left);
		if(Height(T->Right) - Height(T->Left) == 2)
		{
			if(X > T->Right->Element)
				T = SingleRotateWithRight(T);
			else 
				T = DoubleRotateWithRight(T);
		}
	}
	else if(X > T->Element)
	{
		T->Right = Delete(X, T->Right);
		if(Height(T->Left) - Height(T->Right) == 2)
		{
			if(X > T->Left->Element)
				T = SingleRotateWithLeft(T);
			else 
				T = DoubleRotateWithLeft(T);
		}
	}
	else
	{
		if(T->Left == NULL || T->Right == NULL)
		{
			Position TmpCell = T;
			if(T->Left != NULL)
			{
				T = T->Left;
			}
			else if(T->Right != NULL)
			{
				T = T->Right;
				T->Height--;
			}
			else 
			{
				T = NULL;
			}
			free(TmpCell);
			UpdateHeight(T);
		}
		else 
		{
			Position TmpCell = FindMin(T->Right);
			T->Element = TmpCell->Element;
			Delete(TmpCell->Element, TmpCell);
		}
	}

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1`;
	return T;
}

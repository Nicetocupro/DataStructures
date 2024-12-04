#include "list.h"

typedef struct Node
{
	ElementType Element;
	Position Next;
} Node;

/* 清除整个表的内容 */
List MakeEmpty(List L)
{
	Position P = L->Next, tmp = NULL;
	while(P != NULL)
	{
		tmp = P;
		P = P->Next;
		free(tmp);
	}

	return L;
}

/* Retrun true if L is empty */
int IsEmpty(List L)
{
	return L->Next == NULL;
}

/* 测试当前位置是否是最后一个元素 */
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

/* 返回 X 在 L 中的Node单元 */
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while(P != NULL && P->Element != X)
	{
		P = P->Next;
	}

	return P;
}

/* 删除元素 */
void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);

	if(!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

/* 寻找元素X的前驱节点 */
Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while(P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}

	return P;
}

/* 插入元素 */
void insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = (Node *)malloc(sizeof(Node));

	if(TmpCell == NULL)
	{
		printf("Out of space!!!\n");
		exit(1);
	}

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

/* 删除整个表 */
void DeleteList(List L)
{
	Position P = L, tmp = NULL;

	while(P != NULL)
	{
		tmp = P;
		P = P->Next;
		free(tmp);
	}
}

/* 返回头节点 */
Position Header(List L)
{
	return L;
}

/* 返回第一个节点 */
Position First(List L)
{
	return L->Next;
}

/* 返回下一个节点 */
Position Advance(Position P)
{
	return P->Next;
}

/* 返回节点的值 */
ElementType Retrieve(Position P)
{
	return P->Element;
}

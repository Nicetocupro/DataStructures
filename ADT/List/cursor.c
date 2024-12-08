#include "cursor.h"

struct Node 
{
	ElementType Element;
	Position Next;
} Node;

struct Node CursorSpace[SpaceSize];

void InitializeCursorSpace(void)
{
	for(int i = 0; i < SpaceSize; i++)
	{
		CursorSpace[i].Next = i + 1;
	}

	CursorSpace[SpaceSize - 1].Next = 0;
}

static Position CursorAlloc(void)
{
	Position P;

	P = CursorSpace[0].Next;

	if(P == 0)
	{
		fprintf(stderr, "Out of space!!!\n");
	}
	
	CursorSpace[0].Next = CursorSpace[P].Next;

	return P;
}

static void CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}

/* 将链表置空 */
List MakeEmpty(List L)
{
	InitializeCursorSpace();
	return L;
}

/* Return true if L is empty */
int IsEmpty(List L)
{
	return CursorSpace[L].Next == 0;
}

/* Return true if P is the last position in list L */
int IsLast(Position P, List L)
{
	return CursorSpace[P].Next == 0;
}

/* Return Position of X in L; 0 if not found */
Position Find(ElementType X, List L)
{
	Position P;
	P = CursorSpace[L].Next;
	while(P && CursorSpace[P].Element != X)
		P = CursorSpace[P].Next;

	return P;
}

/* Delete first occurrence of X from a list */
void Delete(ElementType X, List L)
{
	Position P, TmpCell;
	
	P = FindPrevious(X, L);

	if(!IsLast(P, L))
	{
		TmpCell = CursorSpace[P].Next;
		CursorSpace[P].Next = CursorSpace[TmpCell].Next;
		CursorFree(TmpCell);
	}
}

/* Insert(after legal position P) */
void insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = CursorAlloc();

	CursorSpace[TmpCell].Element = X;
	CursorSpace[TmpCell].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = TmpCell;
}

/* 删除整个表 */
void DeleteList(List L)
{
	Position P, TmpCell;

	P = CursorSpace[L].Next;
	while(P)
	{
		TmpCell = CursorSpace[P].Next;
		CursorFree(P);
		P = TmpCell;
	}
}

/* 头节点 */
Position Header(const List L)
{
	return L;
}

/* 首个有效节点 */
Position First(const List L)
{
	return CursorSpace[L].Next;
}

/* 下一个节点 */
Position Advance(const Position P)
{
	return CursorSpace[P].Next;
}

/* 返回节点值 */
ElementType Retrieve(const Position P)
{
	return CursorSpace[P].Element;
}

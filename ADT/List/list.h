#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#ifndef _List_H 
/*
	如果没有定义_List_H 宏,那么执行后面的代码
	ifndef == if not defined
	这是为了避免C或C++中防止头文件重复包含的预处理指令，称为头文件保护
 */

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif 

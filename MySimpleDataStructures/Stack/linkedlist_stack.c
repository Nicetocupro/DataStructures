#include<stdio.h>
#include<stdlib.h>
#include<climits>


// 链表节点结构体
typedef struct ListNode{
	int val;
	struct ListNode *next;
} ListNode;

// 基于链表实现的栈
typedef struct{
	ListNode *top;
	int size;
} LinkedListStack;

/* 构造函数 */
LinkedListStack *newLinkedListStack()
{
	LinkedListStack *s = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	s->top = NULL;
	s->size = 0;
	return s;
}

/* 析构函数 */
void delLinkedListStack(LinkedListStack *s)
{
	while(s->top)
	{
		ListNode *n = s->top->next;
		free(s->top);
		s->top = n;
	}
	free(s);
}

/* 获取栈的长度 */
int size(LinkedListStack *s)
{
	return s->size;
}

/* 判断是否为空 */
bool isEmpty(LinkedListStack *s)
{
	return size(s) == 0;
}

/* 入栈 */
void push(LinkedListStack *s, int num)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	
	// 更新新加节点指针域
	node->next = s->top;

	// 更新新加节点的数据域
	node->val = num;

	// 更新栈顶
	s->top = node;

	// 更新栈的大小
	s->size++;
}

/* 访问栈顶元素 */
int peek(LinkedListStack *s)
{
	if(s->size == 0)
	{
		printf("栈为空\n");
		return INT_MAX;
	}

	return s->top->val;
}

/* 出栈 */
int pop(LinkedListStack *s)
{
	int val = peek(s);
	ListNode *tmp = s->top;
	s->top = s->top->next;

	free(tmp);
	s->size--;
	return val;
}







#include<stdio.h>
#include<stdlib.h>

// 链表节点结构体 
typedef struct ListNode{
	int val;
	struct ListNode *next;
} ListNode;

// 构造函数
ListNode *newListNode(int val)
{
	ListNode *node;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->val = val;
	node->next = NULL;
	return node;
}

// 打印链表
void printLinkedList(ListNode* n0)
{
	ListNode* p = n0;
	int i = 0;
	while(1)
	{
		if(p == NULL)
		{
			break;
		}
		printf("输出链表的第%d个元素:%d\n", i, p->val);
		p = p->next;
		i++;
	}
	printf("\n");
}

// 在链表节点n0之后插入节点p
void insert(ListNode *n0, ListNode *p)
{
	ListNode *n1 = n0->next;
	p->next = n1;
	n0->next = p;
}

// 删除链表的节点 n0 之后的首个节点p
// remove被stdio.h占用了关键词
void removeItem(ListNode *n0)
{
	if(!n0->next)
	{
		return;
	}

	ListNode *p = n0->next;
	ListNode *n1 = p->next;
	
	n0->next = n1;

	// 释放内存
	free(p);
}

// 访问链表中的索引为 index 的节点
ListNode *access(ListNode *head, int index)
{
	printf("这里是access");
	for(int i = 0; i < index; i++)
	{
		if(head == NULL)
		{
			return NULL;
		}
		head = head->next;
	}

	return head;
}

// 在链表中查找值为 target 的首个节点
int find(ListNode *head, int target)
{
	int index = 0;
	while(head)
	{
		if(head->val == target)
		{
			return index;
		}
		head = head->next;
		index++;
	}
	return -1;
}

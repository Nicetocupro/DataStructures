#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<cassert>
#include"../Linked_list/linked_list.c"

/* 基于链表实现的队列 */
typedef struct{
	ListNode *front, *rear;
	int queSize;
} LinkedListQueue;

/* 构造函数 */
LinkedListQueue *newLinkedListQueue()
{
	LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->queSize = 0;
	return queue;
}

/* 析构函数 */
void delLinkedListQueue(LinkedListQueue *queue)
{
	// 释放所有节点
	while(queue->front != NULL)
	{
		ListNode *tmp = queue->front;
		queue->front = tmp->next;
		free(tmp);
	}

	// 释放 queue 结构体
	free(queue);
}

/* 获取队列长度 */
int size(LinkedListQueue *queue)
{
	return queue->queSize;
}

/* 判断队列是否为空 */
bool empty(LinkedListQueue *queue)
{
	return size(queue) == 0;
}

/* 入队 */
void push(LinkedListQueue *queue, int num)
{
	// 尾部点处添加node
	ListNode *node = newListNode(num);

	// 如果队列为空，则令头\尾点都指向该节点
	if(empty(queue))
	{
		queue->front = node;
		queue->rear = node;
	}
	else
	{
		queue->rear->next = node;
		queue->rear = node;
	}
	queue->queSize++;
}

/* 访问队首元素 */
int peak(LinkedListQueue *queue)
{
	assert(size(queue) && queue->front);
	return queue->front->val;
}

/* 出队 */
int pop(LinkedListQueue *queue)
{
	int num = peak(queue);
	ListNode *tmp = queue->front;
	queue->front = queue->front->next;
	free(tmp);
	queue->queSize--;
	return num;
}

void printLinkedListQueue(LinkedListQueue *queue)
{
	ListNode *tmp = queue->front;
	int i = 1;
	while(tmp)
	{
		printf("这是队列的第%d个元素:%d\n", i, tmp->val);
		tmp = tmp->next;
		i++;
	}
}
 











#include<stdio.h>
#include<stdlib.h>
#include<cassert>


/* 双向链表节点 */
typedef struct DoublyListNode{
	int val;
	struct DoublyListNode *next;
	struct DoublyListNode *prev;
} DoublyListNode;

/* 构造函数 */
DoublyListNode *newDoublyListNode(int num)
{
	DoublyListNode *node = (DoublyListNode*)malloc(sizeof(DoublyListNode));
	node->val = num;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/* 析构函数 */
void delDoublyListNode(DoublyListNode *node)
{
	free(node);
}

/* 基于双向链表实现的双向队列 */
typedef struct{
	DoublyListNode *front, *rear;
	int queSize;
} LinkedListDeque;

/* 构造函数 */
LinkedListDeque *newLinkedListDeque()
{
	LinkedListDeque *deque = (LinkedListDeque *)malloc(sizeof(LinkedListDeque));
	deque->front = NULL;
	deque->rear = NULL;
	deque->queSize = 0;
	return deque;
}

/* 析构函数 */
void delLinkedListDeque(LinkedListDeque *deque)
{
	// 释放所有节点
	for(int i = 0; i < deque->queSize && deque->front != NULL; i++)
	{
		DoublyListNode *tmp = deque->front;
		deque->front = tmp->next;
		free(tmp);
	}

	// 释放deque
	free(deque);
}

/* 获取队列长度 */
int size(LinkedListDeque *deque)
{
	return deque->queSize;
}

/* 判断队列是否为空 */
bool empty(LinkedListDeque *deque)
{
	return deque->queSize == 0;
}

/* 入队 */
void push(LinkedListDeque *deque, int num, bool isFront)
{
	DoublyListNode *node = newDoublyListNode(num);

	// 若链表为空，则front, rear都指向node
	if(empty(deque))
	{
		deque->front = node;
		deque->rear = node;
	}
	else if(isFront)
	{
		deque->front->prev = node;
		node->next = deque->front;
		deque->front = node;
	}
	else
	{
		deque->rear->next = node;
		node->prev = deque->rear;
		deque->rear = node;
	}

	deque->queSize++;
}

/* 队首入队 */
void pushFirst(LinkedListDeque *deque, int num)
{
	push(deque, num, true);
}

/* 队尾入队 */
void pushLast(LinkedListDeque *deque, int num)
{
	push(deque, num, false);
}

/* 访问队首元素 */
int peekFirst(LinkedListDeque *deque)
{
	assert(size(deque) && deque->front);
	return deque->front->val;
}

/* 访问队尾元素 */
int peekLast(LinkedListDeque *deque)
{
	assert(size(deque) && deque->rear);
	return deque->rear->val;
}

/* 出队 */
int pop(LinkedListDeque *deque, bool isFront)
{
	if(empty(deque))
	{
		return -1;
	}

	int val;
	if(isFront)
	{
		val = peekFirst(deque);
		DoublyListNode *fNext = deque->front->next;
		if(fNext)
		{
			fNext->prev = NULL;
			deque->front->next = NULL;
		}
		delDoublyListNode(deque->front);
		deque->front = fNext;
	}
	else 
	{
		val = peekLast(deque);
		DoublyListNode *rPrev = deque->rear->prev;
		if(rPrev)
		{
			rPrev->next = NULL;
			deque->rear->prev = NULL;
		}
		delDoublyListNode(deque->rear);
		deque->rear = rPrev;
	}
	deque->queSize--;
	return val; 
}

/* 队首出队 */
int popFirst(LinkedListDeque *deque)
{
	return pop(deque, true);
}

/* 队尾出队 */
int popLast(LinkedListDeque *deque)
{
	return pop(deque, false);
}

/* 打印队列 */
void printLinkedListDeque(LinkedListDeque *deque, bool isFront)
{
	if(isFront)
	{
		DoublyListNode *node = deque->front;
		printf("从队首开始打印\n");

		for(int i = 0; i < deque->queSize; i++)
		{
			if(node == NULL)
			{
				break;
			}
			printf("队列deque[%d] = %d\n", i, node->val);
			node = node->next;
		}
	}
	else
	{
		DoublyListNode *node = deque->rear;
		printf("从队尾开始打印\n");
		for(int i = 0 ; i < deque->queSize; i++)
		{
			if(node == NULL)
			{
				break;
			}
			printf("队列deque[%d] = %d\n", i, node->val);
			node = node->prev;
		}
	}
}

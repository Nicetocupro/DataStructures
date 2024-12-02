#include<stdio.h>
#include<stdlib.h>
#include<cassert>


typedef struct{
	int *nums;
	int front;
	int queSize;
	int queCapacity;
} ArrayDeque;

/* 构造函数 */
ArrayDeque *newArrayDeque(int capacity)
{
	ArrayDeque *deque = (ArrayDeque *)malloc(sizeof(ArrayDeque));

	// 初始化数组 
	deque->queCapacity = capacity;
	deque->nums = (int *)malloc(sizeof(int) * deque->queCapacity);
	deque->front = deque->queSize = 0;

	return deque;
}

/* 析构函数 */
void delArrayDeque(ArrayDeque *deque)
{
	free(deque->nums);
	free(deque);
}

/* 获取队列的容量 */
int capacity(ArrayDeque *deque)
{
	return deque->queCapacity;
}

/* 获取队列的长度 */
int size(ArrayDeque *deque)
{
	return deque->queSize;
}

/* 判断队列是否为空 */
bool empty(ArrayDeque *deque)
{
	return deque->queSize == 0;
}

/* 计算环形数组索引 */
int dequeIndex(ArrayDeque *deque, int i)
{
	return (i + capacity(deque)) % capacity(deque);
}

/* 访问队首元素 */
int peekFirst(ArrayDeque *deque)
{
	assert(!empty(deque));
	int front = dequeIndex(deque, deque->front);
	return deque->nums[front];
}

/* 访问队尾元素 */
int peekLast(ArrayDeque *deque)
{
	assert(!empty(deque));
	int rear = dequeIndex(deque, deque->front + deque->queSize - 1);
	return deque->nums[rear];
}

/* 队首入队 */
void pushFirst(ArrayDeque *deque, int num)
{
	if(size(deque) == capacity(deque))
	{
		printf("队列已经满了\n");
		return;
	}
	// 计算队首指针
	// 通过取余操作实现 rear 越过数组尾部后回到头部 
	if(deque->queSize != 0)
	{
		deque->front = dequeIndex(deque, deque->front - 1);
	}

	deque->nums[deque->front] = num;
	deque->queSize++;
}

/* 队尾入队 */
void pushLast(ArrayDeque *deque, int num)
{
	if(size(deque) == capacity(deque))
	{
		printf("队列已经满了\n");
		return;
	}

	// 计算队尾指针
	// 通过取余操作实现 rear 越过数组尾部后回到头部 
	int rear  = dequeIndex(deque, deque->front + deque->queSize);

	deque->nums[rear] = num;
	deque->queSize++;
}

/* 队首出队 */
int popFirst(ArrayDeque *deque)
{
	int num = peekFirst(deque);
	//队首指针向前移动一位，若越过尾部，则返回到数组头部
	deque->front = dequeIndex(deque, deque->front + 1);
	deque->queSize--;

	return num;
}

/* 队尾出队 */
int popLast(ArrayDeque *deque)
{
	int num = peekLast(deque);
	deque->queSize--;

	return num;
}

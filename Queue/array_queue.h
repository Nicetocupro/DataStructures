#include<stdio.h>
#include<stdlib.h>
#include<cassert>


typedef struct{
	int *nums;
	int front;
	int queSize;
	int queCapacity;
} ArrayQueue;

/* 构造函数 */
ArrayQueue *newArrayQueue(int capacity)
{
	ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));

	// 初始化数组 
	queue->queCapacity = capacity;
	queue->nums = (int *)malloc(sizeof(int) * queue->queCapacity);
	queue->front = queue->queSize = 0;

	return queue;
}

/* 析构函数 */
void delArrayQueue(ArrayQueue *queue)
{
	free(queue->nums);
	free(queue);
}

/* 获取队列的容量 */
int capacity(ArrayQueue *queue)
{
	return queue->queCapacity;
}

/* 获取队列的长度 */
int size(ArrayQueue *queue)
{
	return queue->queSize;
}

/* 判断队列是否为空 */
int empty(ArrayQueue *queue)
{
	return queue->queSize == 0;
}

/* 访问队首元素 */
int peek(ArrayQueue *queue)
{
	assert(!empty(queue));
	return queue->nums[queue->front];
}

/* 入队 */
void push(ArrayQueue *queue, int num)
{
	if(size(queue) == capacity(queue))
	{
		printf("队列已经满了\n");
		return;
	}

	// 计算队尾指针
	// 通过取余操作实现 rear 越过数组尾部后回到头部 
	int rear = (queue->front + queue->queSize) % queue->queCapacity;

	queue->nums[rear] = num;
	queue->queSize++;
}

/* 出队 */
int pop(ArrayQueue *queue)
{
	int num = peek(queue);
	//队首指针向前移动一位，若越过尾部，则返回到数组头部
	queue->front = (queue->front + 1) % queue->queCapacity;
	queue->queSize--;

	return num;
}





























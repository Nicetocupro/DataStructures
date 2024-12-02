#include<stdio.h>
#include<climits>
#include<stdlib.h>
#define MAX_SIZE 100

/* 基于数组实现的栈 */
typedef struct{
	int *data;
	int size;
} ArrayStack;

/* 构造函数 */
ArrayStack *newArrayStack()
{
	ArrayStack *stack = (ArrayStack*)malloc(sizeof(ArrayStack));

	// 初始化一个大容量，避免扩容
	stack->data = (int*)malloc(sizeof(int) * MAX_SIZE);
	stack->size = 0;
	return stack;
}

/* 析构函数 */
void delArrayStack(ArrayStack *stack)
{
	free(stack->data);
	free(stack);
}

/* 获取栈的长度 */
int size(ArrayStack *stack)
{
	return stack->size;
}

/* 判断栈是否是空 */
bool isEmpty(ArrayStack *stack)
{
	return stack->size == 0;
}

/* 入栈 */
void push(ArrayStack *stack, int num)
{
	if(stack->size == MAX_SIZE)
	{
		printf("栈已满\n");
		return;
	}
	stack->data[stack->size] = num;
	stack->size++;
}

/* 访问栈顶元素 */
int peak(ArrayStack *stack)
{
	if(stack->size == 0)
	{
		printf("栈为空\n");
		return INT_MAX;
	}
	return stack->data[stack->size - 1];

}

/* 出栈 */
int pop(ArrayStack *stack)
{
	int val = peak(stack);
	stack->size--;
	return val;
}



#include<stdio.h>
#include<stdlib.h>
#include<cassert>
#include<climits>

typedef struct{
	int *data;		// 数组实现完全二叉树
	int capacity;	// 堆的容量
	int extendRatio;		// 堆扩张因子
	int size;		// 堆大小
	bool type;		// 堆的类型，1大堆还是0小堆
} Heap;

void extend(Heap *heap);

/* 构造函数 */
Heap *newHeap(bool type)
{
	Heap *heap = (Heap *)malloc(sizeof(Heap));
	
	if(heap == NULL)
	{
		printf("Heap init false\n");
		exit(1);
	}

	heap->capacity = 4;
	heap->extendRatio = 2;
	heap->size = 0;
	heap->type = type;
	heap->data = (int *)malloc(sizeof(int) * heap->capacity);

	if(heap->data == NULL)
	{
		printf("Heap data init false\n");
		exit(1);
	}
	
	return heap;
}

/* 析构函数 */
void delHeap(Heap *heap)
{
	free(heap->data);
	free(heap);
}

/* 获取容量 */
int capacity(Heap *heap)
{
	return heap->capacity;
}

/* 获取大小 */
int size(Heap *heap)
{
	return heap->size;
}

/* 判空处理 */
bool isEmpty(Heap *heap)
{
	return size(heap) == 0;
}

/* 获取类型 */
const char* type(Heap *heap)
{
	return type ? "大顶堆" : "小顶堆";
}

/* 获取左子节点的索引 */
int left(int i)
{
	return 2 * i + 1;
}

/* 获取右子节点的索引 */
int right(int i)
{
	return 2 * i + 2;
}

/* 获取父节点的索引 */
int parent(int i)
{
	return (i - 1) / 2;
}

/* 访问堆顶元素 */
int peak(Heap *heap)
{
	return heap->data[0];
}

/* Heap交换两元素 */
void swap(Heap *heap, int i, int j)
{
	int tmp = heap->data[i];
	heap->data[i] = heap->data[j];
	heap->data[j] = tmp;
}

/* 从节点 i 开始，从底至顶堆化 */
void siftUp(Heap *heap, int i)
{
	while(true)
	{
		// 获取节点i的坐标
		int p = parent(i);

		// 当越过根节点 或 节点无须修复的时候，结束

		if(heap->type)
		{
			if(p < 0 || heap->data[i] <= heap->data[p])
			{
				break;
			}
		}
		else 
		{
			if(p < 0 || heap->data[i] >= heap->data[p])
			{
				break;
			}
		}

		swap(heap, i , p);
		
		// 循环向上
		i = p;
	}
}

/* 从节点 i 开始，从顶至底堆化 */
void siftDown(Heap *heap, int i)
{
	while(true)
	{
		// 判断节点 i,l,r中值的最大或最小
		int l = left(i);
		int r = right(i);

		if(heap->type)
		{
			int max = i;
			
			if(l < size(heap) && heap->data[l] > heap->data[max])
			{
				max = l;
			}

			if(r < size(heap) && heap->data[r] > heap->data[max])
			{
				max = r;
			}

			if(max == i)
			{
				break;
			}

			// 交换两个节点
			swap(heap, i , max);

			// 向下继续堆化
			i = max;
		}
		else 
		{	
			int min = i;

			if(l < size(heap) && heap->data[l] < heap->data[min])
			{
				min = l;
			}

			if(r < size(heap) && heap->data[r] < heap->data[min])
			{
				min = r;
			}

			if(min == i)
			{
				break;
			}

			// 交换两个节点
			swap(heap, i , min);

			// 向下继续堆化
			i = min;
		}	
	}
}

/* 元素入堆 */
void push(Heap *heap, int val)
{
	// 默认情况下，不应该添加这么多节点
	if(size(heap) == capacity(heap))
	{
		extend(heap);
	}

	// 添加节点
	heap->data[heap->size] = val;
	heap->size++;

	// 从底至顶堆化
	siftUp(heap, heap->size - 1);
}

/* 元素出堆 */
int pop(Heap *heap)
{
	// 判空处理
	if(isEmpty(heap))
	{
		printf("heap is empty\n");
		return INT_MAX;
	}

	// 交换根节点与最右叶节点
	swap(heap, 0 , size(heap) - 1);
	
	// 删除节点
	int val = heap->data[heap->size - 1];
	heap->size--;

	// 从顶至底堆化 
	siftDown(heap, 0);

	return val;
}

/* 扩充容量 */
void extend(Heap *heap)
{
	// 容量扩充
	heap->capacity *= heap->extendRatio;
	
	// 重新 realloc 分配大小
	heap->data = (int *)realloc(heap->data, heap->capacity * sizeof(int));

	if(heap->data == NULL)
	{
		printf("Heap extend false\n");
		exit(1);
	}
}

Heap *ChangeType(Heap *heap)
{
	heap->type = !heap->type;
	
	int OldSize = heap->size;
	heap->size = 0;

	int *newData = (int *)malloc(sizeof(int) * heap->capacity);
	int *oldData = heap->data;
	heap->data = newData;

	for(int i = 0; i < OldSize ; i++)
	{
		push(heap, oldData[i]);
	}
	
	free(oldData);

	return heap;
}


#include<stdio.h>
#include<stdlib.h>
#include<cassert>

typedef struct{
	int *arr;			// 数组（存储列表元素）
	int capacity;		// 列表容量
	int size;			// 列表大小
	int extendRatio;	// 列表每次扩容的倍数
} MyList;

void extendCapacity(MyList *nums);

/* 构造函数 */
MyList *newMyList()
{
	MyList *nums = (MyList*)malloc(sizeof(MyList));
	nums->capacity = 10;
	nums->arr = (int*)malloc(sizeof(int) * nums->capacity);
	nums->size = 0;
	nums->extendRatio = 2;
	return nums;
}

/* 析构函数 */
void delMyList(MyList *nums)
{
	free(nums->arr);
	free(nums);
}

/* 获取列表长度 */
int size(MyList *nums)
{
	return nums->size;
}

/* 获取列表容量 */
int capacity(MyList *nums)
{
	return nums->capacity;
}

/* 访问元素 */
int get(MyList *nums, int index)
{
	assert(index >= 0 && index < nums->size);
	return nums->arr[index];
}

/* 更新元素 */
void set(MyList *nums, int index, int num)
{
	assert(index >= 0 && index < nums->size);
	nums->arr[index] = num;
}

/* 尾部添加元素 */
void add(MyList *nums, int num)
{
	if(size(nums) == capacity(nums))
	{
		// 扩容
		extendCapacity(nums);
	}

	nums->arr[size(nums)] = num;
	nums->size++;
}

// 在index处插入某个值
void insert(MyList *nums, int index, int num)
{
	assert(index >= 0 && index < size(nums));

	// 元素数据超出容量时，触发扩容机制
	if(size(nums) == capacity(nums))
	{
		extendCapacity(nums);
	}

	for(int i = size(nums); i > index; i--)
	{
		nums->arr[i] = nums->arr[i - 1];
	}

	nums->arr[index] = num;
	nums->size++;
}

// 移除在index处的值
int removeItem(MyList *nums, int index)
{
	assert(index >= 0 && index < size(nums));

	int num = nums->arr[index];

	for(int i = index; i < size(nums) - 1; i++)
	{
		nums->arr[i] = nums->arr[i + 1];
	}

	nums->size--;
	return num;
}

// 列表扩容
void extendCapacity(MyList *nums)
{
	// 先分配空间
	int newCapacity = capacity(nums) * nums->extendRatio;
	int *extend = (int *)malloc(sizeof(int) * newCapacity);
	int *temp = nums->arr;

	// 拷贝旧数据到新数据
	for(int i = 0; i < size(nums); i++)
	{
		extend[i] = nums->arr[i];
	}

	// 释放旧数据
	free(temp);

	// 更新新数据
	nums->arr = extend;
	nums->capacity = newCapacity;
}

/* 将列表转换为Array用于打印 */
int *toArray(MyList *nums)
{
	return nums->arr;
}

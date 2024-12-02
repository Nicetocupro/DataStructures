#include<stdio.h>
#include<random> // random库函数里面包含了stdlib.h，因此不需要再为malloc引入stdlib.h

// 遍历数组，打印数组中各元素
void printNums(int *nums, int size)
{
	for(int i = 0; i < size ; i++)
	{
		printf("nums[%d]:%d\n", i, nums[i]);
	}
}

// 随机访问数组元素
int randomAccess(int *nums, int size)
{
	// 在区间[0, size] 中随机抽取一个数字
	int randomIndex = rand() % size;
	int randomNum = nums[randomIndex];
	return randomIndex;
}

// 在数组的索引 index 处插入元素 num 
void insert(int *nums, int size, int num, int index)
{
	// 会抛弃最尾部的元素
	printf("被抛弃的最尾部元素：%d\n", nums[size - 1]);

	// 把索引 index 以及之后的元素向后移动一位
	for(int i = size ; i > index ; i--)
	{
		nums[i] = nums[i - 1];
	}

	// 将 num 赋值给 nums[index]
	nums[index] = num;
}

// 删除索引 index 处的元素
void removeItem(int *nums, int size, int index)
{
	// 把索引 index 之后的元素向前移动
	for(int i = index; i < size - 1; i++)
	{
		nums[i] = nums[i + 1];
	}
}

// 在数组中查找指定的元素(线性查找)
int find(int *nums, int size, int target)
{
	for(int i = 0 ; i < size ; i++)
	{
		if(nums[i] == target)
		{
			return i;
		}
	}
	return -1;
}

// 扩展数组长度
int *extend(int *nums, int size, int enlarge)
{
	// 初始化一个扩展长度后的数组
	int *res = (int *)malloc(sizeof(int) * (size + enlarge));

	// 将原数组中的所有元素复制
	for(int i = 0; i < size; i++)
	{
		res[i] = nums[i];
	}
	// 初始化扩展厚的空间
	for(int i = size; i < size + enlarge; i++)
	{
		res[i] = 0;
	}

	return res;
}

#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<cstring>

/* 数组表示下的二叉树结构体 */
typedef struct{
	int *tree;
	int size;
} ArrayBinaryTree;

/* 构造函数 */
ArrayBinaryTree *newArrayBinaryTree(int *arr, int arrSize)
{
	ArrayBinaryTree *abt = (ArrayBinaryTree *)malloc(sizeof(ArrayBinaryTree));

	abt->tree = (int*)malloc(sizeof(int) * arrSize);
	memcpy(abt->tree, arr, sizeof(int) * arrSize);
	abt->size = arrSize;
	return abt;
}

/* 析构函数 */
void delArrayBinaryTree(ArrayBinaryTree *abt)
{
	free(abt->tree);
	free(abt);
}

/* 列表容量 */
int size(ArrayBinaryTree *abt)
{
	return abt->size;
}

/* 获取索引为 i 的节点值 */
int val(ArrayBinaryTree *abt, int i)
{
	// 如果越界，则返回INT_MAX, 代表空位
	if(i < 0 || i >= size(abt))
	{
		return INT_MAX;
	}

	return abt->tree[i];
}

/* 层序遍历 */
int *levelOrder(ArrayBinaryTree *abt, int *returnSize)
{
	int *res = (int*)malloc(sizeof(int) * size(abt));
	int index = 0;

	// 直接遍历数组
	for(int i = 0; i < size(abt); i++)
	{
		if(val(abt, i) != INT_MAX)
		{
			res[index++] = val(abt, i);
		}
	}

	*returnSize = index;
	return res;
}

/* 深度优先遍历 */
void dfs(ArrayBinaryTree *abt, int i, char *order, int *res, int *index)
{
	// 若为空位则返回
	if(val(abt, i) == INT_MAX)
		return;

	// 前
	if(strcmp(order, "pre") == 0)
	{
		res[(*index)++] = val(abt, i);
	}
	dfs(abt, 2 * i + 1 , order, res, index);

	// 中
	if(strcmp(order, "in") == 0)
	{
		res[(*index)++] = val(abt, i);
	}
	dfs(abt, 2 * i + 2, order, res, index);
	// 后
	if(strcmp(order, "post") == 0)
	{
		res[(*index)++] = val(abt, i);
	}
}

/* 前序遍历 */
int *preOrder(ArrayBinaryTree *abt, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * size(abt));
	int index = 0;
	dfs(abt, 0 , "pre", res, &index);
	*returnSize = index;
	return res;
}

/* 中序遍历 */
int *inOrder(ArrayBinaryTree *abt, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * size(abt));
	int index = 0;
	dfs(abt, 0 , "in", res, &index);
	*returnSize = index;
	return res;
}

/* 后序遍历 */
int *postOrder(ArrayBinaryTree *abt, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * size(abt));
	int index = 0;
	dfs(abt, 0 , "post", res, &index);
	*returnSize = index;
	return res;
}

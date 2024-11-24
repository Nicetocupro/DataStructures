#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

/* 二叉树节点结构体 */
typedef struct TreeNode{
	int val;				// 节点值
	struct TreeNode *left;	// 左子节点指针
	struct TreeNode *right;	// 右子节点指针
}TreeNode;

/* 构造函数 */
TreeNode *newTreeNode(int val)
{
	TreeNode *node;

	node = (TreeNode *)malloc(sizeof(TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

/* 析构函数 */
void delTreeNode(TreeNode *root)
{
	if(root == NULL)
	{
		return;
	}
	delTreeNode(root->left);
	delTreeNode(root->right);
	free(root);
	return;
}

/* 层序遍历(广度优先) */
int *levelOrder(TreeNode *root, int *size)
{
	/* 辅助队列 */
	int front, rear;
	int index, *arr;
	TreeNode *node;
	TreeNode **queue;

	/* 辅助队列 */
	queue = (TreeNode**)malloc(sizeof(TreeNode *) * MAX_SIZE);
	
	// 队列指针
	front = 0;
	rear = 0;
	
	//加入根节点
	queue[rear++] = root;

	/* 初始化一个列表，用于保存遍历序列 */
	/* 辅助数组 */
	arr = (int *)malloc(sizeof(int) * MAX_SIZE);

	index = 0;
	while(front < rear)
	{
		// 队列出列
		node = queue[front++];

		// 保存节点值
		arr[index++] = node->val;

		if(node->left != NULL)
		{
			queue[rear++] = node->left;
		}

		if(node->right != NULL)
		{
			queue[rear++] = node->right;
		}
	}
	// 更新数组长度的值
	*size = index;
	arr = (int*)realloc(arr, sizeof(int) * (*size));

	free(queue);

	return arr;
}

/* 前序遍历 */
int* preOrder(TreeNode *root, int *size, int *arr)
{
	if(root == NULL)
	{
		return arr;
	}

	// 访问优先级：根节点 -> 左子树 -> 右子树
	arr[(*size)++] = root->val;

	arr = preOrder(root->left, size, arr);
	arr = preOrder(root->right, size, arr);

	return arr;
}

/* 中序遍历 */
int* inOrder(TreeNode *root, int *size, int *arr)
{
	if(root == NULL)
	{
		return arr;
	}
	
	arr = inOrder(root->left, size, arr);
	arr[(*size)++] = root->val;
	arr = inOrder(root->right, size, arr);

	return arr;
}

/* 后序遍历 */
int* postOrder(TreeNode *root, int *size, int *arr)
{
	if(root == NULL)
	{
		return arr;
	}
	arr = postOrder(root->left, size, arr);
	arr = postOrder(root->right, size, arr);
	arr[(*size)++] = root->val;

	return arr;
}


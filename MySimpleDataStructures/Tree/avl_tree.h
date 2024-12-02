#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <cstring>

/* AVL 树节点结构体 */
typedef struct TreeNode{
	int val;
	int height;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

typedef struct{
	TreeNode *root;
} AVLTree;

/* node构造函数 */
TreeNode *newTreeNode(int val)
{
	TreeNode *node;

	node = (TreeNode *)malloc(sizeof(TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* node析构函数 */
void delTreeNode(TreeNode *node)
{
	if(node == NULL)
	{
		return;
	}
	delTreeNode(node->left);
	delTreeNode(node->right);
	printf("node = %d\n", node->val);
	free(node);
}

/* AVL构造函数 */
AVLTree *newAVLTree()
{
	AVLTree *tree = (AVLTree*)malloc(sizeof(AVLTree));
	tree->root = NULL;

	return tree;
}

/* AVL析构函数 */
void delAVLTree(AVLTree *tree)
{
	delTreeNode(tree->root);
	free(tree);
}

/* 获取节点高度 */
int height(TreeNode *node)
{
	// 空节点高度为-1，叶节点高度为 0
	if(node != NULL)
	{
		return node->height;
	}

	return -1;
}

/* 节点高度 */
void updateHeight(TreeNode *node)
{
	int lh = height(node->left);
	int rh = height(node->right);

	// 节点高度等于最高字数高度 + 1
	
	node->height = (lh > rh) ? lh + 1 : rh + 1;
}

/* 获取平衡因子 */
int balanceFactor(TreeNode *node)
{
	// 空节点平衡因子为0
	if(node == NULL)
	{
		return 0;
	}

	// 节点平衡因子 = 左子树高度 - 右子树高度
	return height(node->left) - height(node->right);
}

/* 右旋操作 */
TreeNode *rightRotate(TreeNode *node)
{
	TreeNode *child, *grandChild;
	child = node->left;
	grandChild = child->right;

	// 以child 为原点，将node向右旋转
	child->right = node;
	node->left = grandChild;

	// 更新节点高度
	updateHeight(node);
	updateHeight(child);

	return child;
}

/* 左旋操作 */
TreeNode *leftRotate(TreeNode *node)
{
	TreeNode *child, *grandChild;
	child = node->right;
	grandChild = node->left;

	// 以 child 为原点，将 node 向左旋转
	child->left = node;
	node->right = grandChild;

	// 更新节点高度 
	updateHeight(node);
	updateHeight(child);

	return child;
}

/* 执行旋转操作，使该子树重新回复平衡 */
TreeNode *rotate(TreeNode *node)
{
	// 获取节点 node 的平衡因子
	int bf = balanceFactor(node);

	// 左偏树
	if(bf > 1)
	{
		if(balanceFactor(node->left) < 0)
		{
			node->left = leftRotate(node->left);
		}
		
		return rightRotate(node);
	}
	
	// 右偏树
	if(bf < -1)
	{
		if(balanceFactor(node->right) > 0)
		{
			node->right = rightRotate(node->right);
		}

		return leftRotate(node);
	}

	// 平衡树，无需旋转，直接返回
	return node;
}

TreeNode *insertHelper(TreeNode *node, int val);
/* 插入节点 */
void insert(AVLTree *tree, int val)
{
	tree->root = insertHelper(tree->root, val);
}

/* 递归插入节点(辅助函数) */
TreeNode *insertHelper(TreeNode *node, int val)
{
	if(node == NULL)
	{
		return newTreeNode(val);
	}

	/* 查找插入位置并插入绩点 */
	if(val < node->val)
	{
		node->left = insertHelper(node->left, val);
	}
	else if(val > node->val)
	{
		node->right = insertHelper(node->right, val);
	}
	else
	{
		return node;
	}

	// 更新节点高度
	updateHeight(node);
	// 执行旋转操作，是该子树重新回复平衡
	node = rotate(node);
	// 返回子树根节点
	return node;
}

TreeNode *removeHelper(TreeNode *node, int val);
/* 删除节点 */
void removeItem(AVLTree *tree, int val)
{
	tree->root = removeHelper(tree->root, val);
}

/* 递归删除节点(辅助函数) */
TreeNode *removeHelper(TreeNode *node, int val)
{
	TreeNode *child, grandChild;
	if(node == NULL)
	{
		return NULL;
	}

	if(val < node->val)
	{
		node->left = removeHelper(node->left, val);
	}
	else if(val > node->val)
	{
		node->right = removeHelper(node->right, val);
	}
	else 
	{
		if(node->left == NULL || node->right == NULL)
		{
			TreeNode *temp = node;
			child = ((node->left == NULL) ? node->right : node->left);
			free(temp);

			if(child == NULL)
			{
				return NULL;
			}
			else 
			{
				node = child;
			}
		}
		else 
		{
			TreeNode *temp = node->right;
			while(temp->left != NULL)
			{
				temp = temp->left;
			}

			int tempVal = temp->val;
			node->right = removeHelper(node->right, temp->val);
			node->val = tempVal;
		}
	}

	updateHeight(node);

	node = rotate(node);

	return node;
}

/* 查找节点 */
TreeNode *search(AVLTree *tree, int num)
{
	TreeNode *cur = tree->root;

	// 循环查找，越过叶节点后跳出
	while(cur != NULL)
	{
		if(cur->val < num)
		{
			cur = cur->right;
		}
		else if(cur->val > num)
		{
			cur = cur->left;
		}
		else 
		{
			break;
		}
	}

	// 返回目标节点，如果是NULL，也会返回
	return cur;
}



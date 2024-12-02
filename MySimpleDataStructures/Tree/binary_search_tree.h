#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<cstring>

/* 二叉树节点定义 */
typedef struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
} TreeNode;

/* 二叉搜索树定义 */
typedef struct{
	TreeNode* root;
	int size;
} BinarySearchTree;

/* 二叉树节点构造函数 */
TreeNode* newTreeNode(int val)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/* 二叉树析构函数 */
void delTreeNode(TreeNode *root)
{
	if(root == NULL)
	{
		return;
	}

	delTreeNode(root->left);
	delTreeNode(root->right);
	free(root);
}

/* 二叉搜索树构造函数 */
BinarySearchTree* newBinarySearchTree()
{
	BinarySearchTree *bst = (BinarySearchTree *)malloc(sizeof(BinarySearchTree));

	bst->root = NULL;
	bst->size = 0;

	return bst;
}

/* 析构函数 */
void delBinarySearchTree(BinarySearchTree *bst)
{
	// 将节点首先删除
	delTreeNode(bst->root);

	// 删除二叉搜索树
	free(bst);
}

/* 查找节点 */
TreeNode *search(BinarySearchTree *bst, int num)
{
	TreeNode *cur = bst->root;

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

/* 插入节点 */
void insert(BinarySearchTree *bst, int num)
{
	// 若树为空，则初始化根节点
	if(bst->root == NULL)
	{
		bst->root = newTreeNode(num);
		bst->size++;
		return;
	}

	TreeNode *cur = bst->root;
	TreeNode *pre = NULL;

	// 循环查找，越过叶节点后跳出 
	while(cur != NULL)
	{
		// 找到重复节点，直接返回
		if(cur->val == num)
		{
			return;
		}
		pre = cur;

		if(cur->val < num)
		{
			// 插入位置在 cur 的右子树
			cur = cur->right;
		}
		else 
		{
			cur = cur->left;
		}
	}
	
	// 插入节点 
	TreeNode *node = newTreeNode(num);
	if(pre->val < num)
	{
		pre->right = node;
	}
	else
	{
		pre->left = node;
	}

	bst->size++;
}

/* 删除节点 */
void removeItem(BinarySearchTree *bst, int num)
{
	// 若树为空，直接返回
	if(bst->root == NULL)
	{
		return;
	}
	TreeNode *cur = bst->root;
	TreeNode *pre = NULL;

	// 循环查找，越过叶子节点后跳出 
	while(cur != NULL)
	{
		// 找到删除节点，跳出循环
		if(cur->val == num)
		{
			break;
		}
		pre = cur;
		if(cur->val < num)
		{
			cur = cur->right;
		}
		else
		{
			cur = cur->left;
		}
	}

	if(cur == NULL)
	{
		return;
	}

	// 判断待删除是否存在子节点
	if(cur->left == NULL || cur->right == NULL)
	{
		TreeNode *child = cur->left != NULL ? cur->left : cur->right;
		
		if(pre == NULL)
		{
			bst->root = child;
		}
		else 
		{
			// 删除节点cur
			if(pre->left == cur)
			{
				pre->left = child;
			}
			else 
			{
				pre->right = child;
			}
		}
		bst->size--;
	}
	else 
	{
		TreeNode *tmp = cur->right;
		while(tmp->left != NULL)
		{
			tmp = tmp->left;
		}

		int tmpVal = tmp->val;

		// 递归删除节点tmp;
		removeItem(bst, tmp->val);

		cur->val = tmpVal;
	}
}




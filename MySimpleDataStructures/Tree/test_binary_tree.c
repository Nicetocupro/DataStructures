#include "binary_tree.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// 检查数组内容是否与预期一致
void checkArray(int* arr, int size, int* expected, int expectedSize)
{
    assert(size == expectedSize);
    for (int i = 0; i < size; i++) {
        assert(arr[i] == expected[i]);
    }
}

// 打印数组（用于调试）
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size = 0;
    TreeNode *root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    root->right->left = newTreeNode(6);
    root->right->right = newTreeNode(7);

    // 前序遍历验证
    int *arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    size = 0;
    arr = preOrder(root, &size, arr);
    int expectedPreOrder[] = {1, 2, 4, 5, 3, 6, 7};
    checkArray(arr, size, expectedPreOrder, sizeof(expectedPreOrder) / sizeof(expectedPreOrder[0]));
    printf("PreOrder: ");
    printArray(arr, size);
    free(arr);

    // 中序遍历验证
    arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    size = 0;
    arr = inOrder(root, &size, arr);
    int expectedInOrder[] = {4, 2, 5, 1, 6, 3, 7};
    checkArray(arr, size, expectedInOrder, sizeof(expectedInOrder) / sizeof(expectedInOrder[0]));
    printf("InOrder: ");
    printArray(arr, size);
    free(arr);

    // 后序遍历验证
    arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    size = 0;
    arr = postOrder(root, &size, arr);
    int expectedPostOrder[] = {4, 5, 2, 6, 7, 3, 1};
    checkArray(arr, size, expectedPostOrder, sizeof(expectedPostOrder) / sizeof(expectedPostOrder[0]));
    printf("PostOrder: ");
    printArray(arr, size);
    free(arr);

    // 层序遍历验证
    size = 0;
    arr = levelOrder(root, &size);
    int expectedLevelOrder[] = {1, 2, 3, 4, 5, 6, 7};
    checkArray(arr, size, expectedLevelOrder, sizeof(expectedLevelOrder) / sizeof(expectedLevelOrder[0]));
    printf("LevelOrder: ");
    printArray(arr, size);
    free(arr);

    // 边界情况：空树
    root = NULL;
    arr = (int *)malloc(sizeof(int) * MAX_SIZE);

    size = 0;
    arr = preOrder(root, &size, arr);
    assert(size == 0);
    printf("PreOrder (empty tree): ");
    printArray(arr, size);
    free(arr);

    // 边界情况：只有一个节点的树
    root = newTreeNode(10);
    arr = (int *)malloc(sizeof(int) * MAX_SIZE);

    size = 0;
    arr = preOrder(root, &size, arr);
    int expectedSingleNode[] = {10};
    checkArray(arr, size, expectedSingleNode, sizeof(expectedSingleNode) / sizeof(expectedSingleNode[0]));
    printf("PreOrder (single node): ");
    printArray(arr, size);
    free(arr);

    // 清理内存
	printf("清理内存\n");
	delTreeNode(root);
	printf("Finish Success!");

    return 0;
}


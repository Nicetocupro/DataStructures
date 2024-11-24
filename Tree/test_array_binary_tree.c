#include "array_binary_tree.h"
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
    // 测试用例 1: 构造树并验证大小
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    ArrayBinaryTree *abt = newArrayBinaryTree(arr, sizeof(arr) / sizeof(arr[0]));

    assert(size(abt) == 7);  // 树大小应为7
    printf("Tree size: %d\n", size(abt));

    // 测试用例 2: 验证节点值
    assert(val(abt, 0) == 1);  // 根节点
    assert(val(abt, 1) == 2);  // 左子节点
    assert(val(abt, 2) == 3);  // 右子节点
    assert(val(abt, 10) == INT_MAX);  // 越界测试

    // 测试用例 3: 层序遍历
    int returnSize = 0;
    int *arrLevelOrder = levelOrder(abt, &returnSize);
    int expectedLevelOrder[] = {1, 2, 3, 4, 5, 6, 7};
    checkArray(arrLevelOrder, returnSize, expectedLevelOrder, sizeof(expectedLevelOrder) / sizeof(expectedLevelOrder[0]));
    printf("Level Order: ");
    printArray(arrLevelOrder, returnSize);
    free(arrLevelOrder);

    // 测试用例 4: 前序遍历
    int *arrPreOrder = preOrder(abt, &returnSize);
    int expectedPreOrder[] = {1, 2, 4, 5, 3, 6, 7};
    checkArray(arrPreOrder, returnSize, expectedPreOrder, sizeof(expectedPreOrder) / sizeof(expectedPreOrder[0]));
    printf("PreOrder: ");
    printArray(arrPreOrder, returnSize);
    free(arrPreOrder);

    // 测试用例 5: 中序遍历
    int *arrInOrder = inOrder(abt, &returnSize);
    int expectedInOrder[] = {4, 2, 5, 1, 6, 3, 7};
    checkArray(arrInOrder, returnSize, expectedInOrder, sizeof(expectedInOrder) / sizeof(expectedInOrder[0]));
    printf("InOrder: ");
    printArray(arrInOrder, returnSize);
    free(arrInOrder);

    // 测试用例 6: 后序遍历
    int *arrPostOrder = postOrder(abt, &returnSize);
    int expectedPostOrder[] = {4, 5, 2, 6, 7, 3, 1};
    checkArray(arrPostOrder, returnSize, expectedPostOrder, sizeof(expectedPostOrder) / sizeof(expectedPostOrder[0]));
    printf("PostOrder: ");
    printArray(arrPostOrder, returnSize);
    free(arrPostOrder);

    // 测试用例 7: 边界条件 - 空树
    ArrayBinaryTree *emptyTree = newArrayBinaryTree(NULL, 0);
    returnSize = 0;
    int *arrEmpty = levelOrder(emptyTree, &returnSize);
    assert(returnSize == 0);  // 空树应返回大小为0
    printf("LevelOrder (empty tree): ");
    printArray(arrEmpty, returnSize);
    free(arrEmpty);
    delArrayBinaryTree(emptyTree);

    // 测试用例 8: 边界条件 - 只有一个节点的树
    int singleNodeArr[] = {10};
    ArrayBinaryTree *singleNodeTree = newArrayBinaryTree(singleNodeArr, sizeof(singleNodeArr) / sizeof(singleNodeArr[0]));
    returnSize = 0;
    int *arrSingleNode = levelOrder(singleNodeTree, &returnSize);
    int expectedSingleNode[] = {10};
    checkArray(arrSingleNode, returnSize, expectedSingleNode, sizeof(expectedSingleNode) / sizeof(expectedSingleNode[0]));
    printf("LevelOrder (single node): ");
    printArray(arrSingleNode, returnSize);
    free(arrSingleNode);
    delArrayBinaryTree(singleNodeTree);

    // 测试用例 9: 边界条件 - 只包含空位的树
    int emptyNodeArr[] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    ArrayBinaryTree *emptyNodeTree = newArrayBinaryTree(emptyNodeArr, sizeof(emptyNodeArr) / sizeof(emptyNodeArr[0]));
    returnSize = 0;
    int *arrEmptyNode = levelOrder(emptyNodeTree, &returnSize);
    assert(returnSize == 0);  // 只包含空位的树应返回大小为0
    printf("LevelOrder (empty nodes): ");
    printArray(arrEmptyNode, returnSize);
    free(arrEmptyNode);
    delArrayBinaryTree(emptyNodeTree);

    // 测试用例 10: 析构树
    delArrayBinaryTree(abt);

    return 0;
}




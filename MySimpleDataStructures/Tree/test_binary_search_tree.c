#include "binary_search_tree.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// 检查树的大小
void checkSize(BinarySearchTree* bst, int expectedSize)
{
    printf("Expected size: %d, Actual size: %d\n", expectedSize, bst->size);
    assert(bst->size == expectedSize);
}

// 检查树中是否包含特定值
void checkSearch(BinarySearchTree* bst, int num, int expected)
{
    TreeNode* result = search(bst, num);
    if (expected == 1) {
        printf("Found node with value %d\n", num);
        assert(result != NULL && result->val == num);
    } else {
        printf("Node with value %d not found\n", num);
        assert(result == NULL);
    }
}

// 打印树中节点值（用于调试）
void printTree(TreeNode* root)
{
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}

int main()
{
    // 测试用例 1: 构造二叉搜索树
    BinarySearchTree *bst = newBinarySearchTree();
    assert(bst != NULL);
    checkSize(bst, 0);  // 空树的大小应为0
    printf("Tree constructed successfully.\n");

    // 测试用例 2: 插入节点
    insert(bst, 10);
    checkSize(bst, 1);  // 插入一个节点后，大小应为1
    checkSearch(bst, 10, 1);  // 查找节点 10
    printf("Inserted node with value 10.\n");

    insert(bst, 20);
    checkSize(bst, 2);  // 插入节点 20，大小应为2
    checkSearch(bst, 20, 1);  // 查找节点 20
    printf("Inserted node with value 20.\n");

    insert(bst, 5);
    checkSize(bst, 3);  // 插入节点 5，大小应为3
    checkSearch(bst, 5, 1);  // 查找节点 5
    printf("Inserted node with value 5.\n");

    insert(bst, 10);  // 重复插入 10，不应改变树
    checkSize(bst, 3);  // 树的大小应仍为3，因为 10 已存在
    printf("Attempted to insert duplicate node with value 10.\n");

    // 测试用例 3: 删除节点（删除叶子节点）
    removeItem(bst, 5);
    checkSize(bst, 2);  // 删除节点 5 后，大小应为2
    checkSearch(bst, 5, 0);  // 查找节点 5，应该返回 NULL
    printf("Deleted leaf node with value 5.\n");

    // 测试用例 4: 删除节点（删除有一个子节点的节点）
    insert(bst, 7);
    checkSize(bst, 3);  // 再次插入节点 7，大小应为3
    checkSearch(bst, 7, 1);  // 查找节点 7，应该返回该节点
    removeItem(bst, 7);  // 删除节点 7（它没有子节点）
    checkSize(bst, 2);  // 删除节点后，大小应为2
    checkSearch(bst, 7, 0);  // 查找节点 7，应该返回 NULL
    printf("Deleted node with value 7.\n");

    // 测试用例 5: 删除节点（删除有两个子节点的节点）
    insert(bst, 15);
    insert(bst, 25);
    checkSize(bst, 4);  // 树的大小应为4
    checkSearch(bst, 15, 1);  // 查找节点 15
    checkSearch(bst, 25, 1);  // 查找节点 25
    removeItem(bst, 20);  // 删除节点 20，它有两个子节点
    checkSize(bst, 3);  // 删除后，大小应为3
    checkSearch(bst, 20, 0);  // 查找节点 20，应该返回 NULL
    printf("Deleted node with value 20.\n");

    // 测试用例 6: 边界情况 - 空树删除
    removeItem(bst, 100);  // 尝试删除不存在的节点
    checkSize(bst, 3);  // 删除一个不存在的节点不应改变树的大小
    printf("Attempted to delete non-existent node with value 100.\n");

    // 测试用例 7: 边界情况 - 删除根节点
    removeItem(bst, 10);  // 删除根节点 10
    checkSize(bst, 2);  // 删除后，大小应为2
    checkSearch(bst, 10, 0);  // 查找节点 10，应该返回 NULL
    printf("Deleted root node with value 10.\n");

    // 测试用例 8: 清理二叉搜索树
    delBinarySearchTree(bst);
    printf("Binary search tree destroyed.\n");

    return 0;
}


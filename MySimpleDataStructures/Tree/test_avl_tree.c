#include "avl_tree.h"
#include <assert.h>
#include <stdio.h>

// 检查树的大小（通过遍历树）
void checkAVLTreeSize(TreeNode *node, int *size) {
    if (node != NULL) {
        (*size)++;
        checkAVLTreeSize(node->left, size);
        checkAVLTreeSize(node->right, size);
    }
}

// 检查树的高度（用来验证平衡）
int checkHeight(TreeNode *node) {
	printf("checkHeight\n");
    if (node == NULL) return -1;
    int leftHeight = checkHeight(node->left);
    int rightHeight = checkHeight(node->right);
    if (leftHeight == -1 && rightHeight == -1) return 0;
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 检查树的平衡因子（每个节点的左右高度差，应该在[-1, 1]之间）
void checkBalance(TreeNode *node) {
	if (node != NULL) {
        int bf = balanceFactor(node);
        assert(bf >= -1 && bf <= 1);
        checkBalance(node->left);
        checkBalance(node->right);
    }
}

// 检查节点是否存在
void checkSearch(AVLTree *tree, int num, int expected) {
	TreeNode *result = search(tree, num);
    if (expected == 1) {
        assert(result != NULL && result->val == num);
        printf("Found node with value %d\n", num);
    } else {
        assert(result == NULL);
        printf("Node with value %d not found\n", num);
    }
}

int main() {
    // 测试用例 1: 构造 AVL 树
    AVLTree *tree = newAVLTree();
    assert(tree != NULL);
    printf("AVL tree constructed successfully.\n");

    // 测试用例 2: 插入节点
    insert(tree, 10);
    checkSearch(tree, 10, 1);  // 查找节点 10
    checkBalance(tree->root);  // 确保树是平衡的
    int size = 0;
    checkAVLTreeSize(tree->root, &size);  // 检查树的大小
    assert(size == 1);  // 只有一个节点
    printf("Inserted node with value 10.\n");

    insert(tree, 20);
    insert(tree, 30);  // 插入三个节点，触发旋转
    checkBalance(tree->root);  // 检查平衡
    checkSearch(tree, 20, 1);  // 查找节点 20
    checkSearch(tree, 30, 1);  // 查找节点 30
    checkSearch(tree, 10, 1);  // 查找节点 10
    size = 0;
    checkAVLTreeSize(tree->root, &size);
    assert(size == 3);  // 树中有 3 个节点
    printf("Inserted nodes 20 and 30.\n");

    // 测试用例 3: 删除节点
    removeItem(tree, 10);  // 删除根节点
    checkBalance(tree->root);  // 检查平衡
    checkSearch(tree, 10, 0);  // 确保节点 10 已被删除
    size = 0;
    checkAVLTreeSize(tree->root, &size);
    assert(size == 2);  // 树中应剩余两个节点
    printf("Deleted node with value 10.\n");

    removeItem(tree, 20);  // 删除有一个子节点的节点
	checkBalance(tree->root);  // 检查平衡
    checkSearch(tree, 20, 0);  // 确保节点 20 已被删除
    size = 0;
    checkAVLTreeSize(tree->root, &size);
    assert(size == 1);  // 只剩下一个节点 30
    printf("Deleted node with value 20.\n");

    removeItem(tree, 30);  // 删除最后一个节点
    checkBalance(tree->root);  // 检查平衡
    checkSearch(tree, 30, 0);  // 确保节点 30 已被删除
    size = 0;
    checkAVLTreeSize(tree->root, &size);
    assert(size == 0);  // 树应为空
    printf("Deleted node with value 30.\n");

    // 测试用例 4: 边界情况 - 空树删除
    removeItem(tree, 100);  // 尝试删除不存在的节点
    checkBalance(tree->root);  // 树仍然应该为空
    printf("Attempted to delete non-existent node with value 100.\n");

    // 测试用例 5: 清理 AVL 树
    delAVLTree(tree);
    printf("AVL tree destroyed.\n");

    return 0;
}


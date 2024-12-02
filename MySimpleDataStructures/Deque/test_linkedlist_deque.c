#include <stdio.h>
#include "linkedlist_deque.h"

int main() {
    // 创建一个新的双向队列
    LinkedListDeque *deque = newLinkedListDeque();
    
    // 测试队列的基本操作
    printf("测试入队:\n");
    pushFirst(deque, 10);  // 从队首入队
    pushLast(deque, 20);   // 从队尾入队
    pushFirst(deque, 30);  // 从队首入队
    pushLast(deque, 40);   // 从队尾入队
    pushFirst(deque, 50);  // 从队首入队
    
    // 打印队列内容（从队首开始）
    printLinkedListDeque(deque, true);
    printf("\n");

    // 打印队列内容（从队尾开始）
    printLinkedListDeque(deque, false);
    printf("\n\n");

    // 获取队列的大小
    printf("队列的大小: %d\n", size(deque));

    // 测试访问队首和队尾元素
    printf("队首元素: %d\n", peekFirst(deque));
    printf("队尾元素: %d\n", peekLast(deque));

    // 测试出队操作
    printf("\n测试出队:\n");
    printf("队首出队: %d\n", popFirst(deque));  // 从队首出队
    printf("队尾出队: %d\n", popLast(deque));   // 从队尾出队

    // 打印队列内容（从队首开始）
    printLinkedListDeque(deque, true);
    printf("\n");

    // 再次测试队列大小
    printf("队列的大小: %d\n", size(deque));

    // 测试判断队列是否为空
    if (empty(deque)) {
        printf("队列为空\n");
    } else {
        printf("队列不为空\n");
    }

    // 清理资源
    delLinkedListDeque(deque);
    
    return 0;
}


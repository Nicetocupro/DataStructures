#include <stdio.h>
#include "array_deque.h"

int main() {
    // 创建一个容量为5的双端队列
    ArrayDeque *deque = newArrayDeque(5);

    // 测试入队操作
    printf("测试入队:\n");
    pushFirst(deque, 10);  // 从队首入队
    pushLast(deque, 20);   // 从队尾入队
    pushFirst(deque, 30);  // 从队首入队
    pushLast(deque, 40);   // 从队尾入队
    pushFirst(deque, 50);  // 从队首入队

    // 打印队列状态
    printf("当前队列大小: %d\n", size(deque));
    printf("队列的容量: %d\n", capacity(deque));
    printf("队首元素: %d\n", peekFirst(deque));
    printf("队尾元素: %d\n", peekLast(deque));
    
    // 测试出队操作
    printf("\n测试出队:\n");
    printf("队首出队: %d\n", popFirst(deque));  // 从队首出队
    printf("队尾出队: %d\n", popLast(deque));   // 从队尾出队

    // 打印队列状态
    printf("当前队列大小: %d\n", size(deque));
    printf("队列的容量: %d\n", capacity(deque));
    printf("队首元素: %d\n", peekFirst(deque));
    printf("队尾元素: %d\n", peekLast(deque));

    // 测试队列是否为空
    if (empty(deque)) {
        printf("队列为空\n");
    } else {
        printf("队列不为空\n");
    }

    // 再次进行入队操作
    printf("\n再次进行入队操作:\n");
    pushLast(deque, 60);
    pushFirst(deque, 70);

    // 打印队列状态
    printf("当前队列大小: %d\n", size(deque));
    printf("队列的容量: %d\n", capacity(deque));
    printf("队首元素: %d\n", peekFirst(deque));
    printf("队尾元素: %d\n", peekLast(deque));

    // 清理资源
    delArrayDeque(deque);

    return 0;
}


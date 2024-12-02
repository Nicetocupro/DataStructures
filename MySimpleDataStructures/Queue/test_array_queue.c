#include <stdio.h>
#include "array_queue.h"

int main() {
    // 创建一个容量为5的队列
    ArrayQueue *queue = newArrayQueue(5);

    // 测试入队操作
    printf("测试入队:\n");
    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
    push(queue, 40);
    push(queue, 50);

    // 打印队列
    printf("当前队列的大小: %d\n", size(queue));
    printf("队列容量: %d\n", capacity(queue));
    
    // 测试入队超出容量
    push(queue, 60);  // 队列已经满了

    // 测试访问队首元素
    printf("队首元素: %d\n", peek(queue));

    // 测试出队操作
    printf("\n测试出队:\n");
    printf("出队元素: %d\n", pop(queue));
    printf("出队元素: %d\n", pop(queue));

    // 打印队列
    printf("出队后的队列大小: %d\n", size(queue));
    
    // 测试队列是否为空
    if (empty(queue)) {
        printf("队列为空\n");
    } else {
        printf("队列不为空\n");
    }

    // 再次出队直到队列为空
    printf("\n继续出队:\n");
    printf("出队元素: %d\n", pop(queue));
    printf("出队元素: %d\n", pop(queue));
    printf("出队元素: %d\n", pop(queue));  // 队列已空

    // 测试队列是否为空
    if (empty(queue)) {
        printf("队列为空\n");
    } else {
        printf("队列不为空\n");
    }

    // 清理资源
    delArrayQueue(queue);
    
    return 0;
}


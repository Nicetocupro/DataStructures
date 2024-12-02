#include <stdio.h>
#include "linkedlist_queue.h"

int main() {
    // 创建一个新的队列
    LinkedListQueue *queue = newLinkedListQueue();
    
    // 测试入队
    printf("测试入队:\n");
    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
    push(queue, 40);
    push(queue, 50);

    // 打印队列
    printLinkedListQueue(queue);
    printf("\n\n");

    // 测试队列大小
    printf("队列的大小: %d\n", size(queue));

    // 测试访问队首元素
    printf("队首元素: %d\n", peak(queue));

    // 测试出队
    printf("\n测试出队:\n");
    printf("出队元素: %d\n", pop(queue));
    printf("出队元素: %d\n", pop(queue));
    printf("出队元素: %d\n", pop(queue));

    // 打印队列
    printLinkedListQueue(queue);
    printf("\n\n");

    // 再次测试队列大小
    printf("队列的大小: %d\n", size(queue));

    // 测试判断队列是否为空
    if (empty(queue)) {
        printf("队列为空\n");
    } else {
        printf("队列不为空\n");
    }

    // 清理资源
    delLinkedListQueue(queue);
    
    return 0;
}

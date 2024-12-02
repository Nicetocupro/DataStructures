#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_stack.c"  // 假设你把链表栈的代码保存在这个文件中

int main() {
    // 创建一个栈
    LinkedListStack *stack = newLinkedListStack();

    // 测试栈是否为空
    printf("栈是否为空? %s\n", isEmpty(stack) ? "是" : "否");

    // 测试入栈操作
    printf("入栈: 10\n");
    push(stack, 10);
    printf("栈顶元素: %d\n", peek(stack));
    printf("栈的大小: %d\n", size(stack));

    printf("入栈: 20\n");
    push(stack, 20);
    printf("栈顶元素: %d\n", peek(stack));
    printf("栈的大小: %d\n", size(stack));

    // 测试栈是否为空
    printf("栈是否为空? %s\n", isEmpty(stack) ? "是" : "否");

    // 测试出栈操作
    printf("出栈: %d\n", pop(stack));
    printf("栈顶元素: %d\n", peek(stack));
    printf("栈的大小: %d\n", size(stack));

    printf("出栈: %d\n", pop(stack));
    printf("栈顶元素: %d\n", peek(stack));
    printf("栈的大小: %d\n", size(stack));

    // 测试栈是否为空
    printf("栈是否为空? %s\n", isEmpty(stack) ? "是" : "否");

    // 清理栈
    delLinkedListStack(stack);

    return 0;
}


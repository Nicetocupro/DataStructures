#include <stdio.h>
#include <climits>
#include "array_stack.c"

int main()
{
    // 创建一个新的栈
    ArrayStack *stack = newArrayStack();

    // 测试栈是否为空
    printf("栈是否为空: %s\n", isEmpty(stack) ? "是" : "否");

    // 入栈操作
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("入栈后栈的长度: %d\n", size(stack));

    // 访问栈顶元素
    printf("栈顶元素: %d\n", peak(stack));

    // 出栈操作
    printf("出栈元素: %d\n", pop(stack));
    printf("出栈后栈的长度: %d\n", size(stack));

    // 再次访问栈顶元素
    printf("栈顶元素: %d\n", peak(stack));

    // 出栈剩余元素
    printf("出栈元素: %d\n", pop(stack));
    printf("栈顶元素: %d\n", peak(stack));

    // 再次出栈
    printf("出栈元素: %d\n", pop(stack));

    // 栈是否为空
    printf("栈是否为空: %s\n", isEmpty(stack) ? "是" : "否");

    // 清理栈
    delArrayStack(stack);
    
    return 0;
}


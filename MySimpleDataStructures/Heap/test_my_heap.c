#include <stdio.h>
#include <assert.h>
#include "my_heap.h"

// 测试堆的基本操作
void testHeapBasicOperations() {
    // 测试大顶堆
    Heap *maxHeap = newHeap(true);
    
    // 插入元素
    push(maxHeap, 10);
    push(maxHeap, 20);
    push(maxHeap, 5);
    push(maxHeap, 30);
    push(maxHeap, 15);

    // 确认堆顶是否为最大值
    assert(peak(maxHeap) == 30);  // 堆顶应为最大元素30

    // 弹出堆顶元素
    pop(maxHeap);
    assert(peak(maxHeap) == 20);  // 堆顶应为次大元素20

    // 确认堆的大小
    assert(size(maxHeap) == 4);   // 大小应为4

    // 再插入元素并验证
    push(maxHeap, 25);
    assert(peak(maxHeap) == 25);  // 堆顶应为新插入的最大元素25

    // 清理堆
    delHeap(maxHeap);

    // 测试小顶堆
    Heap *minHeap = newHeap(false);
    
    // 插入元素
    push(minHeap, 10);
    push(minHeap, 20);
    push(minHeap, 5);
    push(minHeap, 30);
    push(minHeap, 15);

    // 确认堆顶是否为最小值
    assert(peak(minHeap) == 5);   // 堆顶应为最小元素5

    // 弹出堆顶元素
    pop(minHeap);
    assert(peak(minHeap) == 10);  // 堆顶应为次小元素10

    // 确认堆的大小
    assert(size(minHeap) == 4);   // 大小应为4

    // 再插入元素并验证
    push(minHeap, 3);
    assert(peak(minHeap) == 3);   // 堆顶应为新插入的最小元素3

    // 清理堆
    delHeap(minHeap);
}

// 测试堆的扩展功能
void testHeapExpansion() {
    Heap *heap = newHeap(true);

    // 插入足够多的元素，验证堆是否能扩展
    for (int i = 1; i <= 100; i++) {
        push(heap, i);
    }

    // 确认堆顶是否为最大值
    assert(peak(heap) == 100);

    // 确认堆的大小是否正确
    assert(size(heap) == 100);

    // 插入更多元素，检查堆的扩展
    for (int i = 101; i <= 200; i++) {
        push(heap, i);
    }

    // 确认堆顶是否为最大值
    assert(peak(heap) == 200);

    // 清理堆
    delHeap(heap);
}

// 测试空堆的情况
void testEmptyHeap() {
    Heap *heap = newHeap(true);

    // 检查堆是否为空
    assert(isEmpty(heap) == true);

    // 尝试从空堆弹出元素，应该返回错误或特定值
    // 假设pop函数在堆空时会返回INT_MIN（你可以修改pop函数来适应这个测试）
    assert(pop(heap) == INT_MAX);  // 如果没有异常，应该返回一个错误值

    // 清理堆
    delHeap(heap);
}

// 测试堆的边界条件
void testHeapBoundaryConditions() {
    // 测试大顶堆的最小容量
    Heap *heap = newHeap(true);

    // 插入一个元素，检查堆顶
    push(heap, 5);
    assert(peak(heap) == 5);

    // 弹出堆顶，堆应该为空
    pop(heap);
    assert(isEmpty(heap) == true);

    // 清理堆
    delHeap(heap);
}

// 测试根据数组构造堆
void testHeapFromArray() {
    // 从数组创建小顶堆
    int arr[] = {10, 20, 5, 30, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    Heap *heap = newHeap_List(arr, n, false);

    // 确认堆顶是否为最小元素
    assert(peak(heap) == 5);

    // 弹出堆顶并检查
    pop(heap);
    assert(peak(heap) == 10);

    // 清理堆
    delHeap(heap);
}

// 测试堆类型的正确性
void testHeapType() {
    Heap *maxHeap = newHeap(true);
    assert(strcmp(type(maxHeap), "大顶堆") == 0);

    Heap *minHeap = newHeap(false);
    assert(strcmp(type(minHeap), "小顶堆") == 0);

    // 清理堆
    delHeap(maxHeap);
    delHeap(minHeap);
}

// 运行所有测试
void runTests() {
    testHeapBasicOperations();
    testHeapExpansion();
    testEmptyHeap();
    testHeapBoundaryConditions();
    testHeapFromArray();
    testHeapType();

    printf("All tests passed!\n");
}

int main() {
    runTests();
    return 0;
}


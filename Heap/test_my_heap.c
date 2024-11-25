#include "my_heap.h"
#include <stdio.h>
#include <assert.h>
#include <limits.h>

void testHeap()
{
    // 1. 测试堆的初始化
    printf("Testing heap initialization...\n");
    Heap *maxHeap = newHeap(true); // 大顶堆
    assert(maxHeap != NULL);
    assert(maxHeap->capacity == 4); // 初始容量为4
    assert(maxHeap->size == 0);     // 初始堆大小为0
    assert(maxHeap->type == true);  // 类型为大顶堆
    printf("Heap initialized correctly.\n");

    // 2. 测试插入操作
    printf("Testing push operation...\n");
    push(maxHeap, 10);
    push(maxHeap, 20);
    push(maxHeap, 5);
    push(maxHeap, 15);
    
    assert(size(maxHeap) == 4); // 插入4个元素
    assert(peak(maxHeap) == 20); // 大顶堆，堆顶应该是20
    printf("Push operation works correctly.\n");

    // 3. 测试扩容操作
    printf("Testing heap extension...\n");
    push(maxHeap, 30); // 触发扩容
    assert(capacity(maxHeap) == 8); // 扩容因子为2，容量应该从4变为8
    assert(size(maxHeap) == 5);     // 堆大小为5
    assert(peak(maxHeap) == 30);    // 大顶堆，堆顶应该是30
    printf("Heap extension works correctly.\n");

    // 4. 测试删除操作
    printf("Testing pop operation...\n");
    int popped = pop(maxHeap);
    assert(popped == 30); // 大顶堆，弹出的最大值应该是30
    assert(size(maxHeap) == 4); // 删除后堆大小应为4
    assert(peak(maxHeap) == 20); // 堆顶应该是20
    printf("Pop operation works correctly.\n");

    // 5. 测试堆化操作
    printf("Testing siftDown and siftUp...\n");
    push(maxHeap, 25); // 插入25，堆化
    assert(size(maxHeap) == 5);
    assert(peak(maxHeap) == 25); // 大顶堆，堆顶应该是25

    int val = pop(maxHeap); // 弹出堆顶
    assert(val == 25);  // 应该弹出25
    assert(peak(maxHeap) == 20); // 堆顶应为20
    printf("SiftDown and siftUp operations work correctly.\n");

    // 6. 测试改变堆类型（从大顶堆改为小顶堆）
    printf("Testing ChangeType...\n");
    maxHeap = ChangeType(maxHeap); // 将大顶堆改为小顶堆
    assert(maxHeap->type == false);  // 应该是小顶堆
    assert(peak(maxHeap) == 5);      // 小顶堆，堆顶应该是5
    printf("ChangeType operation works correctly.\n");

    // 7. 测试删除操作（小顶堆）
    printf("Testing pop operation (small heap)...\n");
    popped = pop(maxHeap);
    assert(popped == 5);   // 小顶堆，弹出的最小值应该是5
    assert(size(maxHeap) == 3); // 堆大小应该是4
    assert(peak(maxHeap) == 10); // 堆顶应该是10
    printf("Pop operation (small heap) works correctly.\n");

    // 8. 测试空堆情况
    printf("Testing empty heap...\n");
    while (!isEmpty(maxHeap))
    {
        pop(maxHeap); // 一直弹出堆顶直到堆空
    }
    assert(isEmpty(maxHeap)); // 堆应该为空
    printf("Empty heap check works correctly.\n");

    // 9. 测试销毁堆
    printf("Testing heap destruction...\n");
    delHeap(maxHeap); // 销毁堆
    printf("Heap destruction works correctly.\n");

    printf("All tests passed!\n");
}

int main()
{
    testHeap();
    return 0;
}


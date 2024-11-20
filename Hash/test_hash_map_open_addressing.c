#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map_open_addressing.h" // 假设你的实现保存为 hash_map_open_addressing.h

void testHashMapOpenAddressing()
{
    printf("=== Test Start ===\n");

    // 初始化哈希表
    HashMapOpenAddressing *hashMap = newHashMapOpenAddressing();
    printf("HashMap initialized. Capacity: %d, Load Threshold: %.2f\n", hashMap->capacity, hashMap->loadThres);

    // 插入元素
    put(hashMap, 1, "One");
    put(hashMap, 2, "Two");
    put(hashMap, 3, "Three");
    put(hashMap, 4, "Four");
    printf("After inserting 4 items:\n");
    print(hashMap);

    // 查询元素
    printf("Get key 2: %s\n", get(hashMap, 2)); // Expected: Two
    printf("Get non-existing key 10: %s\n", get(hashMap, 10)); // Expected: (null)

    // 更新元素
    put(hashMap, 3, "NewThree");
    printf("After updating key 3:\n");
    print(hashMap);

    // 删除元素
    removeItem(hashMap, 2);
    printf("After removing key 2:\n");
    print(hashMap);

    // 查询已删除元素
    printf("Get deleted key 2: %s\n", get(hashMap, 2)); // Expected: (null)

    // 触发扩容
    put(hashMap, 5, "Five");
    put(hashMap, 6, "Six");
    put(hashMap, 7, "Seven");
    printf("After inserting items to trigger resizing:\n");
    print(hashMap);
    printf("New Capacity: %d\n", hashMap->capacity);

    // 检查懒删除标记
    put(hashMap, 2, "ReInsertedTwo");
    printf("After reinserting key 2:\n");
    print(hashMap);

    // 边界测试: 插入空值
    put(hashMap, 8, "");
    printf("After inserting key 8 with an empty string:\n");
    print(hashMap);

    // 插入大量数据
    for (int i = 9; i <= 20; i++) {
        char buffer[20];
        sprintf(buffer, "Value%d", i);
        put(hashMap, i, buffer);
    }
    printf("After inserting multiple items:\n");
    print(hashMap);

    // 删除所有数据
    for (int i = 1; i <= 20; i++) {
        removeItem(hashMap, i);
    }
    printf("After removing all items:\n");
    print(hashMap);

    // 检查边界条件
    printf("Get key 1 after full deletion: %s\n", get(hashMap, 1)); // Expected: (null)

    // 释放内存
    delHashMapOpenAddressing(hashMap);
    printf("HashMap deleted successfully.\n");

    printf("=== Test End ===\n");
}

int main()
{
    testHashMapOpenAddressing();
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hash_map_chaining.h" // 假设.h文件名为hashmapchaining.h

void testHashMap()
{
    printf("=== Test Start ===\n");

    // 创建哈希表
    HashMapChaining *hashMap = newHashMapChaining();
    printf("HashMap initialized. Capacity: %d, Load Threshold: %.2f\n", hashMap->capacity, hashMap->loadThres);

    // 插入元素
    put(hashMap, 1, "One");
    put(hashMap, 2, "Two");
    put(hashMap, 3, "Three");
    printf("After inserting 3 items:\n");
    print(hashMap);

    // 查询元素
    printf("Get key 1: %s\n", get(hashMap, 1)); // Expected: One
    printf("Get key 3: %s\n", get(hashMap, 3)); // Expected: Three
    printf("Get non-existing key 10: %s\n", get(hashMap, 10)); // Expected: (null)

    // 更新元素
    put(hashMap, 1, "NewOne");
    printf("After updating key 1:\n");
    print(hashMap);

    // 触发扩容
    put(hashMap, 4, "Four");
    put(hashMap, 5, "Five");
    printf("After inserting items to trigger resizing:\n");
    print(hashMap);
    printf("New Capacity: %d\n", hashMap->capacity);

    // 删除元素
    removeItem(hashMap, 3);
    printf("After removing key 3:\n");
    print(hashMap);

    // 删除不存在的元素
    removeItem(hashMap, 10);
    printf("After attempting to remove non-existing key 10:\n");
    print(hashMap);

    // 边界测试: 插入空值
    put(hashMap, 6, "");
    printf("After inserting key 6 with an empty string:\n");
    print(hashMap);

    // 边界测试: 插入重复键
    put(hashMap, 6, "Six");
    printf("After updating key 6 with a new value:\n");
    print(hashMap);

    // 边界测试: 大量插入元素
    for(int i = 7; i <= 20; i++)
    {
        char buffer[20];
        sprintf(buffer, "Value%d", i);
        put(hashMap, i, buffer);
    }
    printf("After inserting 14 more items:\n");
    print(hashMap);

    // 析构测试
    delHashMapChaining(hashMap);
    printf("HashMap deleted successfully.\n");

    printf("=== Test End ===\n");
}

int main()
{
    testHashMap();
    return 0;
}


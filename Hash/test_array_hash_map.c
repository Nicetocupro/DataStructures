#include "array_hash_map.h"
#include <stdio.h>

int main() {
    // 创建哈希表
    ArrayHashMap *hmap = newArrayHashMap();

    // 测试1：插入操作
    printf("=== Test 1: Inserting key-value pairs ===\n");
    put(hmap, 1, "apple");
    put(hmap, 2, "banana");
    put(hmap, 3, "cherry");
    put(hmap, 4, "date");

    // 打印哈希表
    print(hmap);

    // 测试2：获取所有键
    printf("\n=== Test 2: Getting all keys ===\n");
    MapSet keySetResult;
    keySet(hmap, &keySetResult);
    int *keys = (int*)keySetResult.set;
    for (int i = 0; i < keySetResult.len; i++) {
        printf("Key: %d\n", keys[i]);
    }
    free(keySetResult.set); // 记得释放内存

    // 测试3：获取所有值
    printf("\n=== Test 3: Getting all values ===\n");
    MapSet valueSetResult;
    valueSet(hmap, &valueSetResult);
    char **vals = (char**)valueSetResult.set;
    for (int i = 0; i < valueSetResult.len; i++) {
        printf("Value: %s\n", vals[i]);
    }
    free(valueSetResult.set); // 记得释放内存

    // 测试4：删除操作
    printf("\n=== Test 4: Removing key 2 ===\n");
    removeItem(hmap, 2);
    print(hmap);  // 删除后重新打印哈希表

    // 测试5：删除操作，删除不存在的键
    printf("\n=== Test 5: Removing a non-existent key ===\n");
    removeItem(hmap, 5);  // 删除一个不存在的键
    print(hmap);  // 查看哈希表，确保没有发生错误

    // 测试6：内存泄漏测试
    printf("\n=== Test 6: Verifying memory management ===\n");
    // 此时我们应该已经调用了`delArrayHashMap`，释放哈希表的内存
    delArrayHashMap(hmap);

    return 0;
}


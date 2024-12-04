#include <stdio.h>
#include <assert.h>
#include "my_list.h"  // 假设 your implementation is in my_list.c

void testNewMyList() {
    MyList *list = newMyList();
    assert(list != NULL);
    assert(size(list) == 0);
    assert(capacity(list) == 10);
    printf("testNewMyList passed\n");
}

void testAdd() {
    MyList *list = newMyList();
    add(list, 10);
    add(list, 20);
    add(list, 30);
    
    assert(size(list) == 3);
    assert(get(list, 0) == 10);
    assert(get(list, 1) == 20);
    assert(get(list, 2) == 30);
    
    printf("testAdd passed\n");
}

void testInsert() {
    MyList *list = newMyList();
    add(list, 10);
    add(list, 20);
    add(list, 30);
    
    insert(list, 1, 15);  // Insert 15 at index 1
    
    assert(size(list) == 4);
    assert(get(list, 0) == 10);
    assert(get(list, 1) == 15);
    assert(get(list, 2) == 20);
    assert(get(list, 3) == 30);
    
    printf("testInsert passed\n");
}

void testRemove() {
    MyList *list = newMyList();
    add(list, 10);
    add(list, 20);
    add(list, 30);
    
    int removed = removeItem(list, 1);  // Remove element at index 1
    assert(removed == 20);
    assert(size(list) == 2);
    assert(get(list, 0) == 10);
    assert(get(list, 1) == 30);
    
    printf("testRemove passed\n");
}

void testExtendCapacity() {
    MyList *list = newMyList();
    
    // Add 10 elements, which should trigger a capacity extension
    for (int i = 0; i < 11; i++) 
	{
        add(list, i);
    }
    
	//printf("%d, %d\n", capacity(list), size(list));
    // At this point, the capacity should be expanded
    assert(capacity(list) == 20);  // Since the initial capacity is 10, and extend ratio is 2
    
    // Add more elements to check if the expansion works
    add(list, 10);
    add(list, 11);
    
    assert(size(list) == 13);
    assert(get(list, 11) == 10);
    assert(get(list, 12) == 11);
    
    printf("testExtendCapacity passed\n");
}

void testGetSet() {
    MyList *list = newMyList();
    add(list, 10);
    add(list, 20);
    
    set(list, 1, 25);  // Set index 1 to 25
    assert(get(list, 1) == 25);
    
    printf("testGetSet passed\n");
}

int main() {
    testNewMyList();
    testAdd();
    testInsert();
    testRemove();
    testExtendCapacity();
    testGetSet();

    printf("All tests passed!\n");

    return 0;
}


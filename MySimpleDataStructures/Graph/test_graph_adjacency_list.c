#include <stdio.h>
#include <assert.h>
#include "graph_adjacency_list.h"

#include <assert.h>

void testGraph() {
    // 测试构造和析构函数
    GraphAdjList *graph = newGraphAdjList();
    assert(graph != NULL);
    assert(graph->size == 0);

    // 测试添加顶点
    addVertex(graph, 1);
    addVertex(graph, 2);
    addVertex(graph, 3);
    assert(graph->size == 3);

    // 测试查找顶点对应的节点
    AdjListNode *node1 = findNode(graph, 1);
    AdjListNode *node2 = findNode(graph, 2);
    AdjListNode *node3 = findNode(graph, 3);
    assert(node1 != NULL && node2 != NULL && node3 != NULL);

    // 测试添加边
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    assert(node1->next->val == 3);
    assert(node1->next->next->val == 2);
	assert(node2->next->val == 1);
    assert(node3->next->val == 1);
	printf("测试添加边成功\n");

    // 测试删除边
    removeEdge(graph, 1, 2);
    assert(node1->next->val == 3);
    assert(node2->next == NULL);
	printf("测试删除边成功\n");

    // 测试删除顶点
    removeVertex(graph, 1);
    assert(graph->size == 2);
    assert(findNode(graph, 1) == NULL);
    assert(node2->next == NULL);
    assert(node3->next == NULL);
	printf("测试删除顶点成功\n");

    // 测试添加超过最大容量的顶点
    for (int i = 4; i <= MAX_SIZE + 1; ++i) {
        addVertex(graph, i);
    }
    assert(graph->size == MAX_SIZE);
    assert(findNode(graph, MAX_SIZE) != NULL);

    // 尝试添加超过最大容量的顶点，应失败
    assert(graph->size == MAX_SIZE);

    // 测试析构函数
    delGraphAdjList(graph);
}

int main() {
    testGraph();
    printf("所有测试用例通过！\n");
    return 0;
}


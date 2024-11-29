#include <stdio.h>
#include <stdlib.h>
#include "graph_adjacency_matrix.h"

int main() {
    // 创建图
    GraphAdjMat *graph = newGraphAdjMat();

    // 添加顶点
    addVertex(graph, 1);
    addVertex(graph, 2);
    addVertex(graph, 3);
    addVertex(graph, 4);
    addVertex(graph, 5);

    // 打印初始图
    printf("初始图:\n");
    printGraphAdjMat(graph);

    // 添加边
    addEdge(graph, 0, 1); // 1-2
    addEdge(graph, 0, 2); // 1-3
    addEdge(graph, 1, 3); // 2-4
    addEdge(graph, 2, 4); // 3-5

    // 打印添加边后的图
    printf("添加边后的图:\n");
    printGraphAdjMat(graph);

    // 删除顶点
    removeVertex(graph, 2); // 删除顶点3

    // 打印删除顶点后的图
    printf("删除顶点3后的图:\n");
    printGraphAdjMat(graph);

    // 删除边
    removeEdge(graph, 0, 1); // 删除边1-2

    // 打印删除边后的图
    printf("删除边1-2后的图:\n");
    printGraphAdjMat(graph);

    // 添加顶点到最大值
    addVertex(graph, 6);
    addVertex(graph, 7);
    addVertex(graph, 8);
    addVertex(graph, 9);
    addVertex(graph, 10);

    // 尝试添加顶点超过最大值
    addVertex(graph, 11); // 应该输出顶点数量达到最大

    // 打印顶点数量达到最大后的图
    printf("顶点数量达到最大后的图:\n");
    printGraphAdjMat(graph);

    // 删除顶点超过范围
    removeVertex(graph, 10); // 应该输出顶点索引越界

    // 删除边超过范围
    removeEdge(graph, 10, 11); // 应该输出边索引越界

    // 释放图
    free(graph);

    return 0;
}

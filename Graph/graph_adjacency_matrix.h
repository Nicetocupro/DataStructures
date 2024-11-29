#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

/* 基于邻接矩阵实现的无向图结构体 */
typedef struct {
	int vertices[MAX_SIZE];
	int adjMat[MAX_SIZE][MAX_SIZE];
	int size;
} GraphAdjMat;

/* 构造函数 */
GraphAdjMat *newGraphAdjMat()
{
	GraphAdjMat *graph = (GraphAdjMat *)malloc(sizeof(GraphAdjMat));
	graph->size = 0;

	for(int i = 0; i < MAX_SIZE; i++)
	{
		for(int j = 0;j < MAX_SIZE; j++)
		{
			graph->adjMat[i][j] = 0;
		}
	}

	return graph;
}

/* 析构函数 */
void delGraphAdjMat(GraphAdjMat *graph, int val)
{
	free(graph);
}

/* 添加顶点 */
void addVertex(GraphAdjMat *graph, int val)
{
	if(graph->size == MAX_SIZE)
	{
		fprintf(stderr, "图的顶点数量已经达到最大\n");
		return;
	}

	// 添加第 n 个节点，并将第 n 行和列设置为0
	int n  = graph->size;
	graph->vertices[n] = val;

	for(int i = 0; i <= n; i++)
	{
		graph->adjMat[n][i] = 0;
		graph->adjMat[i][n] = 0;
	}
	graph->size++;
}

/* 删除顶点 */
void removeVertex(GraphAdjMat *graph, int index)
{
	if(index < 0 ||  index >= graph->size)
	{
		fprintf(stderr, "顶点索引越界\n");
		return;
	}

	// 顶点列表中移除索引 index 的顶点
	for(int i = index; i < graph->size - 1; i++)
	{
		graph->vertices[i] = graph->vertices[i + 1];
	}

	// 将邻接矩阵中删除索引index的行
	for(int i = index; i < graph->size - 1; i++)
	{
		for(int j = 0; j < graph->size; j++)
		{
			graph->adjMat[i][j] = graph->adjMat[i + 1][j];
		}
	}

	// 将邻接矩阵中删除索引index的列 
	for(int i = 0; i < graph->size; i++)
	{
		for(int j = index; j < graph->size - 1; j++)
		{
			graph->adjMat[i][j] = graph->adjMat[i][j + 1];
		}
	}

	graph->size--;
}

/* 添加边 */
void addEdge(GraphAdjMat *graph, int i, int j)
{
	if(i < 0 || j < 0 || i >= graph->size || j >= graph->size)
	{
		fprintf(stderr, "边索引越界或相等\n");
		return;
	}

	graph->adjMat[i][j] = 1;
	graph->adjMat[j][i] = 1;
}

/* 删除边 */
void removeEdge(GraphAdjMat *graph, int i, int j)
{
	if(i < 0 || j < 0 || i >= graph->size || j >= graph->size)
	{
		fprintf(stderr, "边索引越界或相等\n");
		return;
	}

	graph->adjMat[i][j] = 0;
	graph->adjMat[j][i] = 0;
}

/* 打印邻接矩阵 */
void printGraphAdjMat(GraphAdjMat *graph)
{
	printf("顶点列表 = ");
	
	for(int i = 0; i < graph->size; i++)
	{
		printf("%d ", graph->vertices[i]);
	}
	
	printf("\n");

	printf("邻接矩阵 =\n");

	for(int i = 0; i < graph->size; i++)
	{
		for(int j = 0; j < graph->size; j++)
		{
			printf("%d ", graph->adjMat[i][j]);
		}
		printf("\n");
	}
}


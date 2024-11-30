#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 10

/* 节点队列结构体 */
typedef struct {
	int val[MAX_SIZE];
	int front;
	int rear;
	int size;
} Queue;

/* 节点结构体 */
typedef struct AdjListNode {
	int val;
	struct AdjListNode *next;
} AdjListNode;

/* 基于邻接表实现的五向图 */
typedef struct {
	AdjListNode *heads[MAX_SIZE];
	int size;
} GraphAdjList;

/* 构造函数 */
Queue *newQueue()
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->front = 0;
	q->rear = 0;
	q->size = 0;
	return q;
}

/* 判断队列是否为空 */
int isEmpty(Queue *q)
{
	return q->size == 0;
}

/* 入队操作 */
void enqueue(Queue *q, int val)
{
	q->val[q->rear] = val;
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->size++;
}

/* 出队操作 */
int dequeue(Queue *q)
{
	int val = q->val[q->front];
	q->front = (q->front + 1) % MAX_SIZE;
	q->size--;
	return val;
}

/* 查找顶点对应的节点 */
AdjListNode *findNode(GraphAdjList *graph, int val)
{
	for(int i = 0;i < graph->size; i++)
	{
		AdjListNode *cur = graph->heads[i];
		if(cur->val == val)
		{
			return cur;
		}
	}

	return NULL;
}

/* 添加边辅助函数 */
void addEdgeHelper(AdjListNode *head, int val)
{
	AdjListNode *node = (AdjListNode *)malloc(sizeof(AdjListNode));
	node->val = val;

	// 头插法
	node->next = head->next;
	head->next = node;
}

/* 删除边辅助函数 */
void removeEdgeHelper(AdjListNode *head, int val)
{
	AdjListNode *cur = head;
    AdjListNode *pre = NULL;

    while (cur) {
        if (cur->val == val) {
            if (pre) {
                pre->next = cur->next;
            } else {
                head = cur->next;
            }
			free(cur);
            return; // 只删除一条边，因此找到后即可返回
        }
        pre = cur;
        cur = cur->next;
    }
}

/* 构造函数 */
GraphAdjList *newGraphAdjList()
{
	GraphAdjList *graph = (GraphAdjList *)malloc(sizeof(GraphAdjList));
	if(!graph)
	{
		return NULL;
	}
	graph->size = 0;

	for(int i = 0; i < MAX_SIZE; i++)
	{
		graph->heads[i] = NULL;
	}

	return graph;
}

/* 析构函数 */
void delGraphAdjList(GraphAdjList *graph)
{
	for(int i = 0; i < graph->size; i++)
	{
		AdjListNode *cur = graph->heads[i];
		while(cur != NULL)
		{
			AdjListNode *next = cur->next;
			if(cur != graph->heads[i])
			{
				free(cur);
			}
			cur = next;
		}
		free(graph->heads[i]);
	}
}

/* 添加边 */
void addEdge(GraphAdjList *graph, int val1, int val2)
{
	AdjListNode *head1 = findNode(graph, val1);
	AdjListNode *head2 = findNode(graph, val2);
	
	assert(head1 != NULL && head2 != NULL && head1 != head2);
	
	// 添加边 val1 - val2 
	addEdgeHelper(head1, val2);
	addEdgeHelper(head2, val1);
}

/* 删除边 */
void removeEdge(GraphAdjList *graph, int val1, int val2)
{
	AdjListNode *head1 = findNode(graph, val1);
	AdjListNode *head2 = findNode(graph, val2);
	
	assert(head1 != NULL && head2 != NULL && head1 != head2);
	
	// 添加边 val1 - val2
	removeEdgeHelper(head1, val2);
	removeEdgeHelper(head2, val1);
}

/* 添加顶点 */
void addVertex(GraphAdjList *graph, int val)
{
	assert(graph != NULL && graph->size < MAX_SIZE);
	AdjListNode *head = (AdjListNode *)malloc(sizeof(AdjListNode));
	head->val = val;
	head->next = NULL;

	graph->heads[graph->size++] = head;
}

/* 删除节点 */
void removeVertex(GraphAdjList *graph, int val)
{
	AdjListNode *node = findNode(graph, val), *cur, *pre;
	assert(node != NULL);

	// 遍历其他节点，删除所有包含val的边
	for(int i = 0; i < graph->size; i++)
	{
		cur = graph->heads[i];
		pre = NULL;
		while(cur)
		{
			pre = cur;
			cur = cur->next;
			if(cur && cur->val == val)
			{
				pre->next = cur->next;
				free(cur);
				break;
			}
		}
	}

	int i;
	for(i = 0; i < graph->size; i++)
	{
		if(graph->heads[i] == node)
		{
			break;
		}
	}

	for(int j = i; j < graph->size - 1 ; j++)
	{
		graph->heads[j] = graph->heads[j + 1];
	}
	graph->size--;

	// 在邻接表中删除顶点 val 对应的链表
	cur = node;
	pre = NULL;
	while(cur)
	{
		pre = cur;
		cur = cur->next;
		free(pre);
	}
}

/* 检查顶点是否被访问过 */
int isVisited(int *visited, int size, int val)
{
	// 遍历查找节点
	for(int i = 0; i < size; i++)
	{
		if(visited[i] == val)
		{
			return 1;
		}
	}
	return 0;
}

/* 广度优先遍历 */
// 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点
void graphBFS(GraphAdjList *graph, int startVal, int *res, int *resSize, int *visited, int *visitedSize)
{
	// 队列实现 BFS
	Queue *queue = newQueue();
	enqueue(queue, startVal);
	visited[(*visitedSize)++] = startVal;
	
	// 以顶点 val 为起点，循环直至访问完所有节点
	while(!isEmpty(queue))
	{
		int val = dequeue(queue);
		res[(*resSize)++] = val;

		// 遍历该顶点所有邻接顶点
		AdjListNode *node = findNode(graph, val);
		while(node != NULL)
		{
			// 跳过被访问的顶点
			if(isVisited(visited, *visitedSize, val))
			{
				enqueue(queue, node->val);
				visited[(*visitedSize)++] = node->val;
			}
		}
	}
	free(queue);
}

/* dfs辅助函数 */
void dfs(GraphAdjList *graph, int *res, int *resSize, int val)
{
	// 记录访问顶点
	res[(*resSize)++] = val;

	// 遍历该顶点的所有邻接顶点
	AdjListNode *node = findNode(graph, val);
	while(node != NULL)
	{
		// 跳过已被访问的顶点
		if(!isVisited(res, *resSize, node->val))
		{
			dfs(graph, res, resSize, node->val);
		}
		node = node->next;
	}
}

/* 深度优先遍历 */
void graphDFS(GraphAdjList *graph, int startVal, int *res, int *resSize)
{
	dfs(graph, res, resSize, startVal);
}

#include "array_queue.h"

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
	if(MaxElements < MinQueueSize)
		fprintf(stderr, "Queue is too small");
	
	Queue Q;
	Q = malloc(sizeof(struct QueueRecord));
	if(Q == NULL)
		fprintf(stderr, "Out Of Space!!!");

	Q->Array = malloc(sizeof(ElementType) * MaxElements);
	if(Q->Array == NULL)
		fprintf(stderr, "Out Of Space!!!");

	Q->Front = 1;
	Q->Rear = 0;
	Q->Size = 0;
	Q->Capacity = MaxElements;
}

void DisposeQueue(Queue Q)
{
	if(Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}

void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
	if(++Value == Q->Capacity)
	{
		Value == 0;
	}
	return Value;
}

void Enqueue(ElementType X, Queue Q)
{
	if(IsFull(Q))
		fprintf(stderr, "Full queue");
	else 
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

ElementType Front(Queue Q)
{
	return Q->Array[Q->Front];
}

void Dequeue(Queue Q)
{
	if(IsEmpty(Q))
		fprintf(stderr, "Empty Queue");
	else 
	{
		Q->Front = Succ(Q->Front, Q);
		Q->Size--;
	}
}

ElementType FrontAndDequeue(Queue Q)
{
	if(IsEmpty(Q))
		fprintf(stderr, "Empty Queue");
	else
	{
		ElementType res = Q->Array[Q->Front];
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);
		return res;
	}
	return 0;
}

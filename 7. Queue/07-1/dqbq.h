#ifndef DQBQ_H_
#define DQBQ_H_
#include "dq.h"

typedef deque Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);
void Enqueue(Queue* pq, int data);
int Dequeue(Queue* pq);
int QPeek(Queue* pq);

#endif
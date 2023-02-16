#include "dqbq.h"

void QueueInit(Queue* pq){init(pq);}
int QIsEmpty(Queue* pq){return isempty(pq);}
void Enqueue(Queue* pq, int data){insert_rear(pq, data);}
int Dequeue(Queue* pq){return delete_front(pq);}
int QPeek(Queue* pq){return show_front(pq);}
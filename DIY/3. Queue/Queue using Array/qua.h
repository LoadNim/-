#ifndef QUA_H_
#define QUA_H_
#include <stdbool.h>
#define QUEUE_SIZE 10

typedef struct queue{
    int arr[QUEUE_SIZE];
    int front, rear;
}queue;

void init(queue* q);
void enqueue(queue* q, int data);
int dequeue(queue* q);
int peek(queue* q);
bool isempty(queue* q);
bool isfull(queue* q);
#endif
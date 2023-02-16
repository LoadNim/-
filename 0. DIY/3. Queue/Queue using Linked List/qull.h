#ifndef QULL_H_
#define QULL_H_
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
}queue;

void init(queue* q);
void enqueue(queue* q, int data);
int dequeue(queue* q);
int peek(queue* q);
bool isempty(queue* q);
#endif
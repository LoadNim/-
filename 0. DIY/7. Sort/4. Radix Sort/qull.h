#ifndef QULL_H_
#define QULL_H_
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

typedef struct liked_list{
    node* head;
}queue;

void init(queue* q);
void enqueue(queue* q, int data);
int dequeue(queue* q);
int peek(queue* q);
bool isempty(queue* q);
#endif
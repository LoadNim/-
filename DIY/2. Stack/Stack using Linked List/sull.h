#ifndef SULL_H_
#define SULL_H_
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    node* head;
    int size;
}stack;

void init(stack* st);
void peek(stack* st);
void push(stack* st, int data);
void pop(stack* st);
bool isempty(stack* st);
#endif
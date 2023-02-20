#ifndef SWAP_H_
#define SWAP_H_
#include <stdbool.h>

typedef char data;
typedef struct node{
    data data;
    struct node* next;
}node;

typedef struct stack{
    node* head;
}stack;

void init(stack* st);
void push(stack* st, data data);
data pop(stack* st);
data peek(stack* st);
bool isempty(stack* st);
void swap(char* input, char* result);
#endif
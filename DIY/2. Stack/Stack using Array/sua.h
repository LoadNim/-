#ifndef SUA_H_
#define SUA_H_
#include <stdbool.h>

typedef struct stack{
    int arr[10];
    int size;
}stack;

void init(stack* st);
bool isempty(stack* st);
bool ispull(stack* st);
void push(stack* st, int data);
void pop(stack* st);
void peek(stack* st);
#endif
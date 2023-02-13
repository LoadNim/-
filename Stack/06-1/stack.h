#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>
#include "CLinkedList.h"

typedef struct stack{
    List* li;
    int num;
}stack;

void stack_init(stack* st);
void push(stack* st, Data data);
void pop(stack* st);
void peek(stack* st);
bool isempty(stack* st);
#endif
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
#include "CLinkedList.h"

void stack_init(stack* st){
    st->li = (List*)malloc(sizeof(List));
    ListInit(st->li);
    st->num = 0;
}

void push(stack* st, Data data){
    LInsertFront(st->li, data);
    ++(st->num);
}

void pop(stack* st){
    if(isempty(st)) printf("스택이 비어있습니다.\n");
    else{
        int data;
        LFirst(st->li, &data);
        printf("pop : %d\n", LRemove(st->li));
    }
    --(st->num);
}

void peek(stack* st){
    printf("top : %d\n", st->li->tail->next->data);
}

bool isempty(stack* st){
    return !(st->num);
}
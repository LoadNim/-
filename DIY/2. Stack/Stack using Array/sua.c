#include <stdio.h>
#include <stdbool.h>
#include "sua.h"

void init(stack* st){
    st->size = 0;
}

bool isempty(stack* st){
    return !(st->size);
}

bool ispull(stack* st){
    if(st->size == 10) return true;
    else return false;
}

void push(stack* st, int data){
    if(!ispull(st)){
        st->arr[st->size] = data;
        printf("push : %d\n", st->arr[st->size]);
        ++(st->size);
    }
    else printf("스택이 가득 차있습니다!\n");
}

void pop(stack* st){
    if(isempty(st)) printf("스택이 비어있습니다!\n");
    else{
        --(st->size);
        printf("pop : %d\n", st->arr[st->size]);
        st->arr[st->size] = 0;
    }
}

void peek(stack* st){
    printf("현재 top에 있는 값 : %d\n", st->arr[st->size - 1]);
}
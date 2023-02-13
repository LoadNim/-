#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sull.h"

void init(stack* st){
    st->head = (node*)malloc(sizeof(node));
    st->head->next = NULL;
    st->size = 0;
}

void peek(stack* st){
    if(isempty(st)) printf("스택이 비어있습니다!\n");
    else printf("top : %d\n", st->head->next->data);
}

void push(stack* st, int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = st->head->next;
    st->head->next = newnode;
    printf("push : %d\n", st->head->next->data);
    ++(st->size);
}

void pop(stack* st){
    if(isempty(st)) printf("스택이 비어있습니다!\n");
    else{
        node* temp = st->head->next;
        st->head->next = temp->next;
        printf("pop : %d\n", temp->data);
        free(temp);
        --(st->size);
    }
}

bool isempty(stack* st){
    return !(st->size);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "swap.h"

void push(stack* st, data data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(st->head == NULL){
        st->head = newnode;
        st->head->next = NULL;
    }
    else{
        newnode->next = st->head;
        st->head = newnode;
    }
}

data pop(stack* st){
    if(isempty(st)){
        printf("잘못된 메모리 접근입니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else{
        node* temp = st->head;
        data data = temp->data;
        st->head = st->head->next;
        free(temp);
        return data;
    }
}

data peek(stack* st){
    if(isempty(st)){
        printf("잘못된 메모리 접근입니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else return st->head->data;
}

void init(stack* st){st->head = NULL;}
bool isempty(stack* st){return st->head==NULL;}


void swap(char* input, char* result){
    stack st;
    init(&st);
    int r = 0;
    for(int i = 0; i < strlen(input); ++i){
        if(isdigit(input[i])) result[r++] = input[i];
        else if(input[i] == '(') push(&st, input[i]);
        else if(input[i] == '+' || input[i] == '-'){
            if(isempty(&st)) push(&st, input[i]);
            else if(peek(&st) == '(') push(&st, input[i]);
            else{
                while(!isempty(&st) && !(peek(&st) == '(')) result[r++] = pop(&st);
                push(&st, input[i]);
            }
        }
        else if(input[i] == '*' || input[i] == '/'){
            if(isempty(&st)) push(&st, input[i]);
            else if(peek(&st) == '*' || peek(&st) == '/'){
                result[r++] = pop(&st);
                push(&st, input[i]);
            }
            else push(&st, input[i]);
        }
        else{
            while(!(peek(&st) == '(')) result[r++] = pop(&st);
            pop(&st);
        }
    }
    while(!isempty(&st)) result[r++] = pop(&st);
}
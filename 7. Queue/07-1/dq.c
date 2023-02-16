#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dq.h"

void init(deque* dq){
    dq->front = NULL;
    dq->rear = NULL;
}

void insert_front(deque* dq, int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(isempty(dq)){
        dq->front = newnode;
        dq->rear = newnode;
    }
    else{
        newnode->next = dq->front;
        newnode->prev = NULL;
        dq->front->prev = newnode;
        dq->front = newnode;
    }
}

void insert_rear(deque* dq, int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(isempty(dq)){
        dq->front = newnode;
        dq->rear = newnode;
    }
    else{
        newnode->next = NULL;
        newnode->prev = dq->rear;
        dq->rear->next = newnode;
        dq->rear = newnode;
    }
}

int delete_front(deque* dq){
    if(isempty(dq)){
        printf("잘못된 접근입니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else{
        node* temp = dq->front;
        int data = temp->data;
        dq->front = dq->front->next;
        if(dq->front == NULL) dq->rear = NULL;
        else dq->front->prev = NULL;
        free(temp);
        return data;
    }
}

int delete_rear(deque* dq){
    if(isempty(dq)){
        printf("잘못된 접근입니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else{
        node* temp = dq->rear;
        int data = temp->data;
        dq->rear = dq->rear->prev;
        if(dq->rear == NULL) dq->front = NULL;
        else dq->rear->next = NULL;
        free(temp);
        return data;
    }
}

int show_front(deque* dq){
    if(isempty(dq)){
        printf("잘못된 접근입니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else return dq->front->data;
}
int show_rear(deque* dq){
    if(isempty(dq)){
        printf("잘못된 접근입니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else return dq->rear->data;
}
bool isempty(deque* dq){return dq->front == NULL;}
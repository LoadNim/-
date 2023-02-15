#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "qull.h"

void init(queue* q){
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue* q, int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(q->front == NULL){
        q->front = newnode;
        q->rear = newnode;
    }
    else{
        newnode->next = NULL;
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(queue* q){
    if(isempty(q)){
        printf("큐가 비어있습니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else{
        node* temp = q->front;
        int data = temp->data;
        q->front = q->front->next;
        free(temp);
        return data;
    }
}

int peek(queue* q){
    if(isempty(q)){
        printf("큐가 비어있습니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else return q->front->data;
}

bool isempty(queue* q){return q->front == NULL;}
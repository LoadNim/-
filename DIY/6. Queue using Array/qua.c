#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "qua.h"

void init(queue* q){
    q->arr[0] = -1;
    q->front = 0;
    q->rear = 0;
}

void enqueue(queue* q, int data){
    if(isfull(q)){
        printf("큐가 가득 찼습니다!\n");
    }
    else{
        q->rear = (q->rear + 1) % QUEUE_SIZE;
        q->arr[q->rear] = data;
        printf("arr[%d] : %d\n", q->rear, q->arr[q->rear]);
    }
}

int dequeue(queue* q){
    q->front = (q->front + 1) % QUEUE_SIZE;
    return q->arr[q->front];
}

int peek(queue* q){return q->arr[(q->front + 1) % QUEUE_SIZE];}
bool isempty(queue* q){return q->front == q->rear;}
bool isfull(queue* q){return (q->rear + 1) % QUEUE_SIZE == q->front;}
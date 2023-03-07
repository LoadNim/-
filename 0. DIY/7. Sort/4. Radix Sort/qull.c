#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "qull.h"

void enqueue(queue* q, int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(q->head == NULL){
        newnode->next = newnode;
        newnode->prev = newnode;
        q->head = newnode;
    }
    else{
        newnode->next = q->head;
        newnode->prev = q->head->prev;
        q->head->prev->next = newnode;
        q->head->prev = newnode;
    }
}

int dequeue(queue* q){
    node* temp = q->head;
    int for_return = temp->data;
    q->head = q->head->next;
    free(temp);
    return for_return;
}

void init(queue* q){q->head = NULL;}
int peek(queue* q){return q->head->data;}
bool isempty(queue* q){return q->head == NULL;}
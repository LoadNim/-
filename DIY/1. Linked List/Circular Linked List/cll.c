#include <stdlib.h>
#include <stdio.h>
#include "cll.h"

void init(list* li){
    li->tail = (node*)malloc(sizeof(node));
    li->tail->next = li->tail;
    li->num = 0;
}

void insert_head(list* li, int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = li->tail->next;
    li->tail->next = newnode;
    ++(li->num);
}

void insert_tail(list* li, int data){
    node* newnode = (node*)malloc(sizeof(node));
    li->tail->data = data;
    newnode->next = li->tail->next;
    li->tail->next = newnode;
    li->tail = li->tail->next;
    ++(li->num);
}

void delete_node(list* li){
    node* temp = li->cur;
    li->prev->next = li->cur->next;
    li->cur = li->prev;
    free(temp);
    --(li->num);
}

void set_first(list* li){
    li->prev = li->tail;
    li->cur = li->tail->next;
}

void set_next(list* li){
    if(li->cur->next == li->tail){
        li->prev = li->tail;
        li->cur = li->tail->next;
    }
    else{
        li->prev = li->cur;
        li->cur = li->cur->next;
    }
}
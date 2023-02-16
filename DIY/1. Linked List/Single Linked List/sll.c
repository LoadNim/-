#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sll.h"

void init(list* li){
    li->head = (node*)malloc(sizeof(node));
    li->head->next = NULL;
    li->prev = li->head;
    li->num = 0;
}

bool set_first(list* li){
    if(li->head == NULL){
        printf("리스트에 데이터가 없습니다.\n");
        return false;
    }
    else{
        li->cur = li->head->next;
        return true;
    }
}

bool set_next(list* li){
    if(li->cur->next == NULL) return false;
    else{
        li->prev = li->cur;
        li->cur = li->cur->next;
        return true;
    }
}

void insert_node(list* li, int a){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = a;

    if(li->head->next == NULL){
        newnode->next = li->head->next;
        li->head->next = newnode;
    }
    else{
        node *temp = li->head->next;
        while(temp->next != NULL && li->fx(newnode, temp)) temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
    ++(li->num);
}

void delete_node(list* li){
    node* temp = li->cur;
    li->cur = li->prev;
    li->prev->next = temp->next;
    free(temp);
    --(li->num);
}

void init_sort(list* li, bool (*fx)(node* nd1, node* nd2)){
    li->fx = fx;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dll.h"

void init(list* li){
    li->head = (node*)malloc(sizeof(node));
    li->head->next = li->head;
    li->head->prev = li->head;
    li->num = 0;
}

bool set_first(list* li){
    if(li->head->next == li->head){
        printf("리스트에 데이터가 없습니다.\n");
        return false;
    }
    else{
        li->cur = li->head->next;
        return true;
    }
}

bool set_next(list* li){
    if(li->num == 0) return false;
    else if(li->cur->next == li->head){
        li->cur = li->head->next;
        return true;
    }
    else{
        li->cur = li->cur->next;
        return true;
    }
}

void insert_node(list* li, int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = li->head->next;
    newnode->prev = li->head;
    li->head->next->prev = newnode;
    li->head->next = newnode;
    ++(li->num);
}

void delete_node(list* li){
    node* temp = li->cur;
    if(li->num == 1){
        li->head->next = li->head;
        li->head->prev = li->head;
        li->cur = li->head;
        free(temp);
    }
    else{
        li->cur->prev->next = li->cur->next;
        li->cur->next->prev = li->cur->prev;
        li->cur = li->cur->prev;
        free(temp);
    }
    --(li->num);
}
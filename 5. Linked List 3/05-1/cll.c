#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cll.h"

void init(list* li){
    li->tail = NULL;
    li->prev = NULL;
    li->cur = NULL;
    li->num = 0;
}

void insert_tail(list* li, emp* em){
    emp* newnode = (emp*)malloc(sizeof(emp));
    newnode = em;

    if(li->tail == NULL){
        li->tail = newnode;
        newnode->next = newnode;
    }
    else{
        newnode->next = li->tail->next;
        li->tail->next = newnode;
        li->tail = newnode;
    }
    ++(li->num);
}

void insert_front(list* li, emp* em){
    emp* newnode = (emp*)malloc(sizeof(emp));
    newnode = em;

    if(li->tail == NULL){
        li->tail = newnode;
        newnode->next = newnode;
    }
    else{
        newnode->next = li->tail->next;
        li->tail->next = newnode;
    }
    ++(li->num);
}

void delete_node(list* li){
    emp* temp = li->cur;
    if(temp == li->tail){
        if(li->tail->next = li->tail) li->tail == NULL;
        else li->tail = li->prev;
    }

    li->prev->next = temp->next;
    li->cur = li->prev;
    free(temp);
    --(li->num);
}

void set_first(list* li){
    if(li->tail->next == NULL) printf("리스트가 비어있습니다.\n");
    else{
        li->prev = li->tail;
        li->cur = li->tail->next;
    }
}

void set_next(list* li){
    li->prev = li->cur;
    li->cur = li->cur->next;
}
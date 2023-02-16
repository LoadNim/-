#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void ListInit(List* plist){
    plist->head = (Node*)malloc(sizeof(Node));
    plist->tail = (Node*)malloc(sizeof(Node));
    plist->head->next = plist->tail;
    plist->head->prev = NULL;
    plist->tail->prev = plist->head;
    plist->tail->next = NULL;
    plist->numOfData = 0;
}

void LInsert(List* plist, Data data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = plist->tail;
    newnode->prev = plist->tail->prev;
    plist->tail->prev->next = newnode;
    plist->tail->prev = newnode;
    ++(plist->numOfData);
}

int LFirst(List* plist, Data* pdata){
    if(plist->head->next == plist->tail){
        printf("리스트에 데이터가 없습니다.\n");
        return 0;
    }
    else{
        plist->cur = plist->head->next;
        *pdata = plist->cur->data;
        return 1;
    }
}

int LNext(List* plist, Data* pdata){
    if(plist->cur->next == plist->tail) return 0;
    else{
        plist->cur = plist->cur->next;
        *pdata = plist->cur->data;
        return 1;
    }
}

Data LRemove(List* plist){
    Node* temp = plist->cur;
    Data for_return = temp->data;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    plist->cur = plist->cur->prev;
    free(temp);
    --(plist->numOfData);
    return for_return;
}

int LCount(List* plist){
    return plist->numOfData;
}
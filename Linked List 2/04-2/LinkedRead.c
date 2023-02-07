#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

int main(){
    node* head;
    node* tail = NULL;
    node* cur = NULL;
    node* dmy = (node*)malloc(sizeof(node));
    head->next = dmy;
    tail = dmy;

    int arr[4] = {2, 4, 6, 8};
    for(int i = 0; i < 4; ++i){
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = arr[i];
        tail->next = newnode;
        tail = newnode;
    }

    cur = dmy;
    for(int i = 0; i < 4; ++i){
        cur = cur->next;
        printf("%d ", cur->data);
    }
}
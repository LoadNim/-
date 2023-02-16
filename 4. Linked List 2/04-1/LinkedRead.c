#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

int main(){
    node* head = NULL;
    node* tail = NULL;
    node* cur = NULL;

    int arr[5] = {3, 2, 7, 8, 5};
    for(int i = 0; i < 5; ++i){
        node* newnode = (node*)malloc(sizeof(node));
        if(head == NULL){
            newnode->data = arr[i];
            newnode->next = NULL;
            head = newnode;
            tail = newnode;
        }
        else{
            newnode->data = arr[i];
            newnode->next = head;
            head = newnode;
        }
    }

    cur = head;
    for(int i = 0; i < 5; ++i){
        printf("%d ", cur->data);
        cur = cur->next;
    }
}
#ifndef DLL_H_
#define DLL_H_
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

typedef struct list{
    node* head;
    node* cur;
    int num;
}list;

void init(list* li);
bool set_first(list* li);
bool set_next(list* li);
void insert_node(list* li, int data);
void delete_node(list* li);
#endif
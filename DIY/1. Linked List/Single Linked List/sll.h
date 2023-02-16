#ifndef SLL_H_
#define SLL_H_
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct list{
    node* head;
    node* prev;
    node* cur;
    int num;
    bool (*fx)(node* nd1, node* nd2);
}list;

void init(list* li);
bool set_first(list* li);
bool set_next(list* li);
void insert_node(list* li, int a);
void delete_node(list* li);
void init_sort(list* li, bool(*fx)(node* nd1, node*nd2));
#endif
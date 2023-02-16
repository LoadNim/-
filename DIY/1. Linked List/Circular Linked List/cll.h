#ifndef CLL_H_
#define CLL_H_

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct list{
    node* tail;
    node* prev;
    node* cur;
    int num;
}list;

void init(list* li);
void insert_head(list* li, int data);
void insert_tail(list* li, int data);
void delete_node(list* li);
void set_first(list* li);
void set_next(list* li);
#endif
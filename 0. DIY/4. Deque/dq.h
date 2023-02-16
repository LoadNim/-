#ifndef DQ_H_
#define DQ_H_
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

typedef struct deque{
    node* front;
    node* rear;
}deque;

void init(deque* dq);
void insert_front(deque* dq, int data);
void insert_rear(deque* dq, int data);
int delete_front(deque* dq);
int delete_rear(deque* dq);
int show_front(deque* dq);
int show_rear(deque* dq);
bool isempty(deque* dq);
#endif
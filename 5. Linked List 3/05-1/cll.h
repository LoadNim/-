#ifndef CLL_H_
#define CLL_H_

typedef struct emp{
    char name[30];
    int emp_num;
    struct emp* next;
}emp;

typedef struct list{
    emp* tail;
    emp* prev;
    emp* cur;
    int num;
}list;

void init(list* li);
void insert_tail(list* li, emp* em);
void insert_front(list* li, emp* em);
void delete_node(list* li);
void set_first(list* li);
void set_next(list* li);
#endif
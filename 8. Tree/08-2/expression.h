#ifndef EXPRESSION_H_
#define EXPRESSION_H_
#include <stdbool.h>

typedef struct expression_tree{
    struct expression_tree* right;
    struct expression_tree* left;
    char data;
}expt;

expt* make_node();
void link_left(expt* t1, expt* t2);
void link_right(expt* t1, expt* t2);
char get_data(expt* t);
void set_data(expt* t, char data);
expt* get_left(expt* t);
expt* get_right(expt* t);

typedef struct node_for_exp{
    struct node_for_exp* next;
    expt* data;
}nfe;

typedef struct stack_for_exp{
    nfe* head;
}stack_for_exp;

void init_for_exp(stack_for_exp* st);
void push_for_exp(stack_for_exp* st, expt* data);
expt* pop_for_exp(stack_for_exp* st);
expt* peek_for_exp(stack_for_exp* st);
bool isempty_for_exp(stack_for_exp* st);
void expression(char* result);
void traversal_prefix(expt* t);
void traversal_infix(expt* t);
void traversal_postfix(expt* t);
#endif
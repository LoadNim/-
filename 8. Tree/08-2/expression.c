#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "expression.h"

expt* make_node(){
    expt* node = (expt*)malloc(sizeof(expt));
    node->data = 0;
    node->right = NULL;
    node->left = NULL;
    return node;
}

void link_left(expt* t1, expt* t2){
    if(t1->left != NULL) free(t1->left);
    t1->left = t2;
}

void link_right(expt* t1, expt* t2){
    if(t1->right != NULL) free(t1->right);
    t1->right = t2;
}

char get_data(expt* t){return t->data;}
void set_data(expt* t, char data){t->data = data;}
expt* get_left(expt* t){return t->left;}
expt* get_right(expt* t){return t->right;}

void push_for_exp(stack_for_exp* st, expt* data){
    nfe* newnode = (nfe*)malloc(sizeof(nfe));
    newnode->data = data;
    if(st->head == NULL){
        st->head = newnode;
        st->head->next = NULL;
    }
    else{
        newnode->next = st->head;
        st->head = newnode;
    }
}

expt* pop_for_exp(stack_for_exp* st){
    if(isempty_for_exp(st)){
        printf("잘못된 메모리 접근입니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else{
        nfe* temp = st->head;
        expt* data = temp->data;
        st->head = st->head->next;
        free(temp);
        return data;
    }
}

expt* peek_for_exp(stack_for_exp* st){
    if(isempty_for_exp(st)){
        printf("잘못된 메모리 접근입니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else return st->head->data;
}

void init_for_exp(stack_for_exp* st){st->head = NULL;}
bool isempty_for_exp(stack_for_exp* st){return st->head==NULL;}

void expression(char* result){
    int size = strlen(result);
    expt* arr[size];
    stack_for_exp st;
    init_for_exp(&st);
    for(int i = 0; i < size; ++i){
        arr[i] = make_node();
        set_data(arr[i], result[i]);
        if(isdigit(result[i])) push_for_exp(&st, arr[i]);
        else{
            link_right(arr[i], pop_for_exp(&st));
            link_left(arr[i], pop_for_exp(&st));
            push_for_exp(&st, arr[i]);
        }
    }
    printf("전위 표기법 : ");
    traversal_prefix(arr[size-1]);
    printf("\n중위 표기법 : ");
    traversal_infix(arr[size-1]);
    printf("\n후위 표기법 : ");
    traversal_postfix(arr[size-1]);
    printf("\n");
}

void traversal_prefix(expt* t){
    if(t == NULL) return;
    printf("%c", t->data);
    traversal_prefix(t->left);
    traversal_prefix(t->right);
}

void traversal_infix(expt* t){
    if(t == NULL) return;
    if(t->left != NULL || t->right != NULL) printf("(");
    traversal_infix(t->left);
    printf("%c", t->data);
    traversal_infix(t->right);
    if(t->left != NULL || t->right != NULL) printf(")");
}

void traversal_postfix(expt* t){
    if(t == NULL) return;
    traversal_postfix(t->left);
    traversal_postfix(t->right);
    printf("%c", t->data);
}
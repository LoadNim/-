#include <stdio.h>
#include "CLinkedList.h"
#include "stack.h"

int main(){
    int data;
    stack st;
    stack_init(&st);
    for(int i = 0; i < 10; ++i) push(&st, i);
    printf("push()후 스택 출력\n");
    LFirst(st.li, &data);
    printf("%d ", data);
    for(int i = 0; i < 9; ++i){
        LNext(st.li, &data);
        printf("%d ", data);
    }
    printf("\n");
    peek(&st);
    for(int i = 0; i < 11; ++i) pop(&st);
}
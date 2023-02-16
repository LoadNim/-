#include <stdio.h>
#include "sull.h"

int main(){
    stack st;
    init(&st);
    peek(&st);

    for(int i = 0; i < 10; ++i) push(&st, i);
    peek(&st);
    for(int i = 0; i < 11; ++i) pop(&st);
}
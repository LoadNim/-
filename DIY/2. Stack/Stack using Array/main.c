#include <stdio.h>
#include "sua.h"

int main(){
    stack st;
    init(&st);
    for(int i = 0; i < 11; ++i) push(&st, i);
    for(int i = 0; i < 4; ++i) pop(&st);
    peek(&st);
    for(int i = 0; i < 7; ++i) pop(&st);
}
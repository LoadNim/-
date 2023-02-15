#include <stdio.h>
#include "qua.h"

int main(){
    int i = 0;
    int data;
    queue q;
    init(&q);
    while(!isfull(&q)) enqueue(&q, i++);
    printf("peek : %d\n", peek(&q));
    while (!isempty(&q)){
        printf("dequeue : %d\n", dequeue(&q));
    }  
}
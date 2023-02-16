#include <stdio.h>
#include "qull.h"

int main(){
    queue q;
    init(&q);

    enqueue(&q, 1); enqueue(&q, 2);
    enqueue(&q, 3); enqueue(&q, 4); enqueue(&q, 5);
    printf("peek : %d\n", peek(&q));
    for(int i = 0; i < 5; ++i) printf("dequeue : %d\n", dequeue(&q));

    enqueue(&q, 5); enqueue(&q, 4); enqueue(&q, 3);
    printf("peek : %d\n", peek(&q));
    for(int i = 0; i < 3; ++i) printf("dequeue : %d\n", dequeue(&q));
    printf("잘못된 메모리 접근 테스트\n");
    dequeue(&q);
}
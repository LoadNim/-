#include <stdio.h>
#include "dqbq.h"

int main(){
    Queue q;
    init(&q);

    Enqueue(&q, 1); Enqueue(&q, 2);
    Enqueue(&q, 3); Enqueue(&q, 4); Enqueue(&q, 5);
    printf("peek : %d\n", QPeek(&q));
    for(int i = 0; i < 5; ++i) printf("dequeue : %d\n", Dequeue(&q));

    Enqueue(&q, 5); Enqueue(&q, 4); Enqueue(&q, 3);
    printf("peek : %d\n", QPeek(&q));
    for(int i = 0; i < 3; ++i) printf("dequeue : %d\n", Dequeue(&q));
    printf("잘못된 메모리 접근 테스트\n");
    Dequeue(&q);
}
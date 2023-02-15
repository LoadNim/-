#include <stdio.h>
#include "dq.h"

int main(){
    int temp;
    deque dq;
    init(&dq);
    insert_front(&dq, 3); insert_front(&dq, 2);
    insert_front(&dq, 1); insert_rear(&dq, 4);
    
    printf("front : %d, rear : %d\n", show_front(&dq), show_rear(&dq));
    printf("delete : %d\n", delete_front(&dq));
    printf("delete : %d\n", delete_rear(&dq));
    printf("front : %d, rear : %d\n", show_front(&dq), show_rear(&dq));
    printf("delete : %d\n", delete_rear(&dq));
    printf("delete : %d\n", delete_front(&dq));

    insert_rear(&dq, 3); insert_rear(&dq, 2);
    insert_rear(&dq, 1); insert_front(&dq, 4);
    
    printf("\nfront : %d, rear : %d\n", show_front(&dq), show_rear(&dq));
    printf("delete : %d\n", delete_front(&dq));
    printf("delete : %d\n", delete_rear(&dq));
    printf("front : %d, rear : %d\n", show_front(&dq), show_rear(&dq));
    printf("delete : %d\n", delete_rear(&dq));
    printf("delete : %d\n", delete_front(&dq));
}
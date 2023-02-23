#include <stdio.h>
#include "heap.h"

int main(){
    heap h;
    init(&h);
    insert(&h, 'B'); insert(&h, 'A');
    insert(&h, 'C'); insert(&h, 'C');
    insert(&h, 'A'); insert(&h, 'B');
    printf("삽입 후 힙 출력\n");
    for(int i = 1; i <= 6; ++i) printf("%c ", h.arr[i]);
    printf("\n삭제 순서 출력\n");
    for(int i = 0; i < 6; ++i) printf("%c ", delete(&h));
}
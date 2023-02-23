#include <stdio.h>
#include "heap.h"

int main(){
    heap h;
    init(&h);
    insert(&h, "arknights"); insert(&h, "genshin");
    insert(&h, "bluearchive"); insert(&h, "umamusme");
    insert(&h, "valorant"); insert(&h, "arknights");
    printf("삽입 후 힙 출력\n");
    for(int i = 1; i <= 6; ++i) printf("%s\n", h.arr[i]);
    printf("\n삭제 순서 출력\n");
    for(int i = 0; i < 6; ++i) printf("%s\n", delete(&h));
}
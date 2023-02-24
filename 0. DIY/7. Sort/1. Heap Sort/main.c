#include <stdio.h>
#include "heap.h"

int main(){
    heap h;
    init(&h);
    insert(&h, 4); insert(&h, 2); insert(&h, 5); insert(&h, 7); insert(&h, 1);
    insert(&h, 6); insert(&h, 0); insert(&h, 8); insert(&h, 3); insert(&h, 9);
    for(int i = 0; i < 10; ++i) printf("%d ", delete(&h));
}
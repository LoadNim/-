#include <stdio.h>
#include "cll.h"

int main(){
    list li;
    init(&li);
    int arr[5] = {1, 5, 4, 2, 3};
    insert_head(&li, arr[0]);
    insert_tail(&li, arr[1]);
    insert_tail(&li, arr[2]);
    insert_head(&li, arr[3]);
    insert_tail(&li, arr[4]);

    set_first(&li);
    printf("삽입 후 리스트 출력\n");
    for(int i = 0; i < li.num; ++i){
        printf("%d ", li.cur->data);
        set_next(&li);
    }

    for(int i = 0; i < li.num; ++i){
        set_next(&li);
        if(li.cur->data == 4) delete_node(&li);
    }
    printf("\n삭제 후 리스트 출력\n");
    set_first(&li);
    for(int i = 0; i < li.num; ++i){
        printf("%d ", li.cur->data);
        set_next(&li);
    }
}
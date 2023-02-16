#include <stdio.h>
#include "dll.h"

int main(){
    list li;
    init(&li);

    int arr[10] = {1, 2, 3, 1, 3, 3, 2, 2, 1, 2};
    for(int i = 0; i < 10; ++i) insert_node(&li, arr[i]);
    
    if(set_first(&li)){
        printf("데이터 삽입 후 출력\n");
        printf("%d ", li.cur->data);
        for(int i = 0; i < li.num-1; ++i){
            set_next(&li);
            printf("%d ", li.cur->data);
        }
    }

    set_first(&li); delete_node(&li);
    while(set_next(&li)) delete_node(&li);

    for(int i = 0; i < 10; ++i) insert_node(&li, arr[i]);
    if(set_first(&li)){
        printf("\n재사용 테스트\n");
        printf("%d ", li.cur->data);
        for(int i = 0; i < li.num-1; ++i){
            set_next(&li);
            printf("%d ", li.cur->data);
        }
    }
    set_first(&li);
    if(li.cur->data == 3) delete_node(&li);
    for(int i = 0; i < li.num-1; ++i){
        set_next(&li);
        if(li.cur->data == 3) delete_node(&li);
    }
    set_first(&li);
    printf("\n데이터 삭제 후 출력\n");
    printf("%d ", li.cur->data);
    for(int i = 0; i < li.num-1; ++i){
        set_next(&li);
        printf("%d ", li.cur->data);
    }
}
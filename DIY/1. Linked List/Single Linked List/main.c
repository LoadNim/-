#include <stdio.h>
#include <stdbool.h>
#include "sll.h"

bool for_sort(node* nd1, node* nd2){
    if(nd1->data <= nd2->data) return false;
    else return true;
}

int main(){
    list li;
    init(&li);
    init_sort(&li, for_sort);

    int arr[10] = {1, 2, 3, 1, 4, 1, 4, 2, 2, 3};
    for(int i = 0; i < 10; ++i) insert_node(&li, arr[i]);
    if(set_first(&li)){
        printf("데이터 삽입 후 출력\n");
        while(set_next(&li)){
            printf("%d ", li.cur->data);
        }
    }
    
    if(set_first(&li)){
        if(li.cur->data == 3) delete_node(&li);
        while(set_next(&li)){
            if(li.cur->data == 3) delete_node(&li);
        } 
    }

    if(set_first(&li)){
        printf("\n데이터 삭제 후 출력\n");
        printf("%d ", li.cur->data);
        while(set_next(&li)){
            printf("%d ", li.cur->data);
        }
    }
    printf("\n");
}
#include <stdio.h>
#include "ArrayList.h"

int main(){
    List li;
    ListInit(&li);
    for(int i = 1; i < 10; ++i) LInsert(&li, i);

    int sum = 0;
    int data;
    if(LFirst(&li, &data)){
        sum += data;
        while (LNext(&li, &data)){
            printf("data : %d\n", data);
            sum += data;
        }
    }
    printf("list에 저장된 값의 합 : %d\n", sum);

    if(LFirst(&li, &data)){
        if(data % 2 == 0 || data % 3 == 0) LRemove(&li);
        while (LNext(&li, &data)){
            if(data % 2 == 0 || data % 3 == 0) LRemove(&li);
        }
    }
    if(LFirst(&li, &data)){
        printf("list에 저장된 값 출력\n");
        printf("%d ", data);
        while(LNext(&li, &data)) printf("%d ", data);
    }
}
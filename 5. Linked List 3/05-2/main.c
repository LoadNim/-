#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

int main(){
    List li;
    ListInit(&li);

    LInsert(&li, 1); LInsert(&li, 2);
    LInsert(&li, 2); LInsert(&li, 3);
    LInsert(&li, 4); LInsert(&li, 4);
    LInsert(&li, 2); LInsert(&li, 3);
    LInsert(&li, 1); LInsert(&li, 1);

    int data;
    if(LFirst(&li, &data)){
        printf("데이터 삽입 후 출력\n");
        printf("%d ", data);
        while(LNext(&li, &data)){
            printf("%d ", data);
        }
        printf("\n");
    }

    if(LFirst(&li, &data)){
        if(data == 3) LRemove(&li);
        while(LNext(&li, &data)) if(data == 3) LRemove(&li);
    }

    if(LFirst(&li, &data)){
        printf("데이터 삭제 후 출력\n");
        printf("%d ", data);
        while(LNext(&li, &data)){
            printf("%d ", data);
        }
        printf("\n");
    }
}
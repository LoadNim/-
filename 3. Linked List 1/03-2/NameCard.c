#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NameCard.h"

NameCard* MakeNameCard(char* name, char* phone){
    NameCard* temp = malloc(sizeof(NameCard));
    strcpy(temp->name, name);
    strcpy(temp->phone, phone);
    return temp;
}

void ShowNameCardInfo(NameCard* pcard){
    printf("이름 : %s\n", pcard->name);
    printf("전화번호 : %s\n", pcard->phone);
}

int NameCompare(NameCard* pcard, char* name){
    if(!strcmp(pcard->name, name)){
        return 1;
    }
    else return 0;
}

void ChangePhoneNum(NameCard* pcard, char* phone){
    strcpy(pcard->phone, phone);
}
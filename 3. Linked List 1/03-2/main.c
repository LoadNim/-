#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(){
    List li;
    ListInit(&li);
    NameCard* NC;
    NC = MakeNameCard("Load Nim", "010-1234-5678");
    LInsert(&li, NC);
    NC = MakeNameCard("Load Da", "010-1111-2222");
    LInsert(&li, NC);
    NC = MakeNameCard("Load Goon", "010-0101-0101");
    LInsert(&li, NC);

    printf("one\n");
    LFirst(&li, &NC);
    if(NameCompare(NC, "Load Goon")) ShowNameCardInfo(NC);
    while(LNext(&li, &NC)){
        if(NameCompare(NC, "Load Goon")) ShowNameCardInfo(NC);
    }

    LFirst(&li, &NC);
    if(NameCompare(NC, "Load Da")) ChangePhoneNum(NC, "010-2222-3333");
    while(LNext(&li, &NC)){
        if(NameCompare(NC, "Load Da")) ChangePhoneNum(NC, "010-2222-3333");
    }

    LFirst(&li, &NC);
    if(NameCompare(NC, "Load Goon")) LRemove(&li);
    while(LNext(&li, &NC)){
        if(NameCompare(NC, "Load Goon")) LRemove(&li);
    }

    LFirst(&li, &NC);
    ShowNameCardInfo(NC);
    while (LNext(&li, &NC)) ShowNameCardInfo(NC);
}
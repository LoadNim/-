#include <stdio.h>
#include <string.h>
#include "cll.h"

void whos_next(list* li, char* name, int date);

int main(){
    list li;
    init(&li);

    emp em_1;
    strcpy(em_1.name, "Load Nim");
    em_1.emp_num = 1;

    emp em_2;
    strcpy(em_2.name, "Load Da");
    em_2.emp_num = 2;

    emp em_3;
    strcpy(em_3.name, "Load Im");
    em_3.emp_num = 3;

    emp em_4;
    strcpy(em_4.name, "Load Ya");
    em_4.emp_num = 4;

    insert_tail(&li, &em_1);
    insert_front(&li, &em_2);
    insert_tail(&li, &em_4);
    insert_front(&li, &em_3);

    printf("데이터 삽입 후 출력\n");
    set_first(&li);
    printf("이름 : %s, 사번 : %d\n", li.cur->name, li.cur->emp_num);
    for(int i = 0; i < li.num - 1; ++i){
        set_next(&li);
        printf("이름 : %s, 사번 : %d\n", li.cur->name, li.cur->emp_num);
    }

    for(int i = 0; i < li.num; ++i){
        if(li.cur->emp_num == 3){
            delete_node(&li);
            break;
        }
        set_next(&li);
    }

    printf("데이터 삭제 후 출력\n");
    set_first(&li);
    printf("이름 : %s, 사번 : %d\n", li.cur->name, li.cur->emp_num);
    for(int i = 0; i < li.num - 1; ++i){
        set_next(&li);
        printf("이름 : %s, 사번 : %d\n", li.cur->name, li.cur->emp_num);
    }

    int date;
    char name[30];
    printf("당직자 확인\n");
    printf("이름을 입력하세요 : ");
    scanf("%[^\n]s", name);
    printf("날짜를 입력하세요 : ");
    scanf(" %d", &date);
    whos_next(&li, name, date);
}

void whos_next(list* li, char* name, int date){
    while(strcmp(name, li->cur->name)) set_next(li);
    for(int i = 0; i < date; ++i) set_next(li);
    printf("%s의 %d일후 당직은 %s 입니다.", name, date, li->cur->name);
}
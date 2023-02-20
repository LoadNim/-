#include <stdio.h>
#include "swap.h"
#include "expression.h"

int main(){
    char input[100] = {0,};
    char result[100] = {0,};

    printf("수식을 입력하시오 : ");
    scanf("%s", &input);
    swap(input, result);
    printf("%s\n", result);
    expression(result);
}
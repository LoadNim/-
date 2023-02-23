#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"

void insert(heap* h, data data){
    if(h->num >= MAX){
        printf("힙이 가득 찼습니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else{
        ++h->num;
        int p_idx;
        int idx = h->num;
        while(p_idx = return_parent(h, idx)){
            if(strlen(data) > strlen(h->arr[p_idx])) break;
            h->arr[idx] = h->arr[p_idx];
            idx = p_idx;
        }
        h->arr[idx] = data;
    }
}

data delete(heap* h){
    if(isempty(h)){
        printf("힙이 비어 있습니다.\n프로그램을 종료합니다.\n");
        exit(1);
    }
    else{
        data for_return = h->arr[1];
        data last = h->arr[h->num];
        int p_idx = 1;
        int c_idx;
        while(p_idx * 2 <= h->num){
            c_idx = child_comp(h, p_idx);
            if(strlen(last) > strlen(h->arr[c_idx])){
                h->arr[p_idx] = h->arr[c_idx];
                p_idx = c_idx;
            }
            else break;
        }
        h->arr[p_idx] = last;
        --h->num;
        return for_return;
    }
}

int child_comp(heap* h, int p_idx){
    int lc_idx = 0, rc_idx = 0;
    if(p_idx * 2 <= h->num) lc_idx = return_left_child(h, p_idx);
    if(p_idx * 2 + 1 <= h->num) rc_idx = return_right_child(h, p_idx);
    else return lc_idx;
    if(strlen(h->arr[lc_idx]) > strlen(h->arr[rc_idx])) return rc_idx;
    else return lc_idx;
}

void init(heap* h){h->num = 0;}
int return_left_child(heap* h, int idx){return idx * 2;}
int return_right_child(heap* h, int idx){return idx * 2 + 1;}
int return_parent(heap* h, int idx){return idx / 2;}
bool isempty(heap* h){return h->num == 0;}
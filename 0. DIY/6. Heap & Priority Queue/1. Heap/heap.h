#ifndef HEAP_H_
#define HEAP_H_
#define MAX 100
#include <stdbool.h>

typedef char data;
typedef struct heap{
    data arr[MAX];
    int num;
}heap;

void init(heap* h);
void insert(heap* h, data data);
data delete(heap* h);
int child_comp(heap* h, int p_idx);
int return_left_child(heap* h, int idx);
int return_right_child(heap* h, int idx);
int return_parent(heap* h, int idx);
bool isempty(heap* h);
#endif
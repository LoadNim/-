#include <stdio.h>

void merge(int* arr, int start, int end);
void merge_sort(int* arr, int start, int mid, int end);

int main(){
    int arr[10] = {5, 6, 2, 3, 1, 9, 8, 7, 0, 4};
    merge(arr, 0, 9);
    for(int i = 0; i < 10; ++i) printf("%d ", arr[i]);
}

void merge(int* arr, int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        merge(arr, start, mid);
        merge(arr, mid + 1, end);
        merge_sort(arr, start, mid, end);
    }
}

void merge_sort(int* arr, int start, int mid, int end){
    int i = start, r = mid + 1, j = start;
    static int temp[10];
    while(i <= mid && r <= end){
        if(arr[i] < arr[r]) temp[j++] = arr[i++];
        else temp[j++] = arr[r++];
    }
    if(i > mid) for(r; r <= end; ++r) temp[j++] = arr[r];
    else for(i; i <= mid; ++i) temp[j++] = arr[i];
    for(i = start; i <= end; ++i) arr[i] = temp[i];
}
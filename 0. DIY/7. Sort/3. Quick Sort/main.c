#include <stdio.h>

void quick_sort(int* arr, int start, int end);
int partition(int* arr, int start, int end);
void swap(int* arr, int idx_1, int idx_2);

int main(){
    int arr[10] = {4, 5, 2, 3, 1, 2, 3, 3, 1, 0};
    quick_sort(arr, 0, 9);
    for(int i = 0; i < 10; ++i) printf("%d ", arr[i]);
}

void quick_sort(int* arr, int start, int end){
    if(start <= end){
        int pivot = partition(arr, start, end);
        quick_sort(arr, start, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

int partition(int* arr, int start, int end){
    int low, high;
    low = start + 1, high = end;
    while(low <= high){
        while(arr[start] >= arr[low] && low <= end) ++low;
        while(arr[start] <= arr[high] && high >= start + 1) --high;
        if(low <= high) swap(arr, low, high);
    }
    swap(arr, start, high);
    return high;
}

void swap(int* arr, int idx_1, int idx_2){
    int temp = arr[idx_1];
    arr[idx_1] = arr[idx_2];
    arr[idx_2] = temp;
}
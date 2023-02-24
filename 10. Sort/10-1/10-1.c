#include <stdio.h>

void quick_sort(int* arr, int start, int end);
int sel_pivot(int* arr, int start, int mid, int end);
int partition(int* arr, int start, int end);
void swap(int* arr, int idx_1, int idx_2);

int main(){
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    quick_sort(arr, 0, 14);
    for(int i = 0; i < 15; ++i) printf("%d ", arr[i]);
    printf("\n");
}

void quick_sort(int* arr, int start, int end){
    if(start <= end){
        int pivot = partition(arr, start, end);
        quick_sort(arr, start, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

int partition(int* arr, int start, int end){
    int pivot, low, high;
    pivot = sel_pivot(arr, start, (start + end) / 2, end);
    printf("pivot : %d\n", pivot);
    swap(arr, pivot, start);
    low = start + 1, high = end;
    while(low <= high){
        while(arr[start] >= arr[low]) ++low;
        while(arr[start] <= arr[high]) --high;
        if(low <= high) swap(arr, low, high);
    }
    swap(arr, start, high);
    return high;
}

int sel_pivot(int* arr, int start, int mid, int end){
    if(arr[start] > arr[mid]){
        if(arr[end] > arr[start]) return start;
        else if(arr[mid] > arr[end]) return mid;
        else return end;
    }
    else{
        if(arr[start] > arr[end]) return start;
        else if(arr[end] > arr[mid]) return mid;
        else return end;
    }
}

void swap(int* arr, int idx_1, int idx_2){
    int temp = arr[idx_1];
    arr[idx_1] = arr[idx_2];
    arr[idx_2] = temp;
}
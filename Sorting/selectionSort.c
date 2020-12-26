#include <stdio.h> 

void swap(int* a, int* b) {
    int tmp = *a; 
    *a = *b; 
    *b = tmp;
}

void selectionSort(int* arr, int len) {
    // index of the minimum element is i
    for (int i = 0; i < len; i++) {
        // if a min is not found, element stays where it is
        int minIndex = i;
        // look for minimal element out of the unsorted rest of the array
        for (int j = i + 1; j < len; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        // swap index i with the min index
        swap(&arr[i], &arr[minIndex]);
    }
}

void main() {
    int arr[5] = {5, 12, 1, 5, 2};
    selectionSort(arr, 5);
    
    for (int i = 0; i < 5; i++) {
        printf("%d \n", arr[i]);
    }
}
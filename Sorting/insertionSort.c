/*  Instructions: Inserts an element in the array, swaps backwards until part is sorted
    O(n^2) run time and O(1) additional memory
*/

#include <stdio.h> 

void swap(int* a, int* b) {
    int tmp = *a; 
    *a = *b; 
    *b = tmp;
}

void insertionSort(int arr[], int len) {
    // loop through elements
    for (int i = 0; i < len; i++) {
        // "insert" element and go backwards checking if arr[j] > arr[j - 1] for all of j 
        for (int j = i; j > 0; j--) {
            // rest must be sorted if this condition is true
            if (arr[j] > arr[j - 1]) {
                break;
            } else if (arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }
}
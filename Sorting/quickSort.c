/*  Instructions: 
    Choose an element called it the pivot, rearrange the element in the array so that all element < pivot are to the left of the pivot
    and all element >= pivot are to the right of the pivot.
    Recursively sort to the left of the pivot and to the right of the pivot. 

    How do we shoose the pivot: mid_point, first element, last element, at random or we know something about the array (median number)
    Running time O(nlog(n)) for good pivots: Defined as one thatsplits the array into equal halves. 
    T(N) = O(1) + O(n) + 2*T(N/2)
          Choosing Pivot + Rearranging + Recusion
*/
#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a; 
    *a = *b; 
    *b = tmp;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot 
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  

    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    swap (&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Low starting index, high ending index
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}

void main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]) ; 
    quickSort(arr, 0, n-1); 
    
    for (int i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }
}
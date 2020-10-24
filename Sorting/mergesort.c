/*  Instructions: 
    Recursively sort the first half of the array, then the second half, then merge the two halfs in the same array. O(1) memory
    Run time: O(n^2) for naive approach
    Run time: O(NlogN) for better approach using a new array O(n) memory
*/
#include <stdio.h> 

void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
 
    /* create temp arrays */
    int L[n1], R[n2]; 
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    /* Copy the remaining elements of L[], if there 
    are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    /* Copy the remaining elements of R[], if there 
    are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
 
/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
 
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
 
        merge(arr, l, m, r); 
    } 
} 
 

void main() {
    printf("hello world \n");
    int arr[5] = {5, 12, 1, 5, 2};
    mergeSort(arr, 0, 5 - 1);

    for (int i = 0; i < 5; i++) {
        printf("%d \n", arr[i]);
    }
}
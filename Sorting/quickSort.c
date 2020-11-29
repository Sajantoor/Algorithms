/*  Instructions: 
    Choose an element called it the pivot, rearrange the element in the array so that all element < pivot are to the left of the pivot
    and all element >= pivot are to the right of the pivot.
    Recursively sort to the left of the pivot and to the right of the pivot. 

    How do we shoose the pivot: mid_point, first element, last element, at random or we know something about the array (median number)
    Running time O(nlog(n)) for good pivots: Defined as one that splits the array into equal halves. 
    
    T(N) = O(1) + O(n) + 2*T(N/2)
          Choosing Pivot + Rearranging + Recursion
    
    Left pointer: Looks for larger element. 
    Right pointer: Looks for smaller than pivot. 

    O(nlogn) Best Case -> If middle element is median element
    O(N^2) Worst Case 
*/

#include <stdio.h>
// swaps 2 elements
void swap(int* a, int* b) {
  int tmp = *a; 
  *a = *b; 
  *b = tmp;
 }

// everything to the left of the pivot is smaller than the pivot
// everything to the right is larger than the pivot
int rearrange(int* ar, int n, int pivot_index) {
  // validate parameters -> null, out of bounds
  if (ar == NULL || n < 0 || pivot_index < 0 || pivot_index > n) {
    return -1;
  } 
  // if array is 1 the pivot will be located at the index 0, return the array, it's sorted.
  if (n == 1) {
    return 0;
  }

  // Requires 2 "pointers", one for left and one for right
  int left = 1; 
  int right = n - 1;
  int pivot = ar[pivot_index]; 
  // set pivot to be the first element in the array
  swap(&ar[0], &ar[pivot_index]);

  // While right pointer is greater than or equal to left
  while (left <= right) {
    // find first element greater than the pivot and less than the pivot
    while (ar[left] < pivot) left++; 
    while (ar[right] > pivot) right--;

    // swaps first element greater than the pivot, with first element less than the pivot
    if (left < right) {
      swap(&ar[left], &ar[right]);
      left++; right--;
    }

    if (right <= left) {
      break;
    }
  }

  // Once the left has the all the small elements and right has all the big elements, swap the pivot with the right pointer
  swap(&ar[0], &ar[right]);
  // return the new index of the pivot
  return right;
}


void quick_sort(int* ar, int n) {
  // validate params, array less than equal to 1 is already sorted or invalid so just return
  if (ar == NULL || n <= 1) {
    return;
  }
  
  // recursive step: 
  int pivotIndex = rearrange(ar, n, 0);
  // if error in rearrange, stop
  if (pivotIndex == -1) {
    return;
  }

  quick_sort(ar + pivotIndex + 1, n - pivotIndex - 1); // sort the right half wrt pivot
  quick_sort(ar, pivotIndex); // sort left half wrt pivot
}
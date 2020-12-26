#include <stdio.h> 

// Merge subroutine:
// assumption [0 - (mid-1)] is sorted
// assumption [mid - (n-1)] is sorted 
// merge both
void merge(int* ar, int n, int mid) {
  // validate parameters, merge of n = 1 is just the array
  if (ar == NULL || n <= 1 || mid <= 0 || n < mid) {
    return; 
  }

  // create 2 subarrays to store [0 - (mid -1)]: size mid & [mid - (n-1)]: (n) - mid
  int leftSize = mid; 
  int leftHalf[leftSize]; 
  int rightSize = n - mid;
  int rightHalf[rightSize];

  // copy data to subarray
  for (int i = 0; i < leftSize; i++) {
    leftHalf[i] = ar[i];
  }

  for (int i = 0; i < rightSize; i++) {
    rightHalf[i] = ar[i + mid];
  }

  // compare data and sort
  int a = 0; // array incrementer
  int i = 0; // left half incrementer
  int j = 0; // right half incrementer

  while (i < leftSize && j < rightSize) {
    // if left is smaller or equal -> put left in array 
    if (leftHalf[i] <= rightHalf[j]) {
      ar[a] = leftHalf[i];
      i++;
    } else { // right half was bigger -> put right in the array
      ar[a] = rightHalf[j]; 
      j++;
    }

    a++;
  }

  // for remaining elements -> one half is done at this point 
  while (i < leftSize) {
    ar[a] = leftHalf[i];
    a++;
    i++; 
  }

  while (j < rightSize) {
    ar[a] = rightHalf[j]; 
    a++;
    j++;
  }
}

void merge_sort(int* ar, int n) {
  // validate params 
  if (ar == NULL || n <= 1) {
    return;
  }
  
  // BASE CASE:
  // arrays less than zero are invalid 
  // arrays of 0 or 1 ore already sorted 
  
  // RECURSIVE STEP: 
  int mid = n / 2; 
  merge_sort(ar + mid, n - mid); // right half of the array
  merge_sort(ar, mid); // left half of the array
  merge(ar, n, mid);
}

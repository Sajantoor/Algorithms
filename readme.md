# Computer Science Algorithms 
A collection of algorithms, abstract data types and other code I'm learning in Computer Science.

### Table of Contents 
* [Sorting Algorithms](#Sorting-Algorithms)
* [Searching Algorithms](#Searching-Algorithms)

## Sorting Algorithms
> The following are comparision sorting algorithms.

### Merge Sort
A Divide and Conquer algorithm, recursively sort the first half of the array, then the second half, then merge the two halfs.
Split routine, `merge_sort`, and `merge` does the sorting. Merge assumes the left half and the right half of the array is sorted and sorts accordingly. 

Running time: O(nlog(n)) requiring additional O(n) memory.

Recurrence Relation:
```
T(n) = T(n/2) + T(n/2) + (n - 1)
        T(n/2) = Split routine
        (n - 1) = Worst case merging
∴ T(n) = 2T(n/2) + (n - 1)
```

Implementation:
```c
// Sort subroutine
void merge(int* ar, int n, int mid) {
    ...
}

// Split routine
void merge_sort(int* ar, int n) {
    ...
    merge_sort(ar + mid, n - mid); // right half of the array
    merge_sort(ar, mid); // left half of the array
    merge(ar, n, mid); // sort subroutine
}

```

[View code](../main/Sorting/mergeSort.c)

### Quick Sort
A Divide and Conquer algorithm, choose an element and call it the pivot, rearrange the array so all elements less than the pivot are to the left of the pivot and all elements greater than or equal to the pivot are to the right of the pivot. Recursively sort the left and right half of the array (relative to the pivot). 

How do we choose a pivot: mid point of the array, first element, last element, at random or based on information we know, median element? Running time O(nlog(n)) for good pivots: Defined as one that splits the array into equal halves (a median pivots). Worst case running time O(n^2).

Recurrence Relation:
```    
T(n) = O(1) + O(n) + 2*T(n/2)
    Choosing Pivot + Rearranging + Recursion
```

Implementation:
```c
int rearrange(int* ar, int n, int pivot_index) {
    ...
}

void quick_sort(int* ar, int n) {
    ...
    // sort the right half
    quick_sort(ar + pivotIndex + 1, n - pivotIndex - 1);
    // sort the left half
    quick_sort(ar, pivotIndex); 
}
```

[View code](../main/Sorting/quickSort.c)

### Selection Sort
An iterative algorithm, finds the smallest element and put it in first position, second smallest second position, etc. Running time: O(n^2) with O(1) memory. 

Implementation: 
```c
void selectionSort(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        ...
        for (int j = i + 1; j < len; j++) {
            ...
        }
        swap(&arr[i], &arr[minIndex]);
    }
}
```

[View code](../main/Sorting/selectionSort.c)

### Insertion Sort
An iterative algorithm, "inserts" an element in the array, swaps backwards until the array is determined to be sorted, i.e, `if arr[i] > arr[i - 1]` for all of i. Running time: O(n^2) with O(1) additional memory.

Implementation: 
```c
void insertionSort(int* arr, int len) {
    ...
    for (int i = 0; i < len; i++) {
        ...
        for (int j = i; j > 0; j--) {
            ...
        }
    }
}
```

[View code](../main/Sorting/insertionSort.c)


## Searching Algorithms

### Binary Search
A Divide and Conquer algorithm, recursively search through a **sorted** array to find an item and returns its index if found or -1 if not. If the item we are looking for is bigger than the halfway point the item must be in the larger half. If item is smaller than the halfway point, item must be in smaller half. Running time: O(log(n))

Recurrence Relation: 
```
 T(n) = T(n/2) + O(1)
```

Implementation: 
```c
int binary_search_rec(int* arr, int n, int item) {

}
```
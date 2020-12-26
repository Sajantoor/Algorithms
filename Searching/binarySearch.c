#include <stdio.h> 

// returns index of item if found or -1 if not found -> Sorted
int binary_search_rec(int* arr, int n, int item)  {
  static int i = 0; // keeps track starting position
  int half = i + (n - i) / 2; // half of the array 

  if (i <= n) { // id is in the array
    if (arr[half] == item) { // is exactly half -> return half 
      return half;
    } else if (arr[half] < item) { // id is greater - > search n to n / 2 + 1 
      i = half + 1;
      return binary_search_rec(arr, n, item);
    } else { // if ((A + half)->id > id) ->  id is less -> search 0 to n / 2 - 1
      i = 0;
      return binary_search_rec(arr, half - 1, item);
    }
  }
  // id is not in the array
  return -1;
}
// returns index of item if found or -1 if not found -> Sorted
int binary_search_rec(int* arr, int n, int start, int item)  {
  int half = start + (n - start) / 2; // half of the array 

  if (start <= n) { // id is in the array
    if (arr[half] == item) { // is exactly half -> return half 
      return half;
    } else if (arr[half] < item) { // id is greater - > search n to n / 2 + 1 
      return binary_search_rec(arr, n, half + 1, item);
    } else { // if ((A + half)->id > id) ->  id is less -> search 0 to n / 2 - 1
      return binary_search_rec(arr, half - 1, 0, item);
    }
  }
  // id is not in the array
  return -1;
}
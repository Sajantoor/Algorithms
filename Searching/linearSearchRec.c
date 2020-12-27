// returns index of item if found or -1 if not found
int linear_search_rec(int* arr, int n, int item) {
  // if length (n) is reached return -1 
  // else recurse and search again with the last element removed (n - 1)
  if (n == 0) {
    return -1;
  } else if (arr[n - 1] == item) {
    return n - 1;
  } else {
    return linear_search_rec(arr, n - 1, item);
  }
}
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "InsertionSort.h"
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

// One way Quick sort partition
template <typename T> int _partition(T arr[], int l, int r) {
  // Pick a random value from arr[l...r], set as pivot
  swap(arr[l], arr[rand() % (r - l + 1) + l]);

  T v = arr[l];
  int j = l;

  for (int i = l + 1; i <= r; i++) {
    if (arr[i] < v) {
      j++;
      swap(arr[j], arr[i]);
    }
  }

  swap(arr[l], arr[j]);
  return j;
}

template <typename T> void _quickSort(T arr[], int l, int r) {
  if (r - l <= 15) {
    insertionSort(arr, l, r);
    return;
  }

  int p = _partition(arr, l, r);

  _quickSort(arr, l, p - 1);

  _quickSort(arr, p + 1, r);
}

template <typename T> void quickSort(T arr[], int n) {
  srand(time(NULL));
  _quickSort(arr, 0, n - 1);
}

#endif // QUICKSORT_H

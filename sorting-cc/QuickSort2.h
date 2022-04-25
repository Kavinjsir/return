#ifndef QUICKSORT2_H
#define QUICKSORT2_H

#include "InsertionSort.h"
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

// Two way Quick sort partition
template <typename T> int _partition2(T arr[], int l, int r) {
  // Pick a random value from arr[l...r], set as pivot
  swap(arr[l], arr[rand() % (r - l + 1) + l]);

  T v = arr[l];

  // arr[l+1...i) <= v; arr(j...r] >= v
  int i = l + 1, j = r;
  while (true) {
    while (i <= r && arr[i] < v)
      i++;

    while (j >= l + 1 && arr[j] > v)
      j--;

    if (i > j)
      break;

    swap(arr[i], arr[j]);
    i++;
    j--;
  }

  swap(arr[l], arr[j]);

  return j;
}

template <typename T> void _quickSort2(T arr[], int l, int r) {

  if (r - l <= 15) {
    insertionSort(arr, l, r);
    return;
  }

  int p = _partition2(arr, l, r);
  _quickSort2(arr, l, p - 1);
  _quickSort2(arr, p + 1, r);
}

template <typename T> void quickSort2(T arr[], int n) {
  srand(time(NULL));
  _quickSort2(arr, 0, n - 1);
}

#endif // QUICKSORT2_H

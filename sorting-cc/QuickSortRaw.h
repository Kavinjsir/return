#ifndef QUICKSORTRAW_H
#define QUICKSORTRAW_H

#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

// One way Quick sort partition
template <typename T> int _partitionRaw(T arr[], int l, int r) {
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

template <typename T> void _quickSortRaw(T arr[], int l, int r) {
  if (l >= r)
    return;

  int p = _partitionRaw(arr, l, r);

  _quickSortRaw(arr, l, p - 1);

  _quickSortRaw(arr, p + 1, r);
}

template <typename T> void quickSortRaw(T arr[], int n) {
  srand(time(NULL));
  _quickSortRaw(arr, 0, n - 1);
}

#endif // QUICKSORTRAW_H

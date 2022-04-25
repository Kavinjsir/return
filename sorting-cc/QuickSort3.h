#ifndef QUICKSORT3_H
#define QUICKSORT3_H

#include "InsertionSort.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Three way Quick sort partition
template <typename T> void _quickSort3(T arr[], int l, int r) {

  if (r - l <= 15) {
    insertionSort(arr, l, r);
    return;
  }

  swap(arr[l], arr[rand() % (r - l + 1) + l]);

  T v = arr[l];

  int lt = l;
  int gt = r + 1;
  int i = l + 1;

  while (i < gt) {
    if (arr[i] < v) {
      swap(arr[i], arr[lt + 1]);
      i++;
      lt++;
    } else if (arr[i] > v) {
      swap(arr[i], arr[gt - 1]);
      gt--;
    } else {
      i++;
    }
  }

  swap(arr[l], arr[lt]);

  _quickSort3(arr, l, lt - 1);
  _quickSort3(arr, gt, r);
}

template <typename T> void quickSort3(T arr[], int n) {
  srand(time(NULL));
  _quickSort3(arr, 0, n - 1);
}

#endif // QUICKSORT3_H

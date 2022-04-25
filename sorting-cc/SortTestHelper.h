#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

namespace SortTestHelper {

// Generate a random array of n elements, n: [rangeL, rangeR]
int *generateRandomArray(int n, int range_l, int range_r) {

  int *arr = new int[n];

  srand(time(NULL));
  for (int i = 0; i < n; i++)
    arr[i] = rand() % (range_r - range_l + 1) + range_l;
  return arr;
}

// Generate a nearly sorted array. How?
// First generate a sorted array.
// Second swap with "swapTimes".
int *generateNearlyOrderedArray(int n, int swapTimes) {

  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    arr[i] = i;

  srand(time(NULL));
  for (int i = 0; i < swapTimes; i++) {
    int posx = rand() % n;
    int posy = rand() % n;
    swap(arr[posx], arr[posy]);
  }

  return arr;
}

// Return a new array as a copy of a
int *copyIntArray(int a[], int n) {

  int *arr = new int[n];
  copy(a, a + n, arr);
  return arr;
}

// Print arr
template <typename T> void printArray(T arr[], int n) {

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  return;
}

// Judge if arr is sorted
template <typename T> bool isSorted(T arr[], int n) {

  for (int i = 0; i < n - 1; i++)
    if (arr[i] > arr[i + 1])
      return false;

  return true;
}

// Test sorting algorithms on its correctness and performance
template <typename T>
void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {

  clock_t startTime = clock();
  sort(arr, n);
  clock_t endTime = clock();
  cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC
       << " s" << endl;

  assert(isSorted(arr, n));

  return;
}

}; // namespace SortTestHelper

#endif // SORTTESTHELPER_H

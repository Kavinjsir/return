#include "QuickSort.h"
#include "QuickSort2.h"
#include "QuickSortRaw.h"
#include "SortTestHelper.h"
#include <iostream>

using namespace std;

int main() {

  // int n = 1000000;
  int n = 1000000;

  // Test1: common test
  cout << "Test for random array, size = " << n << ", random range [0, " << n
       << "]" << endl;
  int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr2 = SortTestHelper::copyIntArray(arr1, n);
  int *arr3 = SortTestHelper::copyIntArray(arr1, n);

  SortTestHelper::testSort("Quick Sort Raw", quickSortRaw, arr1, n);
  SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
  SortTestHelper::testSort("Quick Sort 2 Way", quickSort2, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  cout << endl;

  // Test2: Sample of nearly sorted arrays
  int swapTimes = 100;
  cout << "Test for nearly ordered array, size = " << n
       << ", swap time = " << swapTimes << endl;
  arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
  arr2 = SortTestHelper::copyIntArray(arr1, n);
  arr3 = SortTestHelper::copyIntArray(arr1, n);

  SortTestHelper::testSort("Quick Sort Raw", quickSortRaw, arr1, n);
  SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
  SortTestHelper::testSort("Quick Sort 2 Way", quickSort2, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  cout << endl;

  // Test3: Sample of massive duplications
  cout << "Test for random array, size = " << n << ", random range [0,10]"
       << endl;
  arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
  arr2 = SortTestHelper::copyIntArray(arr1, n);
  arr3 = SortTestHelper::copyIntArray(arr1, n);

  SortTestHelper::testSort("Quick Sort Raw", quickSortRaw, arr1, n);
  SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
  SortTestHelper::testSort("Quick Sort 2 Way", quickSort2, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  return 0;
}

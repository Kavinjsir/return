#include "../QuickSort3.h"
#include <_stdio.h>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>

struct MinHeapNode {
  int element;
  int i;
};

void swap(MinHeapNode *x, MinHeapNode *y) {
  MinHeapNode tmp = *x;
  *x = *y;
  *y = tmp;
}

class MinHeap {
  MinHeapNode *harr;
  int heap_size;

public:
  MinHeap(MinHeapNode a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size - 1) / 2;
    while (i >= 0) {
      MinHeapify(i);
      i--;
    }
  }

  void MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l].element < harr[i].element) {
      smallest = l;
    }
    if (r < heap_size && harr[r].element < harr[smallest].element) {
      smallest = r;
    }
    if (smallest != i) {
      swap(&harr[i], &harr[smallest]);
      MinHeapify(smallest);
    }
  }

  int left(int i) { return (2 * i + 1); }

  int right(int i) { return (2 * i + 2); }

  MinHeapNode getMin() { return harr[0]; }

  void replaceMin(MinHeapNode x) {
    harr[0] = x;
    MinHeapify(0);
  }
};

FILE *openFile(char *fileName, char *mode) {
  FILE *fp = fopen(fileName, mode);
  if (fp == NULL) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }
  return fp;
}

// Merge k sorted files. Assume the filename: 1, 2, 3, ..., k
void mergeFiles(char *output_file, int n, int k) {
  FILE *in[k];
  for (int i = 0; i < k; i++) {
    char fileName[2];

    std::snprintf(fileName, sizeof(fileName), "%d", i);

    in[i] = openFile(fileName, "r");
  }

  FILE *out = openFile(output_file, "w");

  MinHeapNode *harr = new MinHeapNode[k];
  int i;
  for (i = 0; i < k; i++) {
    if (fscanf(in[i], "%d ", &harr[i].element) != 1) {
      break;
    }
    harr[i].i = i;
  }
  MinHeap hp(harr, i);

  int count = 0;

  while (count != i) {
    MinHeapNode root = hp.getMin();
    fprintf(out, "%d ", root.element);

    if (fscanf(in[root.i], "%d ", &root.element) != 1) {
      root.element = INT_MAX;
      count++;
    }

    hp.replaceMin(root);
  }

  for (int i = 0; i < k; i++) {
    fclose(in[i]);
  }

  fclose(out);
}

void createInitialRuns(char *input_file, int run_size, int num_ways) {
  FILE *in = openFile(input_file, "r");

  FILE *out[num_ways];
  char fileName[2];

  for (int i = 0; i < num_ways; i++) {
    snprintf(fileName, sizeof(fileName), "%d", i);

    out[i] = openFile(fileName, "w");
  }

  int *arr = (int *)std::malloc(run_size * sizeof(int));

  bool more_input = true;
  int next_output_file = 0;

  int i;
  while (more_input) {
    for (i = 0; i < run_size; i++) {
      if (fscanf(in, "%d ", &arr[i]) != 1) {
        more_input = false;
        break;
      }
    }
    quickSort3(arr, i);

    for (int j = 0; j < i; j++) {
      fprintf(out[next_output_file], "%d ", arr[j]);
    }
    next_output_file++;
  }

  for (int i = 0; i < num_ways; i++) {
    fclose(out[i]);
  }

  fclose(in);
}

void externalSort(char *input_file, char *output_file, int num_ways,
                  int run_size) {
  createInitialRuns(input_file, run_size, num_ways);

  mergeFiles(output_file, run_size, num_ways);
}

int main() {
  int num_ways = 10;
  int run_size = 1000;

  char input_file[] = "input.txt";
  char output_file[] = "output.txt";

  FILE *in = openFile(input_file, "w");

  srand(time(NULL));

  for (int i = 0; i < num_ways * run_size; i++) {
    fprintf(in, "%d ", rand());
  }

  fclose(in);

  externalSort(input_file, output_file, num_ways, run_size);
}

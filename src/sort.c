#include <stdio.h>
#include <string.h>

void print_arr(int *slice, int len) {
  for (int i = 0; i < len; i++) {
    printf("index: %d val: %d \n", i, slice[i]);
  }
}

static void merge(int *slice, int *work, int begin, int middle, int end) {
  int i = begin;
  int j = middle;

  for (int k = begin; k < end; k++) {
    if (i < middle && (j >= end || work[i] <= work[j])) {
      slice[k] = work[i];
      i++;
    } else {
      slice[k] = work[j];
      j++;
    }
  }
}

static void tdmerge_sort(int *slice, int *work, int begin, int end) {
  if ((end - begin) <= 1) {
    return;
  }
  int middle = (begin + end) / 2;
  tdmerge_sort(work, slice, begin, middle);
  tdmerge_sort(work, slice, middle, end);
  merge(slice, work, begin, middle, end);
}

void merge_sort(int *slice, int len) {
  int work[len];
  memcpy(work, slice, len * sizeof(int));
  tdmerge_sort(slice, work, 0, len);
}

static int partition(int *slice, int lo, int hi) {
  int pivot = slice[lo];
  int i = lo;
  int j = hi;

  while (i < j) {
    while (slice[i] < pivot) i++;

    while (slice[j] > pivot) j--;

    int tmp = slice[i];
    slice[i] = slice[j];
    slice[j] = tmp;
  }
  return j;
}

void quick_sort(int *slice, int lo, int hi) {
  if (lo >= 0 && hi >= 0 && lo < hi) {
    int p = partition(slice, lo, hi);
    quick_sort(slice, lo, p);
    quick_sort(slice, p + 1, hi);
  }
}

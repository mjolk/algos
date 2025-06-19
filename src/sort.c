#include <stdio.h>
#include <string.h>

void print_arr(char *name, int *slice, int len) {
  for (int i = 0; i < len; i++) {
    printf("name: %s index: %d val: %d \n", name, i, slice[i]);
  }
}

void insert_sort(int *slice, int len) {
  for (int i = 1; i < len; i++) {
    int k = slice[i];
    int j = i - 1;
    while (j >= 0 && slice[j] > k) {
      slice[j + 1] = slice[j];
      j--;
    }

    slice[j + 1] = k;
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

void count_sort(int *slice, int *out, int len, int k) {
  int maxk = k + 1;
  int zero[maxk];
  memset(zero, 0, maxk * sizeof(int));

  for (int i = 0; i < len; i++) {
    zero[slice[i]]++;
  }

  for (int i = 1; i < maxk; i++) {
    zero[i] += zero[i - 1];
  }

  int i = len - 1;
  while (i >= 0) {
    out[zero[slice[i]] - 1] = slice[i];
    i--;
  }
}

static void rcount_sort(int *slice, int *out, int len, int exp) {
  int i, count[10] = {0};

  for (i = 0; i < len; i++) {
    count[(slice[i] / exp) % 10]++;
  }

  for (i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (i = len - 1; i >= 0; i--) {
    out[count[(slice[i] / exp) % 10] - 1] = slice[i];
    count[(slice[i] / exp) % 10]--;
  }

  for (i = 0; i < len; i++) {
    slice[i] = out[i];
  }
}

void radix_sort(int *slice, int *out, int len, int k) {
  for (int exp = 1; k / exp > 0; exp *= 10) {
    rcount_sort(slice, out, len, exp);
  }
}

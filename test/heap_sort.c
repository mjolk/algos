#include <assert.h>

#include "../src/sort.c"

int main() {
  int slice[8] = {3, 2, 8, 1, 7, 6, 4, 5};
  int expected[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  heap_sort(slice, 8);

  for (int i = 0; i < 8; i++) {
    assert(slice[i] == expected[i]);
  }
}

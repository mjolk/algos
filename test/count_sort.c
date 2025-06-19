#include <assert.h>

#include "../src/sort.c"

int main() {
  int slice[8] = {3, 2, 8, 1, 7, 6, 4, 5};
  int expected[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  int out[8];
  count_sort(slice, out, 8, 8);

  print_arr("result", out, 8);

  for (int i = 0; i < 8; i++) {
    assert(out[i] == expected[i]);
  }
}

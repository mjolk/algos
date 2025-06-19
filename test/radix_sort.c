#include <assert.h>

#include "../src/sort.c"

int main() {
  int slice[8] = {30, 242, 8, 112, 13, 57, 1, 88};
  int expected[8] = {1, 8, 13, 30, 57, 88, 112, 242};
  int out[8] = {0};

  radix_sort(slice, out, 8, 242);

  for (int i = 0; i < 8; i++) {
    assert(out[i] == expected[i]);
  }
}

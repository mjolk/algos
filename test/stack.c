#include "../src/stack.c"

#include "../src/bst.c"
#include "assert.h"

int main() {
  struct stack s = {.len = 3, .top = -1};
  struct node nodes[3] = {{
                              .data = 1,
                          },
                          {
                              .data = 2,
                          },
                          {
                              .data = 3,
                          }};

  push(&s, &nodes[0]);
  assert(s.top == 0);
  push(&s, &nodes[1]);
  assert(s.top == 1);
  push(&s, &nodes[2]);
  assert(s.top == 2);
  pop(&s);
  assert(s.top == 1);
  pop(&s);
  assert(s.top == 0);
  pop(&s);
  assert(s.top == -1);
  assert(empty(&s) == 1);
}

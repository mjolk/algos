#include "../src/rbt.c"

#include <assert.h>
#include <stdlib.h>

#include "../src/stack.c"

int main() {
  int slice[8] = {3, 2, 8, 1, 7, 6, 4, 5};
  int expected[8] = {1, 2, 3, 4, 5, 6, 7, 8};

  struct node *root = malloc(sizeof(struct node));
  root->data = slice[0];

  for (int i = 1; i < 8; i++) {
    struct node *n = malloc(sizeof(struct node));
    n->data = slice[i];
    rbt_insert(root, n);
  }

  walk_inorder(root);

  struct stack s = {.top = -1, .len = 8};
  struct node *curr = root;
  int result[8] = {0};
  int *r = &result[0];

  while (curr || !empty(&s)) {
    while (curr) {
      push(&s, curr);
      curr = curr->left;
    }

    curr = pop(&s);
    *r++ = curr->data;

    curr = curr->right;
  }

  for (int i = 0; i < 8; i++) {
    printf("result index: %d value: %d \n", i, result[i]);
    assert(result[i] == expected[i]);
  }
}

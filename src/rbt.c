#include "bst.c"
/* left rotation
       x
        \
         y
        / \
       a   b

       y
      / \
     x   b
      \
       a
*/
static void rotate_left(struct node *root, struct node *x) {
  struct node *y = x->right;
  x->right = y->left;
  if (y->left) y->left->parent = x;
  y->parent = x->parent;
  if (!x->parent) {
    root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }

  y->left = x;
  x->parent = y;
}
/* right rotation
       x
      /
     y
    / \
   a   b

       y
      / \
     a   x
        /
        b
*/
static void rotate_right(struct node *root, struct node *x) {
  struct node *y = x->left;
  x->left = y->right;
  if (y->right) y->right->parent = x;
  y->parent = x->parent;
  if (!x->parent) {
    root = y;
  } else if (x == x->parent->right) {
    x->parent->right = y;
  } else {
    x->parent->left = y;
  }

  y->right = x;
  x->parent = y;
}

struct node *rbt_search(struct node *root, int data) {
  struct node *n = root;

  while (n != 0 && n->data != data) {
    if (data < n->data) {
      n = n->left;
    } else {
      n = n->right;
    }
  }

  return n;
}

static void balance_insert(struct node *root, struct node *new) {
  struct node *u = 0;
  while (new != root && new->parent->color > 0) {
    if (new->parent == new->parent->parent->left) {
      u = new->parent->parent->right;
      if (u->color > 0) {
        new->parent->color = 0;
        u->color = 0;
        new->parent->parent->color = 1;
        new = new->parent->parent;

      } else {
        if (new == new->parent->right) {
          new = new->parent;
          rotate_left(root, new->parent->parent);
        }

        new->parent->color = 0;
        new->parent->parent->color = 1;
        rotate_right(root, new->parent->parent);
      }
    } else {
      u = new->parent->parent->left;
      if (u->color > 0) {
        new->parent->color = 0;
        u->color = 0;
        new->parent->parent->color = 1;
        new = new->parent->parent;
      } else {
        if (new == new->parent->left) {
          new = new->parent;
          rotate_right(root, new->parent->parent);
        }

        new->parent->color = 0;
        new->parent->parent->color = 1;
        rotate_left(root, new->parent->parent);
      }
    }
  }

  root->color = 0;
}

void rbt_insert(struct node *root, struct node *new) {
  struct node *parent = 0, *n = root;

  while (n) {
    parent = n;
    if (n->data > new->data) {
      n = n->left;
    } else {
      n = n->right;
    }
  }

  new->parent = parent;
  if (!parent) {
    root = new;
  } else if (new->data < parent->data) {
    parent->left = new;
  } else {
    parent->right = new;
  }

  if (!new->parent) {
    new->color = 0;
    return;
  }

  if (!new->parent->parent) return;

  balance_insert(root, new);
}

static void balance_delete(struct node *root, struct node *x) {
  struct node *w = 0;
  while (x != root && x->color < 1) {
    if (x == x->parent->left) {
      w = x->parent->right;
      if (w->color > 0) {
        w->color = 0;
        x->parent->color = 1;
        rotate_left(root, x->parent);
        w = x->parent->right;
      }
      if (w->left->color < 1 && w->right->color < 1) {
        w->color = 1;
        x = x->parent;
      } else {
        if (w->right->color < 1) {
          w->left->color = 0;
          w->color = 1;
          rotate_right(root, w);
          w = x->parent->right;
        }

        w->color = x->parent->color;
        x->parent->color = 0;
        w->right->color = 0;
        rotate_left(root, x->parent);
        x = root;
      }
    } else {
      w = x->parent->left;
      if (w->color > 0) {
        w->color = 0;
        x->parent->color = 1;
        rotate_right(root, x->parent);
        w = x->parent->left;
      }

      if (w->right->color < 1 && w->left->color < 1) {
        w->color = 1;
        x = x->parent;

      } else {
        if (w->left->color < 1) {
          w->right->color = 0;
          w->color = 1;
          rotate_left(root, w);
          w = x->parent->left;
        }

        w->color = x->parent->color;
        x->parent->color = 0;
        w->left->color = 0;
        rotate_right(root, x->parent);
        x = root;
      }
    }
  }
  x->color = 0;
}

static void transplant(struct node *root, struct node *x, struct node *y) {
  if (!x->parent) {
    root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }

  y->parent = x->parent;
}

void rbt_delete(struct node *root, struct node *del) {
  struct node *y = del, *x = 0;
  int y_color = y->color;

  if (!del->left) {
    x = del->right;
    transplant(root, del, del->right);
  } else if (!del->right) {
    x = del->left;
    transplant(root, del, del->left);
  } else {
    y = minimum(del->right);
    y_color = y->color;
    x = y->right;
    if (y != del->right) {
      transplant(root, y, y->right);
      y->right = del->right;
      y->right->parent = y;
    } else {
      x->parent = y;
    }
    transplant(root, del, y);
    y->left = del->left;
    y->left->parent = y;
    y->color = del->color;
  }

  if (y_color == 0) balance_delete(root, x);
}

#include <stdio.h>
struct node {
  int data;
  struct node *left;
  struct node *right;
};

void walk_inorder(struct node *root) {
  if (!root) return;

  walk_inorder(root->left);
  printf("node data: %d \n", root->data);
  walk_inorder(root->right);
}

void walk_preorder(struct node *root) {
  if (!root) return;

  printf("node data: %d \n", root->data);
  walk_preorder(root->left);
  walk_preorder(root->right);
}

void walk_postorder(struct node *root) {
  if (!root) return;

  walk_postorder(root->left);
  walk_postorder(root->right);
  printf("node data: %d \n", root->data);
}

struct node *search(struct node *root, int data) {
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

// we assume there is already a tree
void insert(struct node *root, struct node *new) {
  struct node *n = root;
  struct node *parent = 0;

  while (n) {
    parent = n;
    if (n->data > new->data) {
      n = n->left;
    } else {
      n = n->right;
    }
  }

  if (parent->data > new->data) {
    parent->left = new;
  } else {
    parent->right = new;
  }
}

struct node *minimum(struct node *n) {
  while (n) {
    n = n->left;
  }

  return n;
}

struct node *in_order_successor(struct node *root, struct node *n) {
  if (!root) {
    return 0;
  }

  if (root->right && root->data == n->data) {
    return minimum(root->right);
  }

  struct node *curr = root;
  while (curr) {
    if (n->data < curr->data) {
      n = curr;
      curr = curr->left;
    } else if (n->data >= curr->data) {
      curr = curr->right;
    }
  }

  return n;
}

struct node *delete(struct node *root, struct node *del) {
  struct node *p = 0, *curr = root, *nc = 0;

  while (curr && curr->data != del->data) {
    p = curr;
    if (del->data < curr->data) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }

  if (!curr) return root;

  // tbd -> only left or right node
  if (!curr->left || !curr->right) {
    if (curr->left) {
      nc = curr->left;
    } else {
      nc = curr->right;
    }

    if (!p) return nc;

    if (curr == p->left) {
      p->left = nc;

    } else {
      p->right = nc;
    }

    return curr;  // to be deleted
    // tbd right and left node
  } else {
    p = 0;
    nc = curr->right;

    while (nc->left) {
      p = nc;
      nc = nc->left;
    }

    if (p) {
      p->left = nc->right;
    } else {
      curr->right = nc->right;
    }

    curr->data = p->data;

    return p;
  }

  return 0;
}

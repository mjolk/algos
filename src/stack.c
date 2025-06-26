
struct stack {
  int top;
  struct node *items[10];
  int len;
};

int empty(struct stack *stack) { return (stack->top < 0); }

void push(struct stack *stack, struct node *item) {
  if (stack->top >= stack->len) return;
  stack->items[++stack->top] = item;
}

struct node *pop(struct stack *stack) {
  if (stack->top < 0) return 0;
  return stack->items[stack->top--];
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
  struct node_s *next;
  struct node_s *prev;
  int val;
} node_t, *node_p;

node_p head, tail;

void initialize()
{
  head = (node_p) malloc(sizeof(node_t));
  head->prev = NULL; head->val = 0;
  tail = (node_p) malloc(sizeof(node_t));
  tail->next = tail; tail->val = 0;
  tail->prev = head; head->next = tail;
}

node_p insert_after(node_p x, int y)
{
  node_p t;
  t = (node_p) malloc(sizeof(node_t));
  t->val = y;

  x->next->prev = t;
  t->next = x->next;
  x->next = t;
  t->prev = x;
  return t;
}

void delete_next(node_p x)
{
  node_p t = x->next;
  x->next->next->prev = x;
  x->next = x->next->next;
  free(t);
}

void printvals()
{
  node_p t;
  t = head->next;
  while(t->next != t) {
    printf("%d ", t->val);
    t = t->next;
  }
  printf("\n");
}

int main()
{
  node_p new;
  initialize();
  new = insert_after(head, 1);
  new = insert_after(new, 2);
  printvals();
  delete_next(head);
  printvals();
  return 0;
}

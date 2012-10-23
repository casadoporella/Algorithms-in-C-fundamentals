#include <stdio.h>
#include <stdlib.h>

struct node { int key; struct node *next; };
struct node *head, *z, *t;

void listinitialize() {
  head = (struct node *) malloc(sizeof(*head));
  z = (struct node *) malloc(sizeof(*z));
  head->next = z; z->next = z;
}

void deletenext(struct node *x)
{
  t = x->next;
  x->next = x->next->next;
  free(t);
}

struct node* insertafter(int v, struct node* t)
{
  struct node* x = (struct node*) malloc(sizeof(struct node));
  x->key = v; 
  x->next = t->next;
  t->next = x;
  return x;
}

void printkeys()
{
  t = head->next;
  while(t->next != t) {
    printf("%d ", t->key);
    t = t->next;
  }
}

void movenexttofront(struct node* x)
{
  t = x->next;
  x->next = x->next->next;
  t->next = head->next;
  head->next = t;
}

void exchange(struct node *t, struct node *u)
{
  struct node *x, *y;
  x = t->next;
  y = u->next;
  t->next = t->next->next;
  u->next = u->next->next;
  y->next = t->next; t->next = y;
  x->next = u->next; u->next = x;
}

int main(int argc, char* argv[])
{
  struct node *ptr1, *ptr2;
  listinitialize();
  ptr1 = insertafter(1, head);
  ptr2 = insertafter(2, ptr1);
  ptr1 = insertafter(3, ptr2);
  printkeys(); printf("\n");
  exchange(head, ptr2);
  printkeys(); printf("\n");
  movenexttofront(ptr2);
  printkeys(); printf("\n");
  deletenext(head);
  printkeys();
  return 0;
}

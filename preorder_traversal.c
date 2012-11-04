#include <stdio.h>
#include <stdlib.h>

#define MAX 10 /*max no of elements in stack*/

/*tree datastructure*/
struct node {
  char value;
  struct node *r, *l; 
};
struct node *z;
void treeinit()
{
  z = (struct node *) malloc(sizeof(struct node));
  z->r = z;
  z->l = z;
}

/*stack datastructure*/
struct stack {
  struct node* stack[MAX+1];
  int p;
};

void push(struct stack *s, struct node* v)
{  s->stack[s->p++] = v; }
struct node* pop(struct stack *s)
{ return s->stack[--s->p]; }
int stackempty(struct stack *s)
{ return !s->p; }
void stackinit(struct stack *s)
{ s->p = 0; }

int node_exists(struct stack *s, struct node *p)
/*check if a particular node exists in the stack*/
{
  int i;
  for (i = 0; i < MAX; i++)
    if (s->stack[i] == p)
      return 1;
  return 0;
}

void visit(struct stack *visited, struct node *t)
/*prints out the value of the node and inserts in visited array*/
{
  printf("%c ", t->value);
  push(visited, t);
} 


void postorder(struct node* t)
/*receives a pointer to the root of a tree and prints out the node values in postorder*/
{
  struct node *x = NULL;
  struct stack node_stack, visited;
  stackinit(&node_stack);
  stackinit(&visited);
  push(&node_stack, t);
  while (!stackempty(&node_stack)) {
    x = pop(&node_stack);
    if (x->r != z && !node_exists(&visited, x->r) || x->l != z && !node_exists(&visited, x->l)) {
      push(&node_stack, x);
      if (x->r != z)
	push(&node_stack, x->r);
      if (x->l != z)
	push(&node_stack, x->l);
    } else {
      visit(&visited, x);
    }
  }
}

/*
tree:
         a
         |
    ------------
    |          |
    b          c
    |          |
  ----       -----
  |  |       |   |
  d  e       f   g
*/
int main(int argc, char *argv[])
{
  int i;
  struct node* nodes[7];
  for (i=0; i < 7; i++) {
    nodes[i] = (struct node*) malloc(sizeof(struct node));
  }
  nodes[0]->value = 'a';
  nodes[1]->value = 'b';
  nodes[2]->value = 'c';
  nodes[3]->value = 'd';
  nodes[4]->value = 'e';
  nodes[5]->value = 'f';
  nodes[6]->value = 'g';
  
  nodes[0]->l = nodes[1];
  nodes[0]->r = nodes[2];
  nodes[1]->l = nodes[3];
  nodes[1]->r = nodes[4];
  nodes[2]->l = nodes[5];
  nodes[2]->r = nodes[6];
  
  /*traverse tree*/
  postorder(nodes[0]);
  return 0;
}

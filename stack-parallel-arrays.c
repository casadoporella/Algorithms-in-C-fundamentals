/*
Linked list implementation of pushdown stacks, using parallel arrays.
 */

#include <stdio.h>

#define MAX 10
int key[MAX+2], next[MAX+2], head, z, x;

void initialize()
{
  x = 2;
  head = 0, z = 1;
  next[head] = z; next[z] = z;
}

int stackempty()
{
  return next[head] == z;
}

void push(int v) 
{
  key[x] = v;
  next[x] = next[head];
  next[head] = x; x++;
  return;
}

int pop()
{
  int t = key[next[head]];
  next[head] = next[next[head]];
  return t;
}
  
void printstack()
{
  int k = next[head];
  while (next[k] != k) {
    printf("%d ", key[k]);
    k = next[k];
  }
  printf("\n");
}

int main()
{
  initialize();
  push(1);
  push(2);
  push(3);
  printstack();
  printf("popped %d\n", pop());
  printstack();
  return 0;
}

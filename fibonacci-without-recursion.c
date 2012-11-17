#include <stdio.h>

#define MAX 25

/*stack datastructure*/
int stack[MAX+1];
int p;
void stack_init()
{ p = 0;}
void push(int v)
{ stack[p++] = v; }
int pop()
{ return stack[--p]; }
int stack_empty()
{ return !p; }

/*recursive fibonacci*/
int fib(int n)
{
  if (n <= 1)
    return 1;
  else 
    return fib(n-1) + fib(n-2);
}

/*end recursion removal*/
int fib1(int n)
{
  int  t=0;
 l: if (n <= 1) goto x;
  t+=fib1(n-1);
  n = n - 2;
  goto l;
 x:return t+1;
}

/*void eliminate recursion, simulate compiler
- push local vars, next instruction address, goto fuction
- pop next instruction address, local vars*/
int fib2(int n)
{
  int t = 0;
 l: if (n<=1) goto x;
  push(n);
  n-=1;
  goto l;
 x: t+=1;
  if (!stack_empty()) goto r;
  else return t;
 r: n = pop();
  n-=2;
  goto l;
}

/*remove first and second gotos*/
int fib3(int n)
{
  int t = 0;
 l: while (n>1) {
    push(n);
    n-=1;
  }
  t+=1;
  if (!stack_empty()) goto r;
  else return t;
 r:n = pop();
  n-=2;
  goto l;
}

/*remove remaining gotos - recurse on stack*/
int fib4(int n)
{
  int t=0;
  push(n);
  while (!stack_empty()) {
    n = pop();
    while (n > 1) {
      push(n-2);
      n-=1;
    }
    t+=1;
  }
  return t;
}

/*remove inner loop*/
int fib5(int n)
{
  int t = 0;
  push(n);
  while (!stack_empty()) {
    n = pop();
    if (n>1) {
      push(n-2);
      push(n-1);
    }
    else {
      t+=1;
    }
  }
  return t;
}

int main()
{
  printf("fib 6 is %d\n", fib(6));
  printf("fib 6 is %d\n", fib1(6));
  stack_init();
  printf("fib 6 is %d\n", fib2(6));
  stack_init();
  printf("fib 6 is %d\n", fib3(6));
  stack_init();
  printf("fib 6 is %d\n", fib4(6));
  stack_init();
  printf("fib 6 is %d\n", fib5(6));
  return 0;
}

/*computing the largest integer less than log2N (lgN)*/
#include <stdio.h>

/*recursive function*/
int f_recursive(int N)
{
  if (N/2 == 0)
    return 0;
  else
    return 1 + f_recursive(N/2);
}

/*iterative version*/
int f_iterative(int N)
{
  int n = 0;
  while (N/2 > 0) {
    n++;
    N /= 2;
  }
  return n;
}



int main()
{
  int n = 0;
  printf("Input integer N:");
  scanf("%d", &n);
  printf("Floor of lg%d is %d\n", n, f_recursive(n));
  printf("Floor of lg%d is %d\n", n, f_iterative(n));
  return 0;
}

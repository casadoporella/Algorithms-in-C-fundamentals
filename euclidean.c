/*
Euclidean algorithm for gcd
A = mk
B = nk
A - B = (m - n)k
*/

#include <stdio.h>

int gcd(int u, int v)
{
  int t, i=0;
  if (v > u) {
      t = u; u = v; v = t;
  }
  while (v > 0) { 
    printf("u - %d,  v - %d\n", u, v); i++;
    t = u % v;
    u = v;
    v = t;
  }
  printf("%d times\n", i);
  return u;
}

int main()
{
  int x, y;
  while (scanf("%d %d", &x, &y) != EOF) {
    if (x > 0 && y > 0)
      printf("%d %d %d", x, y, gcd(x, y));
  }
  return 0;
}
    

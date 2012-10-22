/*
Fill in a two-dimensional array of boolean values by setting a[i][j] to 1 if the gcd of and j is 1, otherwise to 0
*/

#include <stdio.h>
#define MAX 10

int gcd(int u, int v)
{
  int t;
  if (v > u) {
      t = u; u = v; v = t;
  }
  while (v > 0) { 
    t = u % v;
    u = v;
    v = t;
  }
  return u;
}

int main(int argc, char *argv[])
{
  int arr[MAX+1][MAX+1], i, j;
  for (i = 0; i < MAX+1; i++) {
    for (j = i; j < MAX +1; j++) {
      if (i == 0 || j == 0 || gcd(i, j) != 1) {
	arr[i][j] = 0;
	arr[j][i] = 0;
      }	else {
	arr[i][j] = 1;
	arr[j][i] = 1;
      }
    }
  }
  return 0;
}

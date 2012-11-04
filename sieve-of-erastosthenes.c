#include <stdio.h>

#define N 1000

int main(int argc, char* argv[])
{
  int i, j, arr[N+1];
  for (arr[1] = 0, i = 2; i <= N; i++) arr[i] = 1;
  for (i = 2; i <= N/2; i++)
    if (arr[i])
      for (j = 2; j <= N/i; j++)
	arr[i*j] = 0;
  for(i = 1; i < N; i++) {
    if (arr[i]) printf("%4d", i);
  }
  return 0;
}

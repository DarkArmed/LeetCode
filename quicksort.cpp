#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int a[], int n)
{
  srand(time(NULL));

  for(int i = 0; i < n; ++i)
  {
    a[i] = rand() % n;
  }
}

void swap(int &a, int &b)
{
  int temp(a);

  a = b;
  b = temp;
}

int partition(int a[], int lo, int hi)
{
  int l = lo, r = hi + 1;

  int x = a[l];

  // printf("%d %d %d\n", l, r, x);

  while(l < r)
  {
    while(a[++l] < x && l < hi);
    while(a[--r] > x && r > lo);

    if(l < r)
    {
      swap(a[l], a[r]);
    }
  }

  swap(a[lo], a[r]);
  return r;
}

void qsort(int a[], int lo, int hi)
{
  if(lo >= hi) return;

  int p = partition(a, lo, hi);

  qsort(a, lo, p - 1);
  qsort(a, p + 1, hi);
}

int main()
{
  int a[100000];
  int n = 1000;

  scanf("%d", &n);
  // while(scanf("%d", &a[n++]) != EOF);

  init(a, n);

  qsort(a, 0, n - 1);

  for(int i = 0; i < n; ++i)
  {
    printf("%d\t", a[i]);
  }

  return 0;
}
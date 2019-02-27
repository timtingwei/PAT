/* Copyright [2019] <mituh> */
/* 1029-median.cpp */
/* two pointers  */

#include <cstdio>
#include <vector>
using namespace std;
#define MaxSize 200000
int a[MaxSize];
int main() {
  int n, m, i, j, mid, sum, tmp, ans;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &tmp);
    a[i] = tmp;
  }
  scanf("%d", &m);
  mid = (n+m+1)/2;
  i = 0; j = 0; sum = 0;
  scanf("%d", &tmp);
  while (i < n && j < m) {
    if (++sum == mid) {
      ans = (a[i] <= tmp) ? a[i] : tmp; break;
    }
    if (a[i] <= tmp) {
      i++;
    } else {
      scanf("%d", &tmp); j++;
    }
  }
  if (sum != mid) {
    while (i < n) {
      if (++sum == mid) { ans = a[i]; break;}
      i++;
    }
    while (j < m) {
      if (++sum == mid) { ans = tmp; break;}
      scanf("%d", &tmp); j++;
    }
  }
  printf("%d\n", ans);
  return 0;
}

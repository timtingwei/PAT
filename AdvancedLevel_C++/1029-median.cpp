/* Copyright [2019] <mituh> */
/* 1029-median.cpp */
/* two pointers  */

#include <cstdio>
#define MaxSize 200000
long long a[MaxSize];
int main() {
  int n, m, i, j, mid, sum;
  long long tmp, ans;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  scanf("%d", &m);
  mid = (n+m+1)/2;
  i = 0; j = 0; sum = 0;
  scanf("%lld", &tmp);
  while (i < n && j < m) {
    if (++sum == mid) {
      ans = (a[i] <= tmp) ? a[i] : tmp; break;
    }
    if (a[i] <= tmp) {
      i++;
    } else {
      scanf("%lld", &tmp); j++;
    }
  }
  if (sum != mid) {
    while (i < n) {
      if (++sum == mid) { ans = a[i]; break;}
      i++;
    }
    while (j < m) {
      if (++sum == mid) { ans = tmp; break;}
      scanf("%lld", &tmp); j++;
    }
  }
  printf("%d\n", ans);
  return 0;
}

/* Copyright [2019] <mituh> */
/* 1078-hashing-25.cpp */
/* 平方探测 */

#include <cstdio>
#define MaxSize 10100
int v[MaxSize] = {0};

int IsPrime(int n) {
  int i;
  if (n == 0 || n == 1) return 0;
  for (i = 2; i*i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {
  int msize, n, i, j, a;
  scanf("%d%d", &msize, &n);
  while (!IsPrime(msize)) msize++;
  int flag = 0;
  for (i = 0; i < n; i++) {
    int ans = -1;
    scanf("%d", &a);
    for (j = 0; j <= msize; j++) {
      int pos = (a + j*j) % msize;
      if (v[pos] == 0) {
        v[pos] = a;
        ans = pos; break;
      }
    }
    if (flag) {
      printf(" ");
    } else { flag = 1; }
    if (ans == -1) {
      printf("-");
    } else { printf("%d", ans); }
  }
  return 0;
}

// Update
// Update
// Update

// Copyright [2018] <mituh>
// 1013. 数素数 (20).cpp    // 32 12 36 = 1hour
/*
  思路: 只计算前n个素数, 输出第m~n个素数,
  case6 error, 注意到 m <= n <= 10e6, 测试1 1

5 27

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
int const MAXN = 10004;
int a[MAXN];

int is_prime(int n) {
  int s = floor(sqrt(n) + 0.5);
  for (int i = 2; i <= s; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {
  int m, n, cnt = 0;
  if (scanf("%d %d", &m, &n) == 2) {
    memset(a, 0, sizeof(a));
    a[cnt++] = 2;
    int i = 3;
    for (;;) {
      if (cnt == n) break;
      if (is_prime(i)) a[cnt++] = i;   // 交换了上下两句, debug input: 1 1
      i++;
    }

// printf("cnt=%d\n", cnt);
    int pos = 0;
    for (int i = m-1; i < cnt; i++) {
      if (pos) printf(" ");
      printf("%d", a[i]);
      pos++;
      if (pos == 10) {printf("\n"); pos = 0;}
    }
    if (pos) printf("\n");
  }
  return 0;
}

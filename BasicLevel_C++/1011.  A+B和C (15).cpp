// Copyright [2018] <mituh>
// 1011.  A+B和C (15).cpp    // 33  52  = 20min
/*
  思路: 使用long long类型
*/
#include <cstdio>
#include <iostream>

int compare(int a, int b, int c) {
  long long la = a, lb = b, lc = c;
// printf("la=%lld, lb=%lld, lc=%lld, la+lb=%lld\n", la, lb, lc, la+lb);
  return la+lb > lc;
}

int main() {
  int T, a, b, c, kase = 0;
  if (scanf("%d", &T) == 1) {
    while (T--) {
      scanf("%d %d %d", &a, &b, &c);
      printf("Case #%d: ", ++kase);
      if (compare(a, b, c)) {
        printf("true\n");
      } else {
        printf("false\n");
      }
    }
  }
  return 0;
}

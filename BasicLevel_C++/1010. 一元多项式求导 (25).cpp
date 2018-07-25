// Copyright [2018] <mituh>
// 1010. 一元多项式求导 (25).cpp    // 10 33 69
/*
3 4 -5 2 6 1 -2 0

12 3 -10 1 6 0
*/
#include <stdio.h>
#define MAXN 1200

int ia[MAXN];

int main() {
  int a, n, flag = 0;
  while (scanf("%d %d", &a, &n) == 2) {
    if (n != 0) {
      if (flag == 1) printf(" ");
      printf("%d %d", a*n, n-1);
      flag = 1;
    }
  }
  if (!flag) printf("0 0");   // why? 处理只输入0 0的情况
  return 0;
}

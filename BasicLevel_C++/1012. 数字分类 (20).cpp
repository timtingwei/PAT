// Copyright [2018] <mituh>
// 1012. 数字分类 (20).cpp    // 55  28 48 = 30+20min
/*
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：  注意 2 6 6的情况A2 error

13 1 2 3 4 5 6 7 8 9 10 20 16 18
30 11 2 9.7 9

8 1 2 4 5 6 7 9 16
N 11 2 N 9

2 6 6
N 0 N N N
*/
#include <cstdio>
#include <cstring>
#include <iostream>
int const MAXN = 10000000;
int a[MAXN];
int main() {
  int n;
  if (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) { scanf("%d", &a[i]);}
    int a1 = 0, a2 = 0, a3 = 0, a5 = -1;
    double a4 = 0.0;
    int flag = 1, a2_n = 0, a4_n = 0;  // A2 6 6的情况也为0
    for (int i = 0; i < n; i++) {
      if ((a[i] % 5 == 0) && (a[i] % 2 == 0)) a1 += a[i];
      if (a[i] % 5 == 1) {
        a2 += (flag * a[i]);
        flag *= -1;
        a2_n++;
      }
      if (a[i] % 5 == 2) a3++;
      if (a[i] % 5 == 3) { a4 += a[i]; a4_n++;}
      if (a[i] % 5 == 4 && a[i] > a5) a5 = a[i];
    }

    if (a1 != 0) {
      printf("%d", a1);
    } else {
      printf("N");
    }

    if (a2_n != 0) {
      printf(" %d", a2);
    } else {
      printf(" N");
    }

    if (a3 != 0) {
      printf(" %d", a3);
    } else {
      printf(" N");
    }

    if (a4_n != 0) {
      a4 /= a4_n;
      printf(" %.1f", a4);
    } else {
      printf(" N");
    }

    if (a5 != -1) {
      printf(" %d", a5);
    } else {
      printf(" N");
    }

    printf("\n");
  }
  return 0;
}

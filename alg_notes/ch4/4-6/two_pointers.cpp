// Copyright [2018] <mituh>
// two_pointers.cpp
/*
给定一个递增的正整数数列和一个整数M, 求序列中的两个不同位置的数a和b, 使得他们的和恰好为M, 输出所有满足条件的方案
*/


/*
// 朴素版本 O(n^2)
#include <cstdio>
int main() {
  int a[] = {1, 3, 4, 5, 7, 2};
  int n = 6;
  int M = 8;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (a[i] + a[j] == M) printf("%d %d\n", a[i], a[j]);
    }
  }  // O(n^2)

  return 0;
}
*/


#include <cstdio>
int main() {
  int a[] = {1, 2, 3, 4, 5, 7}; int n = 6;
  int M = 8;

  int i = 0, j = n - 1;
  while (i < j) {
    if (a[i] + a[j] == M) {
      printf("%d %d\n", a[i], a[j]);
      i++; j--;
    } else if (a[i] + a[j] < M) {
      i++;
    } else {
      j--;
    }
  }
  return 0;
}



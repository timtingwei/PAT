# 《算法笔记》

## 4.1 排序

## 4.6 two pointers
### 4.6.1 什么是two pointers
#### 求递增数列中两个数之和为M的数a, b
```cpp
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

```
#### 合并两个递增序列
```cpp
#include <cstdio>
#include <cstring>

int merge(int a[], int b[], int c[], int n, int m) {
  int i = 0, j = 0, cnt = 0;
  while (i < n && j < m) {
    c[cnt++] = a[i] < b[j] ? a[i++]:b[j++];
  }
  while (i < n) c[cnt++] = a[i++];
  while (j < m) c[cnt++] = b[j++];

  return cnt;
}

int main() {
  int a[] = {1, 3, 4, 7}; int n = 4;
  int b[] = {2, 3, 5, 6, 8, 9}; int m = 6;
  // int a[] = {1, 2, 3}; int n = 3;
  // int b[] = {4, 5, 6, 7, 8}; int m = 5;
  int c[20]; memset(c, 0, sizeof(c));

  int cnt = merge(a, b, c, n, m);
  
  for (int i = 0; i < cnt; i++) {
    printf("%d ", c[i]);
  }
  printf("\n");
  return 0;
}
```

广义two pointers是利用问题和数列的特性, 用两个下标i, j对序列进行扫描(可以同向,也可以反向), 以较低的复杂(一般是O(n), 合起来扫描一遍, 或者如合并一样O(n+m))解决问题。
### 4.6.2 归并排序
### 4.6.3 快速排序

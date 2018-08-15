// Copyright [2018] <mituh>
// two_pointers_merge.cpp
// 假设有两个递增序列A和B, 要求将他们合并为一个递增序列C
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

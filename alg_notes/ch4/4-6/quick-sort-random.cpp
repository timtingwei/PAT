// Copyright [2018] <mituh>
// quick-sort-random.cpp
// 实现随机切割的快速排序, 规避数组等分长度差很多的情况

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>

void swap(int *A, int i, int j) {
  int tmp = A[i]; A[i] = A[j]; A[j] = tmp;
}

int Partition_random(int A[], int left, int right) {
  int p = (int)round(1.0*rand()/RAND_MAX*(right-left) + left);
  swap(A, left, p);
  int temp = A[left];
  while (left < right) {
    while (left < right && temp < A[right]) right--;
    A[left] = A[right];
    while (left < right && A[left] <= temp) left++;
    A[right] = A[left];
  }
  A[left] = temp;
  return left;
}

void quickSort(int A[], int left, int right) {
  // while (left < right) {
  if (left < right) {
    int pos = Partition_random(A, left, right);
    printf("pos = %d\n", pos);
    quickSort(A, left,    pos - 1);
    quickSort(A, pos + 1, right);
  }
}


int main() {

  int a[] = {35, 18, 16, 72, 24, 65, 12, 88, 46, 28, 55};
  int n = 11;
  for (int i = 0; i < n; i++) {
    printf("%2d ", i);
  }
  printf("\n");

  // Partition(a, 0, n-1);
  quickSort(a, 0, n-1);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}

// Copyright [2018] <mituh>
// partition.cpp

#include <cstdio>

int Partition(int a[], int n) {
  int temp = a[0];
  int left = 0, right = n - 1;
  while (left < right) {
    while (left < right && temp < a[right]) right--;
    a[left] = a[right];
    while (left < right && a[left] <= temp) left++;
    a[right] = a[left];
  }
  a[left] = temp;
  return left;
}

int main() {
  // int a[6] = {5, 3, 9, 6 , 1, 4};
  int a[] = {35, 18, 16, 72, 24, 65, 12, 88, 46, 28, 55};
  int n = 11;
  for (int i = 0; i < n; i++) {
    printf("%2d ", i);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  Partition(a, n);
  for (int i = 0; i < n; i++) {
    printf("%2d ", i);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}

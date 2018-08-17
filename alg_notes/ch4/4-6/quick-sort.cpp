// Copyright [2018] <mituh>
// quick-sort.cpp

#include <cstdio>

int Partition(int A[], int left, int right) {
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
  if (left < right) {                    // 需要判断, 否则会无限循环下去
    printf("left = %d, right = %d\n", left, right);
    int pos = Partition(A, left, right);
    quickSort(A, left,  pos - 1);
    quickSort(A, pos+1, right);
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

// Copyright [2018] <mituh>
#include <stdio.h>

const int MAXN = 100;
void merge(int A[], int L1, int R1, int L2, int R2) {
  int i = L1, j = L2;
  int temp[MAXN], index = 0;

  while (i <= R1 && j <= R2) {
    temp[index++] = (A[i] <= A[j]) ? A[i++] : A[j++];
  }
  while (i <= R1) temp[index++] = A[i++];
  while (j <= R2) temp[index++] = A[j++];

  for (int i = 0; i < index; i++) {
    A[L1 + i] = temp[i];
  }
}

void mergeSort(int A[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(A, left,    mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, mid+1, right);
  }
}


int main() {
  // int A[] = {66, 12, 33, 57, 64, 27, 18, 81, 42};
  // int left = 0, right = 9;
  int A[] = {3, 1, 2, 9, 7};
  int left = 0, right = 5;

  for (int i = 0; i < right; i++) printf("%d ", A[i]);
  printf("\n");
  mergeSort(A, left, right-1);
  for (int i = 0; i < right; i++) printf("%d ", A[i]);
  printf("\n");
  return 0;
}

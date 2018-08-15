// Copyright [2018] <mituh>
// merge-sort-no-recursive.cpp
// 归并排序非递归版本

#include <stdio.h>
#include <algorithm>
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

/*
void mergeSort(int A[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(A, left,    mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, mid+1, right);
  }
}
*/


/*
// 归并排序下标从0开始
void mergeSort(int A[], int n) {
  // step为组内元素个数, step/2是左子区间元素个数, 注意等号可以不取
  for (int step = 2; step / 2 < n; step *= 2) {
    // 每step个元素一组, 组内前step/2和后step/2个元素进行归并
    for (int i = 0; i < n; i += step) {   // 对每一组
      int mid = i + step/2 - 1;           // 左子区间元素个数为step/2
      if (mid + 1 < n) {   // 右子区间存在元素
        merge(A, i, mid, mid + 1, std::min(i+step-1, n-1));
      }
    }
  }
}
*/


/*
// 归并排序下标从1开始
void mergeSort(int A[], int n) {
  for (int step = 2; step / 2 <= n; step *= 2) {
    for (int i = 1; i <= n; i += step) {
      int mid = i + step/2 -1;
      if (mid + 1 <= n) {
        merge(A, i, mid, mid+1, std::min(i+step-1, n));
      }
    }
  }
}
*/

void show(int A[], int n) {
  for (int i = 0; i < n; i++) printf("%d ", A[i]);
  printf("\n");
}

// 归并排序每一趟结束时的序列(题中只需要)
void mergeSort(int A[], int n) {
  for (int step = 2; step / 2 < n; step *= 2) {
    for (int i = 0; i < n; i += step) {
      std::sort(A + i, A + std::min(i + step, n));
      show(A, n);
    }
  }
}

int main() {
  // int A[] = {66, 12, 33, 57, 64, 27, 18, 81, 42};
  // int left = 0, right = 9;
  int A[] = {3, 2, 9, 1, 7, 6, 5, 0};
  int left = 0, right = 8;

  for (int i = 0; i < right; i++) printf("%d ", A[i]);
  printf("\n");
  // mergeSort(A, left, right-1);
  mergeSort(A, right);
  for (int i = 0; i < right; i++) printf("%d ", A[i]);
  printf("\n");
  return 0;
}

/*
3 2 9 1 7 6 5 0 
2 3 9 1 7 6 5 0 
2 3 1 9 7 6 5 0 
2 3 1 9 6 7 5 0 
2 3 1 9 6 7 0 5 
1 2 3 9 6 7 0 5 
1 2 3 9 0 5 6 7 
0 1 2 3 5 6 7 9 
0 1 2 3 5 6 7 9
*/

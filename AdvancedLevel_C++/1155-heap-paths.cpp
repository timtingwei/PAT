/* Copyright [2019] <mituh> */
/* 1155-heap-paths.cpp */
/* 堆, 树的遍历 */


#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
#define MaxSize 10000
int n, T[MaxSize];
vector<int> v;
void precUp(int p) {
  int i, flag = 0;
  v.clear();
  while (p != 1) {
    v.push_back(T[p]);
    p /= 2;
  }
  v.push_back(T[1]);
  for (i = v.size()-1; i >= 0; i--) {
    if (flag) {
      printf(" ");
    } else {
      flag = 1;
    }
    printf("%d", v[i]);
  }
  printf("\n");
}


void PrintPath() {
  int k, i;
  k = 1;
  while (1) {
    if (pow(2, k-1)-1 < n && n <= pow(2, k)-1) {
      break;
    }
    k++;
  }
  int last, second, p;
  last = n-pow(2, k-1)+1;
  second = pow(2, k-1)-1-n/2;
  for (i = 0, p = pow(2, k-1)-1; i < second; p--, i++) {
    precUp(p);
  }
  for (p = n, i = 0; i < last; p--, i++) {
    precUp(p);
  }
}

int IsMinHeap() {
  int i, left, right;
  for (i = 1; i <= n; i++) {
    left = 2*i; right = 2*i+1;
    if (left <= n && T[left] < T[i]) return 0;
    if (right <= n && T[right] < T[i]) return 0;
  }
  return 1;
}

int IsMaxHeap() {
  int i, left, right;
  for (i = 1; i <= n; i++) {
    left = 2*i; right = 2*i+1;
    if (left <= n && T[left] > T[i]) return 0;
    if (right <= n && T[right] > T[i]) return 0;
  }
  return 1;
}

int main() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &T[i]);
  }
  PrintPath();
  if (IsMaxHeap() && !IsMinHeap()) {
    printf("Max Heap\n");
  } else if (IsMinHeap() && !IsMaxHeap()) {
    printf("Min Heap\n");
  } else {
    printf("Not Heap\n");
  }
  return 0;
}

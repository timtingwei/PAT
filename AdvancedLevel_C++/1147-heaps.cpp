/* Copyright [2019] <mituh> */
/* 1147-heaps.cpp */
/* 堆, 树的遍历 */
/* case2, 4, WA: 不明白 */

#include <cstdio>
#include <vector>
using namespace std;
#define MaxSize 10050   /* 防止最后一排溢出 */
vector<int> v;
int T[MaxSize];

void ReadData(int n) {
  int i;
  for (i = 0; i < MaxSize; i++) T[i] = -1;
  for (i = 1; i <= n; i++) { scanf("%d", &T[i]);}
}

int IsMaxHeap(int n) {
  int i, ans = 1;
  for (i = n; i > 1; i--) {
    if (T[i] > T[i/2]) {
      ans = 0; break;
    }
  }
  return ans;
}

int IsMinHeap(int n) {
  int i, ans = 1;
  for (i = n; i > 1; i--) {
    if (T[i] < T[i/2]) {
      ans = 0; break;
    }
  }
  return ans;
}

void PostOrderTraversal(int Root) {
  if (T[Root] == -1) return;
  PostOrderTraversal(Root*2);
  PostOrderTraversal(Root*2+1);
  v.push_back(T[Root]);
}

int main() {
  int m, n, i, j;
  scanf("%d%d", &m, &n);
  for (i = 0; i < m; i++) {
    ReadData(n);
    if (IsMaxHeap(n)) {
      printf("Max Heap\n");
    } else if (IsMinHeap(n)) {
      printf("Min Heap\n");
    } else {
      printf("Not Heap\n");
    }
    v.clear();
    PostOrderTraversal(1);
    int flag;
    for (j = 0, flag = 0; j < v.size(); j++) {
      if (flag) {
        printf(" ");
      } else {
        flag = 1;
      }
      printf("%d", v[j]);
    }
    printf("\n");
  }
  return 0;
}


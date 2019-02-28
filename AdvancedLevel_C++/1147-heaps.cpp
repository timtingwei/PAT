/* Copyright [2019] <mituh> */
/* 1147-heaps.cpp */
/* 堆, 树的遍历 */

#include <cstdio>
#include <vector>
using namespace std;
#define MaxSize 10050   /* 防止最后一排溢出 */
vector<int> v;
int T[MaxSize];

void ReadData(int n) {
  int i;
  for (i = 1; i <= n; i++) { scanf("%d", &T[i]);}
}

int IsMaxHeap(int Root) {
  int Left, Right;
  Left = Root*2; Right = Root*2+1;
  if (T[Left] != -1 && T[Right] != 1) {
    if (T[Root] >= T[Left] && T[Root] >= T[Right]) {
      return IsMaxHeap(Left) && IsMaxHeap(Right);
    } else { return 0; }
  } else if (T[Left] != -1 || T[Right] != -1) {
    if (T[Left] != -1) {
      if (T[Root] >= T[Left]) {
        return IsMaxHeap(Left);
      } else { return 0; }
    } else {
      if (T[Root] >= T[Right]) {
        return IsMaxHeap(Right);
      } else { return 0; }
    }
  }
  return 1;
}

int IsMinHeap(int Root) {
  int Left, Right;
  Left = Root*2; Right = Root*2+1;
  if (T[Left] != -1 && T[Right] != 1) {
    if (T[Root] <= T[Left] && T[Root] <= T[Right]) {
      return IsMinHeap(Left) && IsMinHeap(Right);
    } else { return 0; }
  } else if (T[Left] != -1 || T[Right] != -1) {
    if (T[Left] != -1) {
      if (T[Root] <= T[Left]) {
        return IsMinHeap(Left);
      } else {return 0;}
    } else {
      if (T[Root] <= T[Right]) {
        return IsMinHeap(Right);
      } else { return 0;}
    }
  }
  return 1;
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
    fill(T, T+MaxSize, -1);
    ReadData(n);
    if (IsMaxHeap(1)) {
      printf("Max Heap\n");
    } else if (IsMinHeap(1)) {
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


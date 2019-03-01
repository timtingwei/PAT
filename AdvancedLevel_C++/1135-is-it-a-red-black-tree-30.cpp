/* Copyright [2019] <mituh> */
/* 1135-is-it-a-red-black-tree-30.cpp */
/* 红黑树 */
#include <cstdio>
#include <vector>
using namespace std;
#define MaxSize 10000
int T[MaxSize];  /* 空树-1 */
int color[MaxSize];   /* 黑0 红1 */
int Cnt[MaxSize];     /* 每个结点以下的黑结点 */
void Insert(int Root, int X, int c) {
  if (T[Root] == -1) {
    T[Root] = X; color[Root] = c;    /* 下标都为Root */
    return;
  }
  if (X <= T[Root]) {
    Insert(Root*2, X, c);
  } else {
    Insert(Root*2+1, X, c);
  }
}

int GetBiggerCnt(int Root) {
  if (T[Root] == -1) {
    return 0;
  }
  int left_cnt, right_cnt, c;
  left_cnt = GetBiggerCnt(Root*2);
  right_cnt = GetBiggerCnt(Root*2+1);
  c = (left_cnt >= right_cnt) ? left_cnt : right_cnt;
  if (color[Root] == 1) { c++; }   /* 黑结点加本身 */
  Cnt[Root] = c;
  return c;
}

int Judge() {
  if (color[1] == 1) return 0;   /* 根结点为红 */
  int i;
  fill(Cnt, Cnt+MaxSize, 0);
  GetBiggerCnt(1);
  for (i = 1; i < MaxSize; i++) {
    if (T[i] != -1) {
      if (color[i] == 1) {   /* 红色结点左右孩子存在红 */
        if (T[i*2] != -1 && color[i*2] == 1) {
          printf("red node's left child is red\n");
          return 0;
        }
        if (T[i*2+1] != -1 && color[i*2+1] == 1) {
          printf("red node's right child is red\n");
          return 0;
        }
      }
      if ((T[i*2] != -1 && T[i*2+1] != -1) && (Cnt[i*2] != Cnt[i*2+1])) {
        /* 左右孩子存在, 但下面的黑色结点数不同 */
        printf("cnt different\n");
        return 0;
      }
    }
  }
  return 1;
}

/* 测试树 */
void preOrder(int Root) {
  if (T[Root] == -1) return;
  printf("%d ", T[Root]);
  printf("%d ", color[Root]);
  preOrder(Root*2);
  preOrder(Root*2+1);
}

void BuildTree(int n) {
  int i, tmp, c;
  fill(T, T+MaxSize, -1);
  fill(color, color+MaxSize, -1);
  for (i = 0; i < n; i++) {
    scanf("%d", &tmp);
    c = 0;
    if (tmp < 0) {
      c = 1; tmp = -tmp;
    }
    Insert(1, tmp, c);  /* 带颜色插入 */
  }
}

int main() {
  int n, m, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &m);
    BuildTree(m);
    preOrder(1);
    printf("\n");
    if (Judge()) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}

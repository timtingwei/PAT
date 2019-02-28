/* Copyright [2019] <mituh> */
/* 1127-zigzagging-on-a-tree.cpp */
/* 后序中序 建树, 遍历完全二叉树  */

#include <cstdio>
#include <cmath>
#define MaxSize 50
int in[MaxSize], post[MaxSize], T[MaxSize];

void order(int index, int inL, int postL, int n) {
  if (n == 0) return;
  if (n == 1) { T[index] = in[inL]; return; }
  int i, Root, Left, Right;
  Root = post[postL + n-1];
  T[index] = Root;
  for (i = inL; in[i] != Root; i++) {}
  Left = i - inL;
  Right = n-Left-1;
  order(index*2, inL, postL, Left);
  order(index*2+1, inL+Left+1, postL+Left, Right);
}

int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &in[i]);
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &post[i]);
  }
  for (i = 0; i < MaxSize; i++) {T[i] = -1;}
  order(1, 0, 0, n);;
  int k = 1, flag = 0, pre = 1, ok = 1, temp;
  printf("%d", T[1]);
  while (ok) {
    k++;   /* 下一排 */
    ok = 0;
    if (flag == 0) {
      for (temp = pre*2, i = 0; i < pow(2, k-1); i++, temp++) {
        if (T[temp] != -1) {
          ok = 1;
          printf(" %d", T[temp]);
        }
      }
      pre = temp - 1;
      flag = 1;
    } else {
      for (temp = pre*2+1, i = 0; i < pow(2, k-1); i++, temp--) {
        if (T[temp] != -1) {
          ok = 1;
          printf(" %d", T[temp]);
        }
      }
      pre = temp + 1;
      flag = 0;
    }
  }
  printf("\n");
  return 0;
}

/* Copyright [2019] <mituh> */
/* 1138-postorder-traversal-25.cpp */
/* 先序中序转后序  */

#include <cstdio>
#define MaxSize 50050
int pre[MaxSize], in[MaxSize], post[MaxSize];
void order(int preL, int inL, int postL, int n) {
  if (n == 0) { return;}
  if (n == 1) { post[postL] = pre[preL]; return;}
  int i, Root, Left, Right;
  Root = pre[preL];
  post[postL+n-1] = Root;
  for (i = inL; in[i] != Root; i++) { }
  Left = i - inL;      /* 左子树的个数, 要减去初始位置 */
  Right = n-1-Left;    /* 相对的减去左子树数量 */
  order(preL+1, inL, postL, Left);
  order(preL+Left+1, inL+Left+1, postL+Left, Right);
}

int main() {
  int i, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &pre[i]);
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &in[i]);   /* 读入中序序列 */
  }
  order(0, 0, 0, n);
  printf("%d\n", post[0]);
  return 0;
}

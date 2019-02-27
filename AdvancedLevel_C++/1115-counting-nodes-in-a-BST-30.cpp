/* Copyright [2019] <mituh> */
/* 1115-counting-nodes-in-a-BST-30.cpp */
/* BST插入 + DFS  */

#include <cstdio>
#include <cstdlib>
#define MaxSize 1050
typedef struct TNode *BST;
struct TNode {
  BST Left, Right;
  int Data;
};

/*
BST CreateTree() {
  BST T;
  T = (BST)malloc(sizeof(struct TNode));
  T->Left = T->Right = NULL;
  return T;
}
*/

BST Insert(BST T, int X) {
  if (T == NULL) {
    T = (BST)malloc(sizeof(struct TNode));
    T->Left = T->Right = NULL;
    T->Data = X;
  } else {
    if (X <= T->Data) {
      T->Left = Insert(T->Left, X);
    } else {
      T->Right = Insert(T->Right, X);
    }
  }
  return T;
}

BST BuildTree(int n) {
  /* 不存入第一个结点, 可以先将T定义成NULL, 在Insert中初始化*/
  int i, X; BST T = NULL;
  /* T = CreateTree(); */
  /* scanf("%d", &X); */
  /* T->Data = X;*/        /* 只能这样先存入第一个结点吗? */
  for (i = 0; i < n; i++) {
    scanf("%d", &X);
    T = Insert(T, X);
  }
  return T;
}
int maxd = 0, n1, n2, Num[MaxSize] = {0};
void dfs(BST T, int depth) {
  if (!T) return;
  Num[depth]++;
  if (depth > maxd) maxd = depth;
  dfs(T->Left, depth+1);
  dfs(T->Right, depth+1);
}

void PrintLevelSum() {
  n1 = Num[maxd];
  if (maxd == 1) {
    n2 = 0;
  } else {
    n2 = Num[maxd-1];
  }
  printf("%d + %d = %d\n", n1, n2, n1+n2);
}

int main() {
  int n; BST T;
  scanf("%d", &n);
  T = BuildTree(n);
  dfs(T, 1);
  PrintLevelSum();
  return 0;
}



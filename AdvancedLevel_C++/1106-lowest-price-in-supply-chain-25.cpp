/* Copyright [2019] <mituh> */
/* 1106-lowest-price-in-supply-chain-25.cpp */
/*  */
/*
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0

Sample Output:
1.8362 2
*/

#include <stdio.h>
#define MaxSize 100050
int G[MaxSize][MaxSize];
int visited[MaxSize];
int depth[MaxSize];
int leaves[MaxSize];

/*
void InitG(int N) {
  int v, w;
  for (v = 0; v < N; v++) {
    for (w = 0; w < N; w++) {
      G[v][w] = 0;
    }
  }
}
*/

void InitVDL(int N) {
  int i;
  for (i = 0; i < N; i++) {
    visited[i] = 0;
    depth[i] = 0;
    leaves[i] = 0;
  }
}

void DFS(int V, int N) {
  int W;
  visited[V] = 1;
  for (W = 0; W < N; W++) {
    if (G[V][W] == 1 && !visited[W]) {
      depth[W] = depth[V] + 1;
      DFS(W, N);
    }
  }
}

int main() {
  int N, K, i, j, t, cnt_l, min, Cnt;
  double P, r, Lowest;
  cnt_l = Cnt = 0;
  scanf("%d %lf %lf", &N, &P, &r);
  /* InitG(N); */
  InitVDL(N);
  for (i = 0; i < N; i++) {
    scanf("%d", &K);
    for (j = 0; j < K; j++) {
      scanf("%d", &t);
      G[i][t] = 1;
    }
    if (K == 0) {
      leaves[cnt_l++] = i;   /* 记录叶结点 */
    }
  }
  depth[0] = 0;
  DFS(0, N);   /* 深度遍历改变depth, leaves数组 */
  min = leaves[0];   /* 找出深度最小的下标 */
  for (i = 1; i < cnt_l; i++) {
    if (depth[leaves[i]] < depth[min]) {
      min = leaves[i];
    }
  }
  for (i = 0; i < cnt_l; i++) {
    if (depth[leaves[i]] == depth[min]) {
      Cnt++;
    }
  }
  /* 计算最终结果 */
  Lowest = P;
  for (i = 0; i < depth[min]; i++) {
    Lowest *= (1+r/100);    /* 注意百分比!! */
  }
  printf("%.4lf %d\n", Lowest, Cnt);
  return 0;
}

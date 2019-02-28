/* Copyright [2019] <mituh> */
/* 1118-birds-in-forest-25.cpp */
/* 并查集 */
/*
5
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
0
2
10 5
3 7
*/
#include <cstdio>
#include <vector>
using namespace std;
#define MaxSize 10050
#define INFI 99999
int T[MaxSize];    /* int T[MaxSize] = {INFI}为什么不行? */
int have[MaxSize];

void Init() {
  int i;
  for (i = 0; i < MaxSize; i++) {
    T[i] = INFI;    /* 为什么需要这样? */
    have[i] = 0;
  }
}

int GetRoot(int c) {
  while (T[c] >= 0) c = T[c];
  return c;
}

int Find(int c) {
  int Root;
  if (T[c] == INFI) {
    T[c] = -1; Root = c;
  } else {
    Root = GetRoot(c);
  }
  return Root;
}

int Union(int R1, int R2) {
  if (R1 == R2) return R1;
  int Root;
  if (T[R1] < T[R2]) {
    T[R1] += T[R2]; T[R2] = R1; Root = R1;
  } else {
    T[R2] += T[R1]; T[R1] = R2; Root = R2;
  }
  return Root;
}

int main() {
  int i, j, n, k, bird, Root, Cnt = 0, tree_Cnt = 0;
  scanf("%d", &n);
  Init();
  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    if (k == 0) continue;
    scanf("%d", &bird);
    if (!have[bird]) { Cnt++; have[bird] = 1; }
    Root = Find(bird);
    for (j = 1; j < k; j++) {
      scanf("%d", &bird);
      if (!have[bird]) { Cnt++; have[bird] = 1; }
      Root = Union(Root, Find(bird));
    }
  }
  for (i = 0; i < Cnt; i++) {
    if (T[i] < 0) tree_Cnt++;
  }
  printf("%d %d\n", tree_Cnt, Cnt);
  int Q, b1, b2;
  scanf("%d", &Q);
  for (i = 0; i < Q; i++) {
    scanf("%d %d", &b1, &b2);
    if (Find(b1) == Find(b2)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}

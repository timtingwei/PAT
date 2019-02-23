/* Copyright [2019] <mituh> */
/* 1107-social-clusters-30.cpp */
/* 并查集 */
/*
Find:Hash表找某种爱好第一次出现的人下标, Union: 按秩合并两个人结点,
找到根结点用vector保存其相反数, 排序后打印

注意: 数组T中, 每个人初始独立成为一个根结点. -2代表为根结点, 规模大小为2
*/

/*
Sample Input:
9
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
2: 6 4

Sample Output:
3
4 3 1
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MaxSize 1050

vector<int> first(MaxSize);
vector<int> T(MaxSize);
vector<int> hobbies;   /* 临时存放读入的某人爱好 */

void InitFirstAndTree(int N) {
  int i;
  for (i = 1; i <= N; i++) {
    T[i] = -1;
  }
  for (i = 0; i < MaxSize; i++) {
    first[i] = -1;
  }
}

int GetRoot(int p) {
  while (T[p] >= 0) {
    p = T[p];
  }
  return p;
}

int Find(int h, int p) {
  /* 找到爱好第一次出现的人的下标 */
  if (first[h] == -1) {   /* 该爱好未出现过 */
    first[h] = p;         /* 自身下标 */
  }
  return first[h];
}

void Union(int N1, int N2) {
  /* 按秩序合并两个结点 */
  int R1, R2;
  R1 = GetRoot(N1);
  R2 = GetRoot(N2);
  if (R1 == R2) return;
  if (T[R1] < T[R2]) {   /* 比较秩大小, 而不是下标!! */
    T[R1] += T[R2];
    T[R2] = R1;
  } else {
    T[R2] += T[R1];
    T[R1] = R2;
  }
}

void ReadHobby(int N, int p) {
  /* N个数, p人下标 */
  int i, h;
  getchar();
  hobbies.clear();
  for (i = 0; i < N; i++) {
    scanf("%d", &h);
    hobbies.push_back(h);
  }
  for (i = 0; i < N; i++) {
    Union(p, Find(hobbies[i], p));
  }
}

bool cmp(int a, int b) {
  return a >= b;
}

void PrintClusters(int N) {
  int i, flag;
  vector<int> clusters;
  for (i = 1; i <= N; i++) {
    if (T[i] <= 0) {
      clusters.push_back(-T[i]);   /* 别忘记负数 */
    }
  }
  sort(clusters.begin(), clusters.end(), cmp);
  printf("%lu\n", clusters.size());
  flag = 0;
  for (i = 0; i < clusters.size(); i++) {
    if (flag) {
      printf(" ");
    } else {
      flag = 1;
    }
    printf("%d", clusters[i]);
  }
  printf("\n");
}


int main() {
  int N, i, K;
  scanf("%d", &N);
  InitFirstAndTree(N);
  for (i = 1; i <= N; i++) {
    scanf("%d", &K);
    ReadHobby(K, i);
  }
  PrintClusters(N);
  return 0;
}

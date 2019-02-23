/* Copyright [2019] <mituh> */
/* 1107-social-clusters-30.cpp */
/* 并查集 */

/*
Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

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
  while (p >= 0) {
    p = T[p];
  }
  return p;
}

int Find(int h, int i) {
  int p;
  p = first[h];
  if (p == -1) {
    first[h] = i;    /* 记录该爱好第一次出现 对应人的下标 */
    return first[h];
  }
  return GetRoot(p);
}

void Union(int R1, int R2) {
  if (R1 < R2) {
    T[R1] += T[R2];
    T[R2] = R1;
  } else if (R2 < R1) {
    T[R2] += T[R1];
    T[R1] = R2;
  } else {  /* R1 == R2*/
    return;
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
  /* 先合并第一个结点 */
  Union(p, Find(hobbies[0], p));
  for (i = 1; i < N; i++) {
    Union(T[p], Find(hobbies[i], p));
  }
}

bool cmp(int a, int b) {
  return b >= a;
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

/* Copyright [2019] <mituh> */
/* 1109-group-photo-25.cpp */
/* 排序 */


#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
  string name;
  int height;
};
#define MaxSize 10050
vector<Node> v;
vector<int> vnum;     /* 从后到前每行个数 */
Node vrow[MaxSize];   /* 每行结点数组 */
Node temp[MaxSize];   /* 每行结点临时 */

void GetVnum(int N, int K, int M) {
  int last, i;
  last = N - K * M;
  vnum.push_back(last);
  for (i = 0; i < K-1; i++) {
    vnum.push_back(M);
  }
}

void ReadData(int N) {
  int i, height;
  string name;
  v.resize(N);
  for (i = 0; i < N; i++) {
    cin >> name >> height;
    v.push_back(Node(name, height));
  }
}

bool cmp(Node n1, Node n2) {
  if (n1.height != n2.height) {
    return n1.heght > n2.height;
  } else {
    return n1.name < n2.name;    /* 有空试试strcmp比较 */
  }
}

void Arrange(Node vrow[], int N) {
  int center, p, i;
  center = N/2;   /* N/2+1-1下标 */

  temp[center] = vrow[0];
  /* 左边 */
  for (i = 1, p = center-1; p >= 0; i += 2, p--) {
    temp[p] = vrow[i];
  }
  /* 右边 */
  for (i = 2, p = center+1; p < N; i += 2, p++) {
    temp[p] = vrow[i];
  }
  for (i = 0; i < N; i++) {
    vrow[i] = temp[i];
  }
}

void Arrange_test(int vrow[], int N) {
  int center, p, i;
  center = N/2;

  temp[center] = vrow[0];
  for (i = 1, p = center-1; p >= 0; i += 2, p--) {
    temp[p] = vrow[i];
  }
  for (i = 2, p = center+1; p < N; i += 2, p++) {
    temp[p] = vrow[i];
  }
  for (i = 0; i < N; i++) {
    vrow[i] = temp[i];
    printf("%d ", vrow[i]);
  }
}

int main() {
  int a[] = {190, 188, 186, 175, 170};
  Arrange_test(a, 5);
  return 0;
}

void PrintV(Node vrow[], int N) {
  int i, flag;
  flag = 0;
  for (i = 0; i < N; i++) {
    if (flag) {
      cout << " ";
    } else {
      flag = 1;
    }
    cout << vrow[i].name;
  }
  cout << endl;
}

/*
int main() {
  int N, K, M, i, j, k, each;
  scanf("%d %d", &N, &K);
  M = N / K;
  GetVnum(N, K, M);
  ReadData(N);
  sort(v.begin(), v.end(), cmp);
  i = 0;
  for (i = 0, j = 0; i < vnum.size(); j++) {
    each = vnum[j];
    for (k = 0; k < each; k++, i++) {
      vrow[k] = v[i];
    }
    Arrange(vrow, each);
    PrintV(vrow, each);
  }
  return 0;
}
*/

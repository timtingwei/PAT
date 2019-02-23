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
vector<Node> vrow;   /* 每行结点数组 */
vector<Node> new_vrow;
int temp[MaxSize];   /* 每行结点下标临时 */

void GetVnum(int N, int K, int M) {
  int last, i;
  last = N - K * M + M;
  vnum.push_back(last);
  for (i = 0; i < K-1; i++) {
    vnum.push_back(M);
  }
}

void ReadData(int N) {
  int i, height;
  string name;
  for (i = 0; i < N; i++) {
    cin >> name >> height;
    Node n;
    n.name = name; n.height = height;
    v.push_back(n);
    /* v.push_back({name, height}); */
  }
}

bool cmp(Node n1, Node n2) {
  if (n1.height != n2.height) {
    return n1.height > n2.height;
  } else {
    return n1.name < n2.name;    /* 有空试试strcmp比较 */
  }
}

vector<Node> Arrange(vector<Node> vrow, int N) {
  int center, p, i;
  vector<Node> new_vrow;
  center = N/2;   /* N/2+1-1下标 */

  temp[center] = 0;
  /* 左边 */
  for (i = 1, p = center-1; p >= 0; i += 2, p--) {
    temp[p] = i;
  }
  /* 右边 */
  for (i = 2, p = center+1; p < N; i += 2, p++) {
    temp[p] = i;
  }
  for (i = 0; i < N; i++) {
    new_vrow.push_back(vrow[temp[i]]);   /* 如果直接在数组中赋值, 需要重载= !!*/
  }
  return new_vrow;
}

void PrintV(vector<Node> vrow, int N) {
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


int main() {
  int N, K, M, i, j, k, each;
  scanf("%d %d", &N, &K);
  M = N / K;
  GetVnum(N, K, M);
  ReadData(N);
  sort(v.begin(), v.end(), cmp);
  for (i = 0, j = 0; j < vnum.size(); j++) {
    each = vnum[j];
    vrow.clear();
    for (k = 0; k < each; k++, i++) {
      vrow.push_back(v[i]);
    }
    new_vrow = Arrange(vrow, each);
    PrintV(new_vrow, each);
  }
  return 0;
}


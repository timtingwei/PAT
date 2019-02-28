/* Copyright [2019] <mituh> */
/* 1121-damn-single.cpp */
/* set应用 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MaxSize 100050
int couple[MaxSize];        /* 记婚姻关系 */
int visited[MaxSize] = {0}; /* 记到场人 */
vector<int> single, v;

bool cmp(int a, int b) {return a < b;}

int main() {
  int n, m, i, id, id2;
  scanf("%d", &n);
  fill(couple, couple+MaxSize, -1);
  fill(visited, visited+MaxSize, 0);
  for (i = 0; i < n ; i++) {
    scanf("%d%d", &id, &id2);
    couple[id] = id2;
    couple[id2] = id;
  }

  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &id); visited[id] = 1;
    v.push_back(id);
  }
  for (i = 0; i < m; i++) {
    id = v[i];
    /* 没结婚, 或者伴侣没来 */
    if (couple[id] == -1 || (couple[id] != -1 && visited[couple[id]] == 0)) {
      single.push_back(id);
    }
  }
  sort(single.begin(), single.end(), cmp);
  printf("%lu\n", single.size());
  int flag = 0;
  for (i = 0; i < single.size(); i++) {
    if (flag) {
      printf(" ");
    } else {
      flag = 1;
    }
    printf("%05d", single[i]);
  }
  return 0;
}

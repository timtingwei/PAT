/* Copyright [2019] <mituh> */
/* 1131-subway-map-30.cpp */
/* 图的dfs */
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
#define MaxSize 10000
int visited[MaxSize] = {0};
vector<vector<int>> G(MaxSize);
int minCnt, minTransfer, start, end1;
vector<int> tempPath, path;
unordered_map <int, int> line;

int CntTransfer(vector<int> a) {
  int i, cnt = -1, preLine = 0;
  for (i = 1; i < a.size(); i++) {
    if (line[a[i-1]*10000+a[i]] != preLine) {
      cnt++;
      preLine = line[a[i-1]*10000+a[i]];
    }
  }
  return cnt;
}

void dfs(int node, int cnt) {
  /* 调用 dfs(start, 0); */
  if ((node == end1) &&
      (cnt < minCnt ||
       (cnt == minCnt && CntTransfer(tempPath) < minTransfer))) {
    minCnt = cnt;
    minTransfer = CntTransfer(tempPath);
    path = tempPath;
  }
  if (node == end1) return;
  int i;
  for (i = 0; i < G[node].size(); i++) {
    if (visited[G[node][i] == 0) {
      visited[G[node][i]] = 1;
      tempPath.push_back(G[node][i]);
      dfs(G[node][i], cnt+1);
      visited[G[node][i]] = 0;
      tempPath.pop_back();    /* 与visit同时进, 同时出! */
    }
  }
}

int main() {
  int i, j, n, m, k, pre, temp;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &m, &pre);
    for (j = 1; j < m; j++) {
      scanf("%d", &temp);
      G[pre].push_back(temp);
      G[temp].push_back(pre);
      line[pre*10000+temp] = line[temp*10000+pre] = i+1;
      pre = temp;   /* pre在循环中需要移动 */
    }
  }
  scanf("%d", &k);
  for (i = 0; i < k; i++) {
    scanf("%d%d", &start, &end1);
    minCnt = 99999; minTransfer = 99999;
    tempPath.clear();
    tempPath.push_back(start); /* 别忘了清空tempPath */
    visited[start] = 1;
    dfs(start, 0);
    visited[start] = 0;
    printf("%d\n", minCnt);
    int preLine = 0, preTransfer = start;
    for (j = 1; j < path.size(); j++) {
      if (line[path[j-1]*10000+line[j]] != preLine) {
        if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n",
                                 preLine, preTransfer, path[j-1]);
        preLine = line[path[j-1]*10000+line[j]];
        preTransfer = path[j-1];
      }
    }
    printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
  }
  return 0;
}

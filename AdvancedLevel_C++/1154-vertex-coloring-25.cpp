/* Copyright [2019] <mituh> */
/* 1154-vertex-coloring-25.cpp */
/* bfs宽度遍历 */
/*
 1, 用宽度遍历比dfs更好; 2, color在int范围之内, 只能用map开; 3, bfs是队列
*/
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
#define MaxSize 10000
#define INF 99999

// vector<vector<int> > G(MaxSize);
vector<int> G[MaxSize];

int ok, cnt, color[MaxSize], visited[MaxSize] = {0};
unordered_map<int, int> mp_have;
/*
void dfs(int V) {
  int i, W;
  visited[V] = 1;
  for (i = 0; i < G[V].size(); i++) {
    W = G[V][i];
    if (!visited[W]) {
      if (color[W] != color[V]) {
        dfs(W);
      } else {
        visited[W] = 1;
        ok = 0;
      }
    }
  }
}
*/

/*
// 栈版
vector<int> v;
void bfs(int S) {
  int i, V, W;
  fill(visited, visited+MaxSize, 0);   // ?
  v.clear();
  v.push_back(S);
  while (v.size() != 0) {
    V = v.back(); v.pop_back();
    visited[V] = 1;
    for (i = 0; i < G[V].size(); i++) {
      W = G[V][i];
      if (!visited[W]) {
        if (color[V] != color[W]) {
          v.push_back(W);
        } else {
          ok = 0; return;
        }
      }
    }
  }
}
*/

/*
void bfs(int S) {
  int i, V, W; queue<int> q;   // q暂时不能初始化
  fill(visited, visited+MaxSize, 0);
  q.push(S);
  while (!q.empty()) {
    V = q.front(); q.pop();
    visited[V] = 1;
    for (i = 0; i < G[V].size(); i++) {
      W = G[V][i];
      if (!visited[W]) {
        if (color[V] != color[W]) {
          q.push(W);
        } else {
          ok = 0; return;
        }
      }
    }
  }
}
*/

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, m, i, j, V, W;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d%d", &V, &W);
    G[V].push_back(W); G[W].push_back(V);
  }
  int K; scanf("%d", &K);
  for (i = 0; i < K; i++) {
    // fill(have, have+MaxSize, 0);
    // fill(visited, visited+MaxSize, 0);
    // fill(color, color+MaxSize, 0);
    for (j = 0; j < MaxSize; j++) {
      visited[j] = 0; color[j] = 0;
    }
    mp_have.clear();
    ok = 1; cnt = 0;
    for (j = 0; j < n; j++) {
      scanf("%d", &color[j]);
      if (!mp_have[color[j]]) {
        cnt++;
        mp_have[color[j]] = 1;
      }
    }
    // dfs(0);
    bfs(0);
    if (ok) {
      printf("%d-coloring\n", cnt);
    } else {
      printf("No\n");
    }
  }
  return 0;
}

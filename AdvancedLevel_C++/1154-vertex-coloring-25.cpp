/* Copyright [2019] <mituh> */
/* 1154-vertex-coloring-25.cpp */
/* bfs宽度遍历 */

#include <cstdio>
#include <vector>
using namespace std;
#define MaxSize 100000
#define INF 99999

// vector<vector<int> > G(MaxSize);
vector<int> G[MaxSize];

int ok, cnt, color[MaxSize], have[MaxSize], visited[MaxSize] = {0};
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
int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, m, i, j, V, W, c;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d%d", &V, &W);
    G[V].push_back(W); G[W].push_back(V);
  }
  int K; scanf("%d", &K);
  for (i = 0; i < K; i++) {
    fill(have, have+MaxSize, 0);
    fill(visited, visited+MaxSize, 0);
    fill(color, color+MaxSize, 0);
    ok = 1; cnt = 0;
    for (j = 0; j < n; j++) {
      scanf("%d", &color[j]);
      if (!have[color[j]]) {
        cnt++;
        have[color[j]] = 1;
      }
    }
    dfs(0);
    if (ok) {
      printf("%d-coloring\n", cnt);
    } else {
      printf("No\n");
    }
  }
  return 0;
}

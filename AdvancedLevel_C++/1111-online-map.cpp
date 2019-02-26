/* Copyright [2019] <mituh> */
/* 1111-online-map.cpp */
/* Dijkstra + DFS  */

#include <cstdio>
#include <vector>
using namespace std;

#define MaxSize 550
#define INFINITY 65533
struct Node {
  int l, t;
} G[MaxSize][MaxSize];

int dist[MaxSize], time_a[MaxSize], node[MaxSize] = {INFINITY},
  path_d[MaxSize], path_t[MaxSize], collected[MaxSize],
  n, m, D, S;

void InitG() {
  int v, w;
  for (v = 0; v < n; v++) {
    for (w = 0; w < n; w++) {
      G[v][w].l = G[v][w].t = INFINITY;
    }   /* 初始化边权重为无限大 */
  }
}

void ReadData() {
  int i, v1, v2, one_way, l, t;
  InitG();
  for (i = 0; i < m; i++) {
    scanf("%d %d %d %d %d", &v1, &v2, &one_way, &l, &t);
    if (one_way == 0) {
      G[v2][v1].l = l; G[v2][v1].t = t;
    }
    G[v1][v2].l = l; G[v1][v2].t = t;
  }
  scanf("%d %d", &S, &D);
}

int FindMinDist(int dist[], int collected[]) {
  /* 在未收录dist中找最小者 */
  int v, min, ans;
  min = INFINITY; ans = -1;
  for (v = 0; v < n; v++) {
    if (collected[v] != 1 && dist[v] < min) {
      min = dist[v];
      ans = v;
    }
  }
  return ans;
}

void Dijkstra_d() {
  int i, V, W;
  for (i = 0; i < n; i++) { collected[i] = 0; }
  for (V = 0; V < n; V++) {
    dist[V] = G[S][V].l;
    time_a[V] = G[S][V].t;
    if (dist[V] < INFINITY) {
      path_d[V] = S;
    } else {
      path_d[V] = -1;
    }
  }

  dist[S] = 0;
  collected[S] = 1;
  while (1) {
    V = FindMinDist(dist, collected);
    if (V == -1) {
      break;
    }
    collected[V] = 1;
    for (W = 0; W < n; W++) {
      if (!collected[W] && G[V][W].l < INFINITY) {
        if (dist[V] + G[V][W].l < dist[W]) {
          dist[W] = dist[V] + G[V][W].l;
          time_a[W] = time_a[V] + G[V][W].t;
          path_d[W] = V;
        } else if ((dist[V] + G[V][W].l == dist[W]) &&
                   (time_a[V] + G[V][W].t < time_a[W])) {
          /* dist不变, 时间和路径修改 */
          time_a[W] = time_a[V] + G[V][W].t;
          path_d[W] = V;
        }
      }
    }
  }
}

void Dijkstra_t() {
  int i, V, W;
  for (i = 0; i < n; i++) { collected[i] = 0; }
  for (V = 0; V < n; V++) {
    time_a[V] = G[S][V].t;
    if (time_a[V] < INFINITY) {
      path_t[V] = S; node[V] = 1;
    } else {
      path_t[V] = -1;
    }
  }

  time_a[S] = 0;
  collected[S] = 1;
  while (1) {
    V = FindMinDist(time_a, collected);
    if (V == -1) {
      break;
    }
    collected[V] = 1;
    for (W = 0; W < n; W++) {
      if (!collected[W] && G[V][W].t < INFINITY) {
        if (time_a[V] + G[V][W].t < time_a[W]) {
          time_a[W] = time_a[V] + G[V][W].t;
          node[W] = node[V] + 1;
          path_t[W] = V;
        } else if ((time_a[V] + G[V][W].t == time_a[W]) &&
                   (node[V] + 1 < node[W])) {
          /* time不变, 结点数和路径修改 */
          node[W] = node[V] + 1;
          path_t[W] = V;
        }
      }
    }
  }
}

vector<int> GetPathVector(int path[]) {
  int p;
  vector<int> v;
  for (p = D; p != S; p = path[p]) {
    v.push_back(p);
  }
  v.push_back(S);
  return v;
}

int IsSame(vector<int> shortest_path, vector<int> fastest_path) {
  int i, ok;
  ok = 1;
  if (shortest_path.size() != fastest_path.size()) {
    ok = 0;
  } else {
    for (i = 0; i < shortest_path.size(); i++) {
      if (shortest_path[i] != fastest_path[i]) {
        ok = 0; break;
      }
    }
  }
  return ok;
}

void PrintPath(vector<int> path) {
  int i, flag;
  flag = 0;
  for (i = path.size()-1; i >= 0; i--) {
    if (flag) {
      printf(" -> ");
    } else {
      flag = 1;
    }
    printf("%d", path[i]);
  }
  printf("\n");
}

int main() {
  vector<int> shortest_path, fastest_path;
  int Shortest, Fastest;
  scanf("%d %d", &n, &m);
  ReadData();   /* 读入G, S, D*/
  Dijkstra_d();   /* 最短 */
  Shortest = dist[D];
  Dijkstra_t();   /* 最快 */
  Fastest = time_a[D];
  shortest_path = GetPathVector(path_d);
  fastest_path = GetPathVector(path_t);
  if (IsSame(shortest_path, fastest_path)) {
    printf("Distance = %d; Time = %d: ", Shortest, Fastest);
    PrintPath(shortest_path);
  } else {
    printf("Distance = %d: ", Shortest); PrintPath(shortest_path);
    printf("Time = %d: ", Fastest); PrintPath(fastest_path);
  }
  return 0;
}

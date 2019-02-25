/* Copyright [2019] <mituh> */
/* 1111-online-map.cpp */
/* Dijkstr + DFS  */

#include <cstdio>
#include <vector>
using namespace std;

#define MaxSize 550
#define INFINITY 65533
struct Node {
  int l, t;
} G[MaxSize][MaxSize];

int S, D, n, m, Shortest, Fastest, min_shortest_fast, min_fastest_depth;
int dist[MaxSize], path_d[MaxSize], time[MaxSize], path_t[MaxSize];
vector<int> shortest_path, fastest_path;

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
    if (!one_way) {
      G[w][v].l = l; G[w][v].t = t;
    }
    G[v][w].l = l; G[v][w].t = t;
  }
  scanf("%d %d", &S, &D);
}

int FindMinDist(int dist[], int collected[]) {
  /* 在未收录dist中找最小者 */
  int v, min, ans;
  min = INFINITY; ans = -1;
  for (v = 0; v < n; v++) {
    if (!collected[v] && dist[v] < min) {
      min = dist[v];
      ans = v;
    }
  }
  return ans;
}

void Dijkstra(int dist[], int path[], int S, int type) {
  int v, w, Gvw;
  int collected[MaxSize];

  /* 
  for (v = 0; v < n; v++) {
    dist[v] = INFINITY;
  }
  */
  /* 初始化路径, 已经初始化图边为INFINITY, dist为G*/
  for (v = 0; v < n; v++) {
    if (type == 0) {
      dist[v] = G[S][v].l;
    } else {
      dist[v] = G[S][v].t;
    }
    if (dist[v] < INFINITY) {
      path[v] = S;
    } else {
      path[v] = -1;
    }
  }

  /* 将起点收入集合 */
  dist[S] = 0;
  collected[S] = 1;
  while (1) {
    /* V是未收录dist中最小者 */
    v = FindMinDist(dist, collected);
    if (v == -1) {   /* 不存在这样的V */
      break;
    }
    collected[v] = 1;
    for (w = 0; w < n; w++) {
      if (type == 0) {
        Gvw = G[v][w].l;
      } else {
        Gvw = G[v][w].t;
      }
      if (!collected[w] && Gvw < INFINITY) {
        if (dist[v] + Gvw < dist[w]) {
          dist[w] = dist[v] + Gvw;
          path[w] = v;
        }
      }
    }
  }
}

void GetMinPath() {
  
}
void dfs_d(int V);
void dfs_t(int V);

int main() {
  scanf("%d %d", &n, &m);
  ReadData();   /* 读入G, S, D*/
  Dijkstra(dist, path_d, S, 0);   /* 最短 */
  Dijkstra(time, path_t, S, 1);   /* 最快 */
  GetMinPath();  /* 根据dist, time, path_d, path_t得到并列的最短路信息 */
  if (IsSame()) {
    printf("Distance = %d; Time = %d: ", dist[D], time[D]);
    PrintPath(shortest_path);
  } else {
    dfs_d(S);      /* 最短找最快 */
    dfs_f(S, 1);   /* 最快找结点最少, 1是根结点算作1个结点 */
    printf("Distance = %d ", Shortest); PrintPath(shortest_path);
    printf("Time = %d ", Fastest); PrintPath(fastest_path);
  }
  return 0;
}


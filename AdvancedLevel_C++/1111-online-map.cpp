/* Copyright [2019] <mituh> */
/* 1111-online-map.cpp */
/* Dijkstr + DFS  */
/*
Sample Input 1:
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5

Sample Output 1:
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5

Sample Input 2:
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5

Sample Output 2:
Distance = 3; Time = 4: 3 -> 2 -> 5
*/

#include <cstdio>
#include <vector>
using namespace std;

#define MaxSize 550
#define INFINITY 65533
struct Node {
  int l, t;
} G[MaxSize][MaxSize];

int S, D, n, m, Shortest, Fastest, min_shortest_fast, min_fastest_depth;
int dist[MaxSize], path_d[MaxSize], time_a[MaxSize], path_t[MaxSize];
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
void Dijkstra_d(int S) {
  int v, w;
  int collected[MaxSize];

  /* 
  for (v = 0; v < n; v++) {
    dist[v] = INFINITY;
  }
  */
  /* 初始化路径, 已经初始化图边为INFINITY, dist为G */
  for (v = 0; v < n; v++) {
    dist[v] = G[S][v].l;
    if (dist[v] < INFINITY) {
      path_d[v] = S;
    } else {
      path_d[v] = -1;
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
      if (!collected[w] && G[v][w].l < INFINITY) {
        if (dist[v] + G[v][w].l < dist[w]) {
          dist[w] = dist[v] + G[v][w].l;
          path_d[w] = v;
        }
      }
    }
  }
}

void Dijkstra_t(int S) {
  int v, w;
  int collected[MaxSize] = {0};    /* ??? */

  /* 
  for (v = 0; v < n; v++) {
    dist[v] = INFINITY;
  }
  */
  /* 初始化路径, 已经初始化图边为INFINITY, dist为G */
  for (v = 0; v < n; v++) {
    time_a[v] = G[S][v].t;
    if (time_a[v] < INFINITY) {
      path_t[v] = S;
    } else {
      path_t[v] = -1;
    }
  }

  /* 将起点收入集合 */
  time_a[S] = 0;
  collected[S] = 1;
  while (1) {
    /* V是未收录dist中最小者 */
    v = FindMinDist(time_a, collected);
    if (v == -1) {   /* 不存在这样的V */
      break;
    }
    collected[v] = 1;
    for (w = 0; w < n; w++) {
      if (!collected[w] && G[v][w].t < INFINITY) {
        if (time_a[v] + G[v][w].t < time_a[w]) {
          time_a[w] = time_a[v] + G[v][w].t;
          path_t[w] = v;
        }
      }
    }
  }
}

/*
void Dijkstra(int dist[], int path[], int S, int type) {
  int v, w, Gvw;
  int collected[MaxSize];

  for (v = 0; v < n; v++) {
    if (type == 0) {
      dist[v] = G[S][v].l;
    } else {
      dist[v] = G[S][v].t;
    }
    printf("dist[%d] = %d\n", v, dist[v]);
    if (dist[v] < INFINITY) {
      path[v] = S;
    } else {
      path[v] = -1;
    }
  }

  dist[S] = 0;
  collected[S] = 1;
  while (1) {
    v = FindMinDist(dist, collected);
    printf("FindMinDist v = %d\n", v);
    if (v == -1) {
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
          printf("path[w] = %d\n", path[w]);
        }
      }
    }
  }
}
*/

void GetMinPath() {
  int p, i, v, w;
  min_shortest_fast = min_fastest_depth = 0;
  Shortest = dist[D];
  Fastest = time_a[D];
  shortest_path.clear(); fastest_path.clear();
  for (p = D; p != S; p = path_d[p]) {
    shortest_path.push_back(p);
  }
  shortest_path.push_back(S);
  for (i = shortest_path.size()-1; i > 0; i--) {
    v = shortest_path[i];
    w = shortest_path[i-1];
    min_shortest_fast += G[v][w].t;
  }
  for (p = D; p != S; p = path_t[p]) {
    fastest_path.push_back(p);
  }
  fastest_path.push_back(S);
  min_fastest_depth = fastest_path.size();
  /* printf("min_shortest_fast = %d, min_fastest_depth = %d\n",
    min_shortest_fast, min_fastest_depth); */
}

int IsSame() {
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

int dfs_time[MaxSize];
int visited_d[MaxSize] = {0};
void dfs_d(int V) {
  int W, p;
  visited_d[V] = 1;  /* dfs visited[]!!!! 到底写在哪? */
  for (W = 0; W < n; W++) {
    if (!visited_d[W] && G[V][W].l < INFINITY) {  /* 路通 */
      dist[W] = dist[V] + G[V][W].l;
      dfs_time[W] = dfs_time[V] + G[V][W].t;
      path_d[W] = V;
      /* printf("dfs_time[%d] = %d\n", W, dfs_time[W]); */
      if (W == D && dist[W] == Shortest && dfs_time[W] < min_shortest_fast) {
        /* 时间最短, 时间更少, 需要更新 */
        shortest_path.clear();
        for (p = W; p != S; p = path_d[p]) {
          shortest_path.push_back(p);
        }
        shortest_path.push_back(S);
        min_shortest_fast = dfs_time[W];   /* time_a[W] ?? */
      }
      
      dfs_d(W);
    }
  }
  visited_d[V] = 0;   /* 递归完该结点, 可再被访问 */
}

int visited_t[MaxSize] = {0};
void dfs_t(int V, int depth) {
  int W, p;
  visited_t[V] = 1;
  for (W = 0; W < n; W++) {
    if (!visited_t[W] && G[V][W].t < INFINITY) {   /* 存在边 */
      /* visited_t[W] = 1; */
      depth += 1;
      time_a[W] = time_a[V] + G[V][W].t;
      path_t[W] = V;
      /* printf("time_a[%d] = %d, Fastest = %d\n", W, time_a[W], Fastest); */
      if (W == D && time_a[W] == Fastest && depth < min_fastest_depth) {   /* 一定要递归到目标结点 */
        /* 时间最快, 结点更少, 需要更新 */
        fastest_path.clear();
        for (p = W; p != S; p = path_t[p]) {
          fastest_path.push_back(p);
        }
        fastest_path.push_back(S);
        min_fastest_depth = depth;
      }
      dfs_t(W, depth);
    }
  }
  visited_t[V] = 0;
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
  scanf("%d %d", &n, &m);
  ReadData();   /* 读入G, S, D*/
  Dijkstra_d(S);   /* 最短 */
  Dijkstra_t(S);   /* 最快 */
  GetMinPath();  /* 根据dist, time_a, path_d, path_t得到并列的最短路信息 */
  /* 先得到最快的最短路 和 最少结点的最快路后, 再判断两条路径是否相同 */
  dfs_time[S] = 0;
  dfs_d(S);      /* 最短找最快 */
  dfs_t(S, 1);   /* 最快找结点最少, 1是根结点算作1个结点 */
  if (IsSame()) {
    printf("Distance = %d; Time = %d: ", Shortest, Fastest);
    PrintPath(shortest_path);
  } else {
    printf("Distance = %d: ", Shortest); PrintPath(shortest_path);
    printf("Time = %d: ", Fastest); PrintPath(fastest_path);
  }
  return 0;
}

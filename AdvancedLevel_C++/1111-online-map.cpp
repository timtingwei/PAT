/* Copyright [2019] <mituh> */
/* 1111-online-map.cpp */
/* Dijkstr + DFS  */

#include <cstdio>
#include <vector>
using namespace std;

#define MaxSize 550
struct Node {
  int l, t;
} G[MaxSize][MaxSize];

int S, D, n, m, Shortest, Fastest, min_shortest_fast, min_fastest_depth;
int dist[MaxSize], path_d[MaxSize], time[MaxSize], path_t[MaxSize];
vector<int> shortest_path, fastest_path;

void ReadData();
void Dijkstra(int dist[], int path[], int S, int type);
void GetMinPath();
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


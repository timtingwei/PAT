/* Copyright [2019] <mituh> */
/* 1087-all-roads-lead-to-rome-30.cpp */
/* Dijkstra + DFS  */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
#define MaxSize 210
#define INFINITY 65533
int n, k, S, D, Least, Num;
int collected[MaxSize],
  cost[MaxSize], happiness[MaxSize], node[MaxSize], path[MaxSize];
unordered_map<int, string> mp_itos;
unordered_map<string, int> mp_stoi;
int V_h[MaxSize];   /* 城市的快乐值 */
int G[MaxSize][MaxSize];

void InitG() {
  int V, W;
  for (V = 0; V < n; V++) {
    for (W = 0; W < n; W++) { G[V][W] = INFINITY; }
  }
}

void ReadData() {
  int i, h, c, V, W; string name, adj_name;
  InitG();
  cin >> name;
  mp_stoi[0] = name; mp_itos[name] = 0; V_h[0] = 0;
  for (i = 1; i < n; i++) {
    cin >> name >> h;
    mp_stoi[name] = i; mp_itos[i] = name; V_h[i] = h;
  }
  for (i = 0; i < n; i++) {
    cin >> name >> adj_name >> c;
    V = mp_stoi[name]; W = mp_stoi[adj_name];
    G[V][W] = c; G[W][V] = c;
  }
  S = 0;
  D = mp_stoi["ROM"];
}

int FindMinCost(int cost[], int collected[]) {
  int V, min = INFINITY, ans = -1;
  for (V = 0; V < n; V++) {
    if (!collected[V] && cost[V] < min) {
      min = cost[V];
      ans = V;
    }
  }
  return ans;  /* 未找到返回-1 */
}

void Dijkstra() {
  int i, V, W;
  for (i = 0; i < n; i++) {
    collected[i] = 0;
    happiness[i] = -1;      /* 比大 */
    node[MaxSize] = INFINITY;
  }
  for (V = 0; V < n; V++) {
    cost[V] = G[S][V];   /* 同时初始化cost */
    if (cost[V] < INFINITY) {
      path[V] = S;
    } else {
      path[V] = -1;
    }
  }
  cost[S] = happiness[S] = node[S] = 0;
  collected[S] = 1;

  while (1) {
    V = FindMinCost(cost, collected);
    for (W = 0; W < n; W++) {
      if (G[V][W] < INFINITY && !collected[W]) {
        if (cost[V] + G[V][W] < cost[W]) {
          cost[W] = cost[V] + G[V][W];
          happiness[W] = happiness[V] + V_h[W];
          node[W] = node[V] + 1;
          path[W] = V;
        } else if (cost[V] + G[V][W] == cost[W]) {
          if (happniess[V] + V_h[W] > happiness[W]) {
            happiness[W] = happiness[V] + V_h[W];
            node[W] = node[V] + 1;
            path[W] = V;
          } else if (happniess[V] + V_h[W] == happiness[W]) {
            node[W] = node[V] + 1;
            path[W] = V;
          }
        }
      }
    }
  }
  Least = cost[D];   /* 记录最小花费 */
}

void dfs(int Least) {
  /* 找到从S到D所有路径, 修改路径数量 */
  int cnt;

  /* Num += 1 */
  /* cout << "Num = " << Num << endl; */
}

int main() {
  cin >> n >> k;   /* 剩余的name在ReadData里读 */
  ReadData();
  Dijkstra();
  dfs(Least);
  cout << Least << " " << Num << " " << happiness[D]
       << " " << (int)happiness[D]/node[D] << endl;
  PrintPath(path);
  return 0;
}


/* Copyright [2019] <mituh> */
/* 1087-all-roads-lead-to-rome-30.cpp */
/* Dijkstra + DFS  */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
#define MaxSize 210
#define INFINITY_new 65533   /* g++中已经定义不同INFINITY */
int n, k, S, D, Least, Num = 0;
int collected[MaxSize], cost[MaxSize],
  happiness[MaxSize], node[MaxSize], path[MaxSize];
unordered_map<int, string> mp_itos;
unordered_map<string, int> mp_stoi;
int V_h[MaxSize];   /* 城市的快乐值 */
int G[MaxSize][MaxSize];

void InitG() {
  int V, W;
  for (V = 0; V < n; V++) {
    for (W = 0; W < n; W++) { G[V][W] = INFINITY_new; }
  }
}

void ReadData() {
  int i, h, c, V, W; string name, adj_name;
  InitG();
  cin >> name;
  mp_stoi[name] = 0; mp_itos[0] = name; V_h[0] = 0;
  for (i = 1; i < n; i++) {
    cin >> name >> h;
    mp_stoi[name] = i; mp_itos[i] = name; V_h[i] = h;
  }
  for (i = 0; i < k; i++) {
    cin >> name >> adj_name >> c;
    V = mp_stoi[name]; W = mp_stoi[adj_name];
    cout << V << " " << W << endl;
    G[V][W] = c; G[W][V] = c;
  }
  S = 0;
  D = mp_stoi["ROM"];
}

int FindMinCost(int cost[], int collected[]) {
  int V, min = INFINITY_new, ans = -1;
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
    happiness[i] = 0;      /* 比大 */
    node[i] = INFINITY_new;
  }
  for (V = 0; V < n; V++) {
    cost[V] = G[S][V];   /* 同时初始化cost */
    if (cost[V] < INFINITY_new) {
      path[V] = S;
      happiness[V] = V_h[V];    /* 紧邻结点快乐值也要初始化!?? */
      node[V] = 1;              /* 同上 */
    } else {
      path[V] = -1;
    }
  }
  cost[S] = happiness[S] = node[S] = 0;
  collected[S] = 1;

  while (1) {
    V = FindMinCost(cost, collected);
    if (V == -1) break;    /* 不要忘记不存在V的情况!! */
    collected[V] = 1;      /* 也不要忘记把V收进来 */
    printf("V = %d\n", V);
    for (W = 0; W < n; W++) {
      if (G[V][W] < INFINITY_new && !collected[W]) {
        if (cost[V] + G[V][W] < cost[W]) {
          cost[W] = cost[V] + G[V][W];
          happiness[W] = happiness[V] + V_h[W];
          node[W] = node[V] + 1;
          path[W] = V;
        } else if (cost[V] + G[V][W] == cost[W]) {
          if (happiness[V] + V_h[W] > happiness[W]) {
            happiness[W] = happiness[V] + V_h[W];
            node[W] = node[V] + 1;
            path[W] = V;
          } else if (happiness[V] + V_h[W] == happiness[W]) {
            printf("node same\n");
            if (node[V] + 1 < node[W]) {
              node[W] = node[V] + 1;
              path[W] = V;
            }
          }
        }
      }
    }
  }
  Least = cost[D];   /* 记录最小花费 */
}

stack<int> stk;
int visited[MaxSize] = {0};
void dfs(int V, int cost) {
  /* 找到从S到D所有路径, 修改路径数量 */
  /* 调用dfs(S, 0) */
  int W;
  visited[V] = 1;
  stk.push(V);
  if (V == D && cost == Least) {
    Num++; return;
  }
  for (W = 0; W < n; W++) {
    if (G[V][W] < INFINITY_new && !visited[W]) {
      dfs(W, cost);
      while (stk.top() != W) { visited[stk.top()] = 0; stk.pop(); }
    }
  }
  /* cout << "Num = " << Num << endl; */
}

void PrintPath(int path[]) {
  int p, i, index, flag = 0;
  vector<int> v;
  for (p = D; p != S; p = path[p]) {
    v.push_back(p);
  }
  v.push_back(p);
  for (i = v.size()-1; i >= 0; i--) {
    index = v[i];
    if (flag) {
      cout << "->";
    } else {
      flag = 1;
    }
    cout << mp_itos[index];
  }
  cout << endl;
}

int main() {
  cin >> n >> k;   /* 剩余的name在ReadData里读 */
  ReadData();
  printf("finish ReadData()\n");
  Dijkstra();
  printf("finish Dijkstra()\n");
  dfs(S, 0);
  cout << Num << " " << Least << " " << happiness[D]
       << " " << (int)happiness[D]/node[D] << endl;
  PrintPath(path);
  return 0;
}


/* Copyright [2019] <mituh> */
/* 1131-subway-map-30.cpp */
/* 图的dfs */
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
#define MaxSize 10010    /* 图的结点编号在00000~99999*/
#define INFI 65533
vector<int> G[MaxSize];  /* 邻接点存在vec中 */
map<int, int> mp_line;  /* mp_line[node_i] = line_i */
void ReadGraph(int n) {
  int i, j, m, V, W; vector<int> line;
  for (i = 1; i <= n; i++) {
    scanf("%d", &m);
    line.clear();
    for (j = 0; j < m; j++) {
      scanf("%d", &V);
      mp_line[V] = i;
      line.push_back(V);
    }

    for (j = 0; j < m-1; j++) {
      V = line[j]; W = line[j+1];
      G[V].push_back(W);
      G[W].push_back(V);
    }
  }
}
vector<int> ans_line_v, ans_node_v;
int min_node, min_transfer;
void Reset() {
  ans_line_v.clear(); ans_node_v.clear();
  min_node = INFI; min_transfer = INFI;
}

vector<int> Copy(vector<int> v) {
  vector<int> new_v; int i;
  for (i = 0; i < v.size(); i++) {
    new_v.push_back(v[i]);
  }
  return new_v;
}

void Refresh(vector<int> line, vector<int> node) {
  int i;
  ans_line_v.clear(); ans_node_v.clear();
  for (i = 0; i < line.size(); i++) {
    ans_line_v.push_back(line[i]);
  }
  for (i = 0; i < node.size(); i++) {
    ans_node_v.push_back(node[i]);
  }
}

int visited[MaxSize] = {0};
void dfs(int V, int D, int node, int transfer, int line,
  vector<int> now_line_v, vector<int> now_node_v) {
  int W, i; vector<int> tmp_line_v, tmp_node_v;
  visited[V] = 1;
  if (V == D) {
    tmp_node_v = Copy(now_node_v);
    tmp_node_v.push_back(D);
    if (node < min_node) {
      min_node = node;
      Refresh(now_line_v, tmp_node_v);
    } else if (node == min_node && transfer < min_transfer) {
      min_transfer = transfer;
      Refresh(now_line_v, tmp_node_v);
    }
    return;
  }
  if (node > min_node || (node == min_node && transfer > min_transfer)) {
    return;
  }
  
  for (i = 0; i < G[V].size(); i++) {
    W = G[V][i];
    if (!visited[W]) {
      if (mp_line[W] == line) {
        dfs(W, D, node+1, transfer, line, now_line_v, now_node_v);
      } else {
        tmp_line_v = Copy(now_line_v); tmp_node_v = Copy(now_node_v);
        tmp_line_v.push_back(mp_line[W]);
        tmp_node_v.push_back(W);
        dfs(W, D, node+1, transfer+1, mp_line[W], tmp_line_v, tmp_node_v);
      }
      visited[W] = 0;
    }
  }
}

void PrintPath(vector<int> line, vector<int> node, int min_node) {
  int i;
  printf("%d\n", min_node);
  for (i = 0; i < line.size(); i++) {
    printf("Take Line#%d from %04d to %04d.\n", line[i], node[i], node[i+1]);
  }
}

void FindPath(int S, int D) {
  vector<int> start_line_v, start_node_v;
  start_line_v.push_back(mp_line[S]);
  start_node_v.push_back(S);
  
  dfs(S, D, 0, 0, mp_line[S], start_line_v, start_node_v);
  
  PrintPath(ans_line_v, ans_node_v, min_node);
}

int main() {
  int n, k, S, D;
  scanf("%d", &n);
  ReadGraph(n);
  scanf("%d", &k);
  while (k--) {
    scanf("%d %d", &S, &D);
    Reset();
    FindPath(S, D);
  }
  return 0;
}


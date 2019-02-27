/* Copyright [2019] <mituh> */
/* 1131-subway-map-30.cpp */
/* 图的dfs */
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
#define MaxSize 10010    /* 图的结点编号在00000~99999*/
#define INFI 65533
/* map<int, int> mp_line; */  /* mp_line[node_i] = line_i */
/* 同一个结点可能属于多条路线, 不能简单用Hash表来查 */
/* 重构: 把路线编号记录到边结点上去  */
typedef struct GNode *Node;
struct GNode {
  int next;
  int line;   /* 假设从V到W的路径只有一条, 不然答案就不唯一 */
};
vector<Node> G[MaxSize];

void ReadGraph(int n) {
  int i, j, m, V, W; vector<int> line; Node node_w, node_v;
  for (i = 1; i <= n; i++) {
    scanf("%d", &m);
    line.clear();
    for (j = 0; j < m; j++) {
      scanf("%d", &V);
      line.push_back(V);
    }

    for (j = 0; j < m-1; j++) {
      /* 从头到尾方向 */
      V = line[j]; W = line[j+1];
      node_w = (Node)malloc(sizeof(GNode));
      node_w->next = W;
      node_w->line = i;
      G[V].push_back(node_w);

      node_v = (Node)malloc(sizeof(GNode));
      node_v->next = V;
      node_v->line = i;
      G[W].push_back(node_v);
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

/*
void PrintV(vector<int> v) {
  int i;
  for (i = 0; i < v.size(); i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}
*/

/*
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
      if (!IsTransfer(V, line, W)) {
        dfs(W, D, node+1, transfer, line, now_line_v, now_node_v);
      } else {
        tmp_line_v = Copy(now_line_v); tmp_node_v = Copy(now_node_v);
        tmp_line_v.push_back(mp_line[W]);
        tmp_node_v.push_back(V);
        dfs(W, D, node+1, transfer+1, mp_line[W], tmp_line_v, tmp_node_v);
      }
      visited[W] = 0;
    }
  }
}
*/

int visited[MaxSize] = {0};
void dfs(int V, int D, int node, int transfer, int line,
         vector<int> now_line_v, vector<int> now_node_v) {
  int W, i, next_line; vector<int> tmp_line_v, tmp_node_v;
  /* 调用 dfs(S, D, 0, 0, 0, start_line_v, start_node_v);
     linec传入0, 会在首个结点处改变 */
  visited[V] = 1;
  /* printf("V = %d, D = %d, node = %d, transfer = %d, line = %d\n",
         V, D, node, transfer, line); 
  PrintV(now_line_v);
  PrintV(now_node_v); */
  if (V == D) {
    tmp_node_v = Copy(now_node_v);
    tmp_node_v.push_back(D);     /* 压入终点结点 */
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

  for (i = 0; i < G[V].size(); i++) {   /* 遍历V的每个邻接点 */
    W = G[V][i]->next;
    if (!visited[W]) {
      next_line = G[V][i]->line;
      if (next_line == line) {
        /* if (mp_line[W] == line) { 不能简单的通过查表来判断路径还是否相同!! */
        dfs(W, D, node+1, transfer, line, now_line_v, now_node_v);
      } else {
        tmp_line_v = Copy(now_line_v); tmp_node_v = Copy(now_node_v);
        tmp_line_v.push_back(next_line);   /* 把下条路线压入 */
        tmp_node_v.push_back(V);            /* 把当前结点压入!! */
        dfs(W, D, node+1, transfer+1, next_line, tmp_line_v, tmp_node_v);
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
  /*
  printf("node.size() = %lu \n", node.size());
  for (i = 0; i < node.size(); i++) {
    printf("%d ", node[i]);
  }
  printf("\n");
  */
}

void FindPath(int S, int D) {
  vector<int> start_line_v, start_node_v;
  /* start_line_v.push_back(mp_line[S]); */
  /* start_node_v.push_back(S); */
  /* dfs(S, D, 0, 0, mp_line[S], start_line_v, start_node_v); */
  dfs(S, D, 0, 0, 0, start_line_v, start_node_v);
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


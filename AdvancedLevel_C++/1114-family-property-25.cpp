/* Copyright [2019] <mituh> */
/* 1114-family-property-25.cpp */
/* 并查集 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MaxSize 10005
#define INFI 99999
struct TNode {
  int ID, root;   /* 根结点n = -root */
  double e, a;
};
TNode T[MaxSize];
vector<TNode> v;
void Init() {
  int i;
  for (i = 0; i < MaxSize; i++) {
    T[i].ID = -1; T[i].root = INFI;
    T[i].e = T[i].a = 0;
  }
}

int GetRoot(int c) {
  while (T[c].root >= 0) c = T[c].root;
  return c;
}

int Find(int c) {
  /* 找到c的根结点下标 */
  int Root;
  if (T[c].root == INFI) {
    T[c].root = -1;
    Root = c;
  } else {
    Root = GetRoot(c);
  }
  return Root;
}

int Union(int R1, int R2) {
  if (R1 == R2) return R1;     /* 在归并代码中, 别要忘记两个根相同的情况!! */
  int Root;
  if (R1 < R2) {   /* R1的结点编号更小 */
    T[R1].root += T[R2].root; T[R2].root = R1;  /* 规模, 挂 */
    T[R1].e += T[R2].e; T[R1].a += T[R2].a;
    Root = R1;
  } else {  /* R1挂在R2上 */
    T[R2].root += T[R1].root; T[R1].root = R2;
    T[R2].e += T[R1].e; T[R2].a += T[R1].a;
    Root = R2;
  }
  return Root;
}

bool cmp(TNode n1, TNode n2) {
  if (n1.a != n2.a) {
    return n1.a > n2.a;
  }
  return n1.ID < n2.ID;
}

int main() {
  int n, i, j;
  scanf("%d", &n);
  Init();
  for (i = 0; i < n; i++) {
    int ID, p1, p2, k, c, Root;
    double e, a;
    scanf("%d %d %d", &ID, &p1, &p2);
    Root = Find(ID);
    if (p1 != -1) Root = Union(Root, Find(p1));
    if (p2 != -1) Root = Union(Root, Find(p2));
    scanf("%d", &k);
    for (j = 0; j < k; j++) {
      scanf("%d", &c);
      Root = Union(Root, Find(c));
    }
    scanf("%lf %lf", &e, &a);
    T[Root].ID = Root;
    T[Root].e += e; T[Root].a += a;
  }

  printf("finish read\n");

  for (i = 0; i < MaxSize; i++) {
    if (T[i].root < 0) { v.push_back(T[i]); }
  }
  sort(v.begin(), v.end(), cmp);
  printf("%lu", v.size());
  for (i = 0; i < v.size(); i++) {
    printf("%04d %d %.3lf %.3lf\n",
            v[i].ID, -v[i].root, v[i].e/(-v[i].root), v[i].a/(-v[i].root));
  }
  return 0;
}


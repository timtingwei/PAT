/* Copyright [2019] <mituh> */
/* 1147-heaps.cpp */
/* 堆, 树的遍历 */
/* case2, 4, WA:  堆, 完全二叉树用结点下标 <= n来判断是不是空结点 */

#include <cstdio>
#include <vector>
using namespace std;
#define MaxSize 10050   /* 防止最后一排溢出 */
vector<int> v;
int T[MaxSize];
int n;  /* 完全二叉树用n与i比较 判断空结点 */

int IsMaxHeap() {
  int i, left, right, ans = 1;
  for (i = 1; i <= n; i++) {
    left = i*2; right = i*2+1;
    if ((left <= n && T[left] > T[i]) || (right <= n && T[right] > T[i])) {
      ans = 0; break;
    }
  }
  return ans;
}

int IsMinHeap() {
  int i, left, right, ans = 1;
  for (i = 1; i <= n; i++) {
    left = i*2; right = i*2+1;
    if ((left <= n && T[left] < T[i]) || (right <= n && T[right] < T[i])) {
      ans = 0; break;
    }
  }
  return ans;
}

void PostOrderTraversal(int Root) {
  if (Root > n) return;
  PostOrderTraversal(Root*2);
  PostOrderTraversal(Root*2+1);
  v.push_back(T[Root]);
}

int main() {
  int m, i, j;
  scanf("%d%d", &m, &n);
  for (i = 0; i < m; i++) {
    for (j = 1; j <= n; j++) { scanf("%d", &T[j]);}
    if (IsMinHeap() && !IsMaxHeap()) {
      printf("Min Heap\n");
    } else if (IsMaxHeap() && !IsMinHeap()) {
      printf("Max Heap\n");
    } else {
      printf("Not Heap\n");
    }
    v.clear();
    PostOrderTraversal(1);
    int flag = 0;
    for (j = 0; j < v.size(); j++) {
      if (flag) {
        printf(" ");
      } else {
        flag = 1;
      }
      printf("%d", v[j]);
    }
    printf("\n");
  }
  return 0;
}


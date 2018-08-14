// Copyright [2018] <mituh>
// struct_sort.cpp
// 结构体排序
#include <cstdio>
#include <algorithm>
using namespace std;
// 实现ssd数组, 按照x从大到小排序
// 实现ssd数组, 在x相等的情况下, 按照y从大到小排序
// struct {  error
struct Node {
  int x, y;
} ssd[5];

bool cmp(Node a, Node b) {
  if (a.x == b.x) return a.y > b.y;
  return a.x > b.x;
}

int main() {
  // {1, 2}, {2, -1}, {2, 0}, {4, -2}, {5, 3};
  ssd[0].x = 1; ssd[0].y = 2;
  ssd[1].x = 2; ssd[1].y = -1;
  ssd[2].x = 2; ssd[2].y = 0;
  ssd[3].x = 4; ssd[3].y = -2;
  ssd[4].x = 5; ssd[4].y = 3;

  sort(ssd, ssd+5, cmp);

  for (int i = 0; i < 5; i++) {
    printf("%d %d\n", ssd[i].x, ssd[i].y);
  }

  return 0;
}

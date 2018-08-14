// Copyright [2018] <mituh>
// double_sort.cpp

// sort(首个元素地址, 尾元素的下个哨兵地址, 比较函数)
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
  double a[] = {1.4, -2.1, 9};
  sort(a, a+3);
  for (int i = 0; i < 3; i++) {
    printf("%.1f ", a[i]);
  }
  printf("\n");

  return 0;
}

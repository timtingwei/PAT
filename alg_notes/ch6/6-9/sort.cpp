// Copyright [2018] <mituh>
// sort.cpp

// sort(首个元素地址, 尾元素的下个哨兵地址, 比较函数)
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int a[6] = {9, 4, 2, 5, 6, -1};
  sort(a, a + 4);                  // 对a[0] ~ a[3] 进行从小到大排序
  for (int i = 0; i < 6; i++) { cout << a[i] << " "; }
  cout << endl;

  sort(a, a+6);                    // 对a[0] ~ a[5] 从小到大排序
  for (int i = 0; i < 6; i++) { cout << a[i] << " "; }
  cout << endl;

  return 0;
}

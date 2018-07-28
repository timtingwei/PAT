// Copyright [2018] <mituh>
// 1016. 部分A+B（15).cpp    // 42 38 -> 1h
/*
  思路:
  1, 字符数组和字符比较, 因为 b<=10e10, 放弃
  2, 长整数取余得到各个位数, 求和

输入样例 1：
3862767 6 13530293 3
输出样例 1：
399

输入样例 2：
3862767 1 13530293 8
输出样例 2：
0
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long a, b, pa = 0, pb = 0;
  int da, db;
  scanf("%lld %d %lld %d", &a, &da, &b, &db);
  while (a) {
    if (a % 10 == da) pa = pa * 10 + da;
    a /= 10;
  }
  while (b) {
    if (b % 10 == db) pb = pb * 10 + db;
    b /= 10;
  }

  printf("%lld\n", pa + pb);

  return 0;
}

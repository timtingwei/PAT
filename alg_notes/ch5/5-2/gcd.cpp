// Copyright [2018] <mituh>
// gcd.cpp
// greatest common divisor, 最大公约数
#include <cstdio>

/*
// 循环的写法
int gcd(int a, int b) {
  while (b != 0) {
    int tmp = a; a = b; b = tmp % b;
  }
  return a;
}
*/

// 递归的写法
int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int main() {
  printf("%d\n", gcd(2, 3));
  return 0;
}

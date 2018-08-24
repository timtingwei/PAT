// Copyright [2018] <mituh>
// lcm.cpp
#include <cstdio>
int gcd(int a, int b) {
  // return !b ? a : a % b;
  return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

int lcm_better(int a, int b) {
  return a / gcd(a, b) * b;
}

int main() {
  printf("%d\n", gcd(2, 3));
  printf("%d\n", lcm(2, 3));
  printf("%d\n", lcm(22223, 23333223));          // -1156828087
  printf("%d\n", lcm_better(2222223, 23223));    // 22359059
  return 0;
}

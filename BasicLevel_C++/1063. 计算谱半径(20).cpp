// Copyright [2018] <mituh>
// 1063. 计算谱半径(20).cpp    09:55->10:08 = 13min
#include <cmath>
#include <cstdio>

int main() {
  int N, a, b; scanf("%d", &N);
  double max = 0, tmp;

  while (N--) {
    // int a, b;
    scanf("%d %d", &a, &b);
    tmp = sqrt(a*a+b*b);
    if (tmp > max) max = tmp;
  }
  printf("%.2lf", floor(max * 100 + 0.5)/100);

  return 0;
}

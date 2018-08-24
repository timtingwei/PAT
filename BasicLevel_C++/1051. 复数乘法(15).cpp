// Copyright [2018] <mituh>
// 1051. 复数乘法(15).cpp   07:27 -> 08:14
/*
1051 复数乘法(15)

复数可以写成 (A+Bi) 的常规形式，其中 A 是实部，B 是虚部，i 是虚数单位，满足 i2=−1；也可以写成极坐标下的指数形式 (R×e(Pi))，其中 R 是复数模，P 是辐角，i 是虚数单位，其等价于三角形式 (R(cos(P)+isin(P))。

现给定两个复数的 R 和 P，要求输出两数乘积的常规形式。

输入格式：
输入在一行中依次给出两个复数的R1, R2, P1, P2数字间以空格分隔。

输出格式：

在一行中按照 A+Bi 的格式输出两数乘积的常规形式，实部和虚部均保留 2 位小数。注意：如果 B 是负数，则应该写成 A-|B|i 的形式。

输入样例：
2.3 3.5 5.2 0.4

输出样例：
-8.68-8.23i
*/
#include <cstdio>
#include <cmath>

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  double r1, p1, r2, p2;
  scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
  double A = r1 * r2 * cos(p1) * cos(p2) - r1 * r2 * sin(p1) * sin(p2);
  double B = r1 * r2 * cos(p1) * sin(p2) + r1 * r2 * sin(p1) * cos(p2);
  // A = -0.0005;
  // B = -0.0005;
  if (A + 0.005 >= 0 && A < 0) {
    printf("0.00");
  } else {
    printf("%.2lf", A);
  }

  if (B >= 0) {
    printf("+%.2lfi\n", B);
  } else if (B + 0.005 >= 0 && B < 0) {
    printf("+0.00i\n");    // 我并不知道有这种边界条件, 为什么0的时候还有i日
  } else {
    printf("%.2lfi\n", B);
  }

  return 0;
}

/*
错误:
-0.00-0.00i

// 不太懂虚部分为什么不能是-0.00
// else if (B - 0.000005 < 0 && B + 0.000005 > 0) { 原来以为是判等的精度问题
*/

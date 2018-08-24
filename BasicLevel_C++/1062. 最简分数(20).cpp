// Copyright [2018] <mituh>
// 1062. 最简分数(20).cpp       12:13->1:10
/*
1062 最简分数（20 point(s)）

一个分数一般写成两个整数相除的形式：N/M，其中 M 不为0。最简分数是指分子和分母没有公约数的分数表示形式。

现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。

输入格式：
输入在一行中按 N/M 的格式给出两个正分数，随后是一个正整数分母 K，其间以空格分隔。题目保证给出的所有整数都不超过 1000。

输出格式：
在一行中按 N/M 的格式列出两个给定分数之间分母为 K 的所有最简分数，按从小到大的顺序，其间以 1 个空格分隔。行首尾不得有多余空格。题目保证至少有 1 个输出。

输入样例：
7/18 13/20 12

输出样例：
5/12 7/12
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a%b);
}

int main() {
  int N1, M1, N2, M2, K;
  scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);

  // case1
  if (N1*M2 > N2*M1) {
    swap(N1, N2);
    swap(M1, M2);
  }

  int num = 1;
  while (num * M1 <= N1 * K) num++;
  int flag = 0;
  while (num * M1 > N1 * K && M2 * num < N2 * K) {
    if (gcd(num, K) == 1) {
      printf("%s%d/%d", (flag ? " " : ""), num, K);
      flag = 1;
    }
    num++;
  }
  return 0;
}

/*
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
int limit[1000];
int mp[2500];

int main() {
  char s1[15], s2[15]; int K;
  scanf("%s %s %d", s1, s2, &K);
  getchar();     // print
  int limit_n = 0;

  for (int i = 2; i <= K; i++) {   // bug01, i != 0
    if (K % i == 0) {
      limit[limit_n++] = i;
    }
  }
  // 仍旧可以优化

  int N1, M1, N2, M2;
  sscanf(s1, "%d/%d", &N1, &M1);
  sscanf(s2, "%d/%d", &N2, &M2);
  memset(mp, 0, sizeof(mp));

  double da =  N1/((double)M1/K), db =  N2/( (double) M2/K);
  if (da > db) {double tmp = da; da = db; db = tmp;}
  int a = ceil(da), b = floor(db);

  if (K == 1) {                         // case1
    for (int i = a; i < b; i++) {
      if (-0.00005 < i - da && i - da < 0.000005) continue;
      if (i != a) printf(" ");
      printf("%d/%d", i, K);
    }
    return 0;
  }

  int scale = 1, over = 0;
  while (!over) {
    over = 1;
    for (int i = 0; i < limit_n; i++) {
      int tmp = limit[i] * scale;
      if (tmp <= b) {
        over = 0;
        if (a <= tmp) {
          mp[tmp] = 1;
        }
      }
    }
    scale++;
    if (over) break;
  }

  int first = 0;
  for (int i = a; i < db; i++) {
    if (-0.00005 < i - da && i - da < 0.000005) continue;   // case2
    if (!mp[i]) {
      if (first) printf(" ");
      printf("%d/%d", i, K);
      first = 1;
    }
  }
  printf("\n");
  return 0;
}
*/

// Copyright [2018] <mituh>
// 1012. 数字分类 (20).cpp    // 55  28 48 = 30+20min
/*

给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；

A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；

A3 = 被5除后余2的数字的个数；

A4 = 被5除后余3的数字的平均数，精确到小数点后1位；

A5 = 被5除后余4的数字中最大数字。

#### 输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

#### 输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

#### 输入样例1：

13 1 2 3 4 5 6 7 8 9 10 20 16 18
#### 输出样例1：

30 11 2 9.7 9
#### 输入样例2：

8 1 2 4 5 6 7 9 16
#### 输出样例2：

N 11 2 N 9
*/

// 第二次做, 02:30 -> 2:43 -> 2:55 = 25;
#include <cstring>
#include <cstdio>

int exist[6];
int ans[6];
double ans_3;

int main() {
  int N; scanf("%d", &N);
  memset(exist, 0, sizeof(exist));
  memset(ans, 0, sizeof(ans));
  int cnt = 0, flag = 1;
  for (int i = 0; i < N; i++) {
    int tmp; scanf("%d", &tmp);
    if (tmp % 5 == 0 && tmp % 2 == 0) {
      ans[0] += tmp; exist[0] = 1;
    }
    if (tmp % 5 == 1) {
      ans[1] += tmp * flag; exist[1] = 1;
      flag *= -1;
    }
    if (tmp % 5 == 2) {
      ans[2]++; exist[2] = 1;
    }
    if (tmp % 5 == 3) {
      ans_3 += tmp; cnt++; exist[3] = 1;
    }
    if (tmp % 5 == 4 && tmp > ans[4]) {
      ans[4] = tmp; exist[4] = 1;
    }
  }

  for (int i = 0; i < 5; i++) {
    if (i) printf(" ");
    if (exist[i]) {
      if (i != 3) printf("%d", ans[i]);
      else printf("%.1f", ans_3 / cnt);
    } else {
      printf("N");
    }
  }
  printf("\n");

  return 0;
}


/*
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：  注意 2 6 6的情况A2 error

13 1 2 3 4 5 6 7 8 9 10 20 16 18
30 11 2 9.7 9

8 1 2 4 5 6 7 9 16
N 11 2 N 9

2 6 6
N 0 N N N
*/

/*
#include <cstdio>
#include <cstring>
#include <iostream>
int const MAXN = 10000000;
int a[MAXN];
int main() {
  int n;
  if (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) { scanf("%d", &a[i]);}
    int a1 = 0, a2 = 0, a3 = 0, a5 = -1;
    double a4 = 0.0;
    int flag = 1, a2_n = 0, a4_n = 0;  // A2 6 6的情况也为0
    for (int i = 0; i < n; i++) {
      if ((a[i] % 5 == 0) && (a[i] % 2 == 0)) a1 += a[i];
      if (a[i] % 5 == 1) {
        a2 += (flag * a[i]);
        flag *= -1;
        a2_n++;
      }
      if (a[i] % 5 == 2) a3++;
      if (a[i] % 5 == 3) { a4 += a[i]; a4_n++;}
      if (a[i] % 5 == 4 && a[i] > a5) a5 = a[i];
    }

    if (a1 != 0) {
      printf("%d", a1);
    } else {
      printf("N");
    }

    if (a2_n != 0) {
      printf(" %d", a2);
    } else {
      printf(" N");
    }

    if (a3 != 0) {
      printf(" %d", a3);
    } else {
      printf(" N");
    }

    if (a4_n != 0) {
      a4 /= a4_n;
      printf(" %.1f", a4);
    } else {
      printf(" N");
    }

    if (a5 != -1) {
      printf(" %d", a5);
    } else {
      printf(" N");
    }

    printf("\n");
  }
  return 0;
}
*/

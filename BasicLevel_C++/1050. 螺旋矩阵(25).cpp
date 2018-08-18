// Copyright [2018] <mituh>
// 1050. 螺旋矩阵(25).cpp   03:15 -> 3:52->5:33, 这题好烦, 算法还需要改进
/*
1050 螺旋矩阵（25 point(s)）

本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。

输入格式：

输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 10
​4
​​ ，相邻数字以空格分隔。

输出格式：

输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。

输入样例：

12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：

98 95 93
42 37 81
53 20 76
58 60 76
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 10000;          // case bug, 开太大超时
// const int MAXM = MAXN * 2;
int ans[MAXN][300];              // case6, 7 开太大超时, 开太小段错误
int a[MAXN];

bool cmp(int a, int b) {
  return a >= b;
}

int main() {
  int N; scanf("%d", &N);
  for (int i = 0; i < N; i++) { scanf("%d", &a[i]); }

  int m = 1, n, min_m = m, d;
  while (m <= N) {                              // debug, m能取到N
    if (N % m == 0 && m >= N/m) {
      n = N / m;     int min_n = N / min_m;
      d = m - n;     int min_d = min_m - min_n;
      if (d < min_d || min_d < 0) min_m = m;    // debug, case2, 1 1
    }
    m++;
  }
  m = min_m; n = N / m;

  sort(a, a+N, cmp);   // bug2, 忘记cmp

  int k, flag = 0;
  int right_n = n, down_m = m, left_n = -1, up_m = -1;   // bug4
  int i = 0, j = 0;
  ans[0][0] = a[0]; k = 1;
  while (k < N) {
    if (flag == 0) {
      if (++j == right_n) {
        j--; up_m++; flag = 1; continue;
      }
    } else if (flag == 1) {
      if (++i == down_m) {
        i--; right_n--; flag = 2; continue;
      }
    } else if (flag == 2) {
      if (--j == left_n) {
        j++; down_m--; flag = 3; continue;
      }
    } else if (flag == 3) {
      if (--i == up_m) {
        i++; left_n++; flag = 0; continue;
      }
    }
    ans[i][j] = a[k++];
    // printf("ans[%d][%d] = %d, k = %d\n", i, j, ans[i][j], k-1);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (j) printf(" ");
      printf("%d", ans[i][j]);   // bug, 并不需要两位
    }
    printf("\n");
  }

  return 0;
}


/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 10000;       // case bug, 开太大超时
// const int MAXM = MAXN * 2;
int ans[MAXN][300];           // case6, 7 开太大超时, 开太小段错误
int a[MAXN];

bool cmp(int a, int b) {
  return a >= b;
}

int main() {
  int N; scanf("%d", &N);
  // memset(a, 0, sizeof(a));
  // memset(ans, 0, sizeof(ans));
  for (int i = 0; i < N; i++) { scanf("%d", &a[i]); }


  int m = 1, n, min_m = m, min_n, min_d, d;
  while (m <= N) {                              // debug, m能取到N
    if (N % m == 0 && m >= N/m) {
// printf("%d\n", m);
      n = N / m;     min_n = N / min_m;
      d = m - n;     min_d = min_m - min_n;
      if (d < min_d || min_d < 0) min_m = m;    // debug, case2, 1 1
    }
    m++;
  }
  m = min_m; n = N / m;
  //
  // while (m < N) {
  //   if (m != 1 && m >= n && N % m == 0) {
  //     n = N / m;
  //     int min_n = N / min_m;
  //     if (m - n < min_m - min_n) min_m = m;
  //     // if (m > max) max = m;
  //     // n = N / m; break;
  //   }
  //   m++;
  // }
  // m = min_m; n = N / m;
  // for (m = floor(sqrt(N) + 0.5); m < N; m++) {   // bug01
  //   if (N % m == 0) { n = N / m; break;}
  // }
  //
  // m = 4, n = 3;
// printf("m = %d, n = %d\n", m, n);

  sort(a, a+N, cmp);   // bug2

// for (int i = 0; i < N; i++) printf("%d ", a[i]);
// printf("\n");

  int k, flag = 0;
  int right_n = n, down_m = m, left_n = -1, up_m = -1;   // bug4
  int i = 0, j = 0;
  ans[0][0] = a[0]; k = 1;
  while (k < N) {
    if (flag == 0) {
      if (++j == right_n) {
        j--; up_m++; flag = 1; continue;
      }
    } else if (flag == 1) {
      if (++i == down_m) {
        i--; right_n--; flag = 2; continue;
      }
    } else if (flag == 2) {
      if (--j == left_n) {
        j++; down_m--; flag = 3; continue;
      }
    } else if (flag == 3) {
      if (--i == up_m) {
        i++; left_n++; flag = 0; continue;
      }
    }
    ans[i][j] = a[k++];
    // printf("ans[%d][%d] = %d, k = %d\n", i, j, ans[i][j], k-1);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (j) printf(" ");
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }

  return 0;
}
*/

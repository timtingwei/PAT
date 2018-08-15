// Copyright [2018] <mituh>
// 1030. 完美数列(25).cpp   05:15 5:41 -> 6:16 (case 4超时)
/*
1030 完美数列(25)（25 point(s)）

给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。

现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：

输入第一行给出两个正整数N和p，其中N（<= 10^5^）是输入的正整数的个数，p（<= 10^9^）是给定的参数。第二行给出N个正整数，每个数不超过10^9^。

输出格式：

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：

10 8
2 3 20 4 5 1 6 7 8 9
输出样例：

8
*/

/*
// case4 TE
#include <cstdio>
#include <algorithm>
const int MAXN = 100050;
long long a[MAXN];
int main() {
  int N, p;
  scanf("%d %d", &N, &p);
  for (int i = 0; i < N; i++) scanf("%lld", &a[i]);
  std::sort(a, a+N);
  
  int i = 0, j, max = 0;
  while (i < N) {
    j = N-1;
    while (a[i]*p < a[j] && i <= j) j--;
    int cnt = j-i+1;
    if (cnt > max) max = cnt;
    i++;
  }
  printf("%d\n", max);

  return 0;
}
*/

/*
// case4同样超时
#include <cstdio>
#include <algorithm>
const int MAXN = 100050;
long long a[MAXN];
int main() {
  int N, p;
  scanf("%d %d", &N, &p);
  for (int i = 0; i < N; i++) scanf("%lld", &a[i]);
  std::sort(a, a+N);

  int i = 0, j, max = 0;
  while (i < N && (max < N-i)) {
    j = N-1;
    while (a[i]*p < a[j] && i <= j) j--;
    int cnt = j-i+1;
    if (cnt > max) max = cnt;
    i++;
  }
  printf("%d\n", max);

  return 0;
}
*/

#include <cstdio>
#include <algorithm>
const int MAXN = 100050;
long long a[MAXN];
int main() {
  int N, p;
  scanf("%d %d", &N, &p);
  for (int i = 0; i < N; i++) scanf("%lld", &a[i]);
  std::sort(a, a+N);

  int max = 0;
  for (int i = 0; i < N; i++) {
    int j = i+max;
    for ( ; j < N && a[j] <= a[i]*p; j++) { }
    int tmp = j-i;
    if (tmp > max) max = tmp;
  }
  printf("%d\n", max);
  return 0;
}

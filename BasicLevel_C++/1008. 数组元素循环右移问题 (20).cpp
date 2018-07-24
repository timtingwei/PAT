// Copyright [2018] <mituh>
// 1008. 数组元素循环右移问题 (20).cpp
/*
  思路: 用一个双倍于整数个数的数组存放, 从中间开始放第一个值, 将M所代表部分移至前面
  注意m比n的时候
  思路2: 只用p标记当前打印位置, p=n时->p=0, 而不是构造一个数组
 */
#include <stdio.h>
#include <string.h>

/*
#define MAXN 300
int a[MAXN];

int main() {
  int n, m, mid = 150;  // n<=100
  scanf("%d %d", &n, &m);
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) { scanf("%d", &a[mid+i]);}
  int k = m;
  while (k) {
    a[mid-k] = a[mid+n-k];
    k--;
  }
  printf("%d", a[mid-m]);
  for (int i = mid-m+1; i < mid+n-m; i++) printf(" %d", a[i]);
  printf("\n");

  return 0;
}
*/
/*
6 6
1 2 3 4 5 6
*/
#define MAXN 100 + 10
int a[MAXN];

int getp(int n, int m) {
  if (n >= m) return n - m;
// printf("d=%d\n", n - (m - n));
  return n - (m - n);
}

int main() {
  int n, m;  // n<=100
  scanf("%d %d", &n, &m);
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) { scanf("%d", &a[i]);}
  int p = getp(n, m), k = 0;
  for (;;) {
// printf("p=%d, k=%d\n", p, k);
    if (p == n) p = 0;
    (k++ == 0) ? printf("%d", a[p]) : printf(" %d", a[p]);
    if (k == n) break;
    p++;
  }
  printf("\n");

  return 0;
}
/*
6 8
1 2 3 4 5 6
5 6 1 2 3 4
*/

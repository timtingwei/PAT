// Copyright [2018] <mituh>
// 1035 插入与归并(25).cpp 3:14 3:38 3:57  吃完早饭再看, 完成
/*
1035 插入与归并（25 point(s)）

根据维基百科的定义：

插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。

归并排序进行如下迭代操作：首先将原始序列看成 N 个只包含 1 个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下 1 个有序的序列。

现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

输入格式：

输入在第一行给出正整数 N (≤100)；随后一行给出原始序列的 N 个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

输出格式：

首先在第 1 行中输出Insertion Sort表示插入排序、或Merge Sort表示归并排序；然后在第 2 行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行首尾不得有多余空格。

输入样例 1：

10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例 1：

Insertion Sort
1 2 3 5 7 8 9 4 6 0
输入样例 2：

10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例 2：

Merge Sort
1 2 3 8 4 5 7 9 0 6

// case 4, case 6 WA
// 判断完是MergeSort后, 需要重新模拟归并, 并且多进行一次迭代, 这里我不是很懂

*/

/*
// 判断出merge后, 直接根据i计算出step进行下一次归并, case 4, 6 WA
Input Case:
10
1 2 3 4 7 5 9 4 0 6
1 2 3 4 5 7 4 9 0 6

// i=4, step = i * 2 = 8, 这样计算就出了问题

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int S[MAXN];
int T[MAXN];

void show(int A[], int n) {
  printf("%d", A[0]);
  for (int i = 1; i < n; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &S[i]);
  for (int i = 0; i < N; i++) scanf("%d", &T[i]);

  int i, j;
  i = 1;
  while (i < N && T[i-1] < T[i]) i++;

  j = i;
  while (j < N) {
    if (S[j] != T[j]) {
      printf("Merge Sort\n");
      int step = 2 * i;
      for (int p = 0; p < N; p += step) {
        sort(T + p, T + min(p+step, N));
      }
      show(T, N);
      return 0;
    }
    j++;
  }
  if (j == N) {
    printf("Insertion Sort\n");
    for (j = i; j > 0 && T[j] < T[j-1]; j--) {
      int tmp = T[j]; T[j] = T[j-1]; T[j-1] = tmp;
    }
    show(T, N);
  }

  return 0;
}
*/

/*
// 没限制step, 以及刚开始比较顺序时, 忽略相等的两个元素有序, 导致case 4 Segmentation Fault
#include <cstdio>
#include <algorithm>
using namespace std;

void show(int S[], int N) {
  for (int k = 0; k < N; k++) {
    if (k) printf(" ");
    printf("%d", S[k]);
  }
  printf("\n");
}

const int MAXN = 105;
int S[MAXN];
int T[MAXN];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)  scanf("%d", &S[i]);
  for (int i = 0; i < N; i++)  scanf("%d", &T[i]);

  int i, j;
  for (i = 1; i < N && T[i-1] < T[i]; i++) { }
  for (j = i; j < N && S[j] == T[j]; j++) { }
  printf("j = %d\n", j);
  if (j == N) {
    printf("Insertion Sort\n");
    sort(S, S+i+1);
  } else {
    printf("Merge Sort\n");
    int flag = 1, step = 2;
    while (flag) {
      flag = 0;
      show(S, N);
      for (int k = 0; k < N; k++) if (S[k] != T[k]) { flag = 1; break;}

      for (int i = 0; i < N; i += step) {
        printf("i = %d, step = %d\n", i, step);
        sort(S+i, S + min(i+step, N));
      }
      step *= 2;
    }
  }

  for (int k = 0; k < N; k++) {
    if (k) printf(" ");
    printf("%d", S[k]);
  }
  printf("\n");

  return 0;
}
*/

// case4: Segmentation Fault
/*
10
3 1 2 8 7 5 9 4 0 6
3 1 2 8 7 5 9 4 0 6
*/


/*
// 虽然修改了step的对循环的控制权, 但错误并不是在这里
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int S[MAXN];
int T[MAXN];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)  scanf("%d", &S[i]);
  for (int i = 0; i < N; i++)  scanf("%d", &T[i]);

  int i, j;
  for (i = 1; i < N && T[i-1] < T[i]; i++) { }
  for (j = i; j < N && S[j] == T[j]; j++) { }
  if (j == N) {
    printf("Insertion Sort\n");
    sort(S, S+i+1);
  } else {
    printf("Merge Sort\n");
    int flag = 1;
    for (int step = 2; step/2 <= N && flag; step *= 2) {
      flag = 0;
      for (int k = 0; k < N; k++) if (S[k] != T[k]) { flag = 1; break;}

      for (i = 0; i < N; i += step) {
// printf("i = %d, step = %d, i+step = %d\n", i, step, i+step);
        sort(S+i, S + min(i+step, N));
      }
    }
  }

  for (int k = 0; k < N; k++) {
    if (k) printf(" ");
    printf("%d", S[k]);
  }
  printf("\n");

  return 0;
}

// case4: wrong answer...S的中间两个元素相等, 也算有序, 仅仅只是漏掉了一个等号..
*/


#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int S[MAXN];
int T[MAXN];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)  scanf("%d", &S[i]);
  for (int i = 0; i < N; i++)  scanf("%d", &T[i]);

  int i, j;
  for (i = 1; i < N && T[i-1] <= T[i]; i++) { }    // case4
  for (j = i; j < N && S[j] == T[j]; j++) { }
  if (j == N) {
    printf("Insertion Sort\n");
    sort(S, S+i+1);
  } else {
    printf("Merge Sort\n");
    int flag = 1;
    for (int step = 2; step/2 <= N && flag; step *= 2) {  // case6
      flag = 0;
      for (int k = 0; k < N; k++) if (S[k] != T[k]) { flag = 1; break;}

      for (i = 0; i < N; i += step) {
        sort(S+i, S + min(i+step, N));
      }
    }
  }

  for (int k = 0; k < N; k++) {
    if (k) printf(" ");
    printf("%d", S[k]);
  }
  printf("\n");

  return 0;
}

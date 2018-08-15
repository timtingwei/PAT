// Copyright [2018] <mituh>
// 1035 插入与归并(25).cpp 3:14 3:38 3:57  未完成, 仍旧不太理解归并排序
/*
aa
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



/*
10
3 1 2 8 7 5 9 4 6 0
1 2 3 4 5 6 7 8 9 0
Insertion Sort
0 1 2 3 4 5 6 7 8 9
*/

/*
10
3 1 2 8 7 5 9 4 0 6
3 1 2 8 7 5 9 4 0 6
Insertion Sort
1 3 2 8 7 5 9 4 0 6
*/


/*
10
3 1 2 8 7 5 9 4 0 6
1 2 3 8 4 5 7 9 0 6
Merge Sort
1 2 3 4 5 7 8 9 0 6
*/

/* 既可以是insertion, 又是mergeSort
10
3 1 2 8 7 5 9 4 0 6
1 2 3 4 5 7 8 9 0 6
*/

// Float points Exception??

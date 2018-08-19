// Copyright [2018] <mituh>
// 1060. 爱丁顿数(25).cpp          04:56->5:19(case3)->5:26
/*
1060 爱丁顿数（25 point(s)）

英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数” E ，即满足有 E 天骑车超过 E 英里的最大整数 E。据说爱丁顿自己的 E 等于87。

现给定某人 N 天的骑车距离，请你算出对应的爱丁顿数 E（≤N）。

输入格式：

输入第一行给出一个正整数 N (≤10^5)，即连续骑车的天数；第二行给出 N 个非负整数，代表每天的骑车距离。

输出格式：
在一行中给出 N 天的爱丁顿数。

输入样例：
10
6 7 6 9 3 10 8 2 7 8

输出样例：
6
*/

/*
#include <iostream>
using namespace std;

int a[100050];

int main() {
  int N; cin >> N;
  for (int i = 0; i < N; i++) {cin >> a[i];}
  int E = 0;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if (a[j] > i+1) cnt++;
    }
    if ((cnt >= i+1) && (i+1) > E) E = i+1;
  }
  cout << E << endl;
  return 0;
}

// case3, 超时
*/

/*
// 从大往小找, 用c++也能ac
#include <cstdio>
using namespace std;

int a[100050];

int main() {
  int N; scanf("%d", &N);
  for (int i = 0; i < N; i++) {scanf("%d", &a[i]);}
  int E = 0;
  for (int i = N-1; i >= 0; i--) {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if (a[j] > i+1) cnt++;
    }
    if (cnt >= i+1) { E = i+1; break;}
  }
  printf("%d\n", E);
  return 0;
}
*/

#include <stdio.h>

int a[100050];

int main() {
  int N; scanf("%d", &N);
  for (int i = 0; i < N; i++) {scanf("%d", &a[i]);}
  int E = 0;
  for (int i = N-1; i >= 0; i--) {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if (a[j] > i+1) cnt++;
    }
    if (cnt >= i+1) { E = i+1; break;}
  }
  printf("%d\n", E);
  return 0;
}

// Copyright [2018] <mituh>
// 1087.有多少不同的值(20).cpp
/*
1087 有多少不同的值(20)

当自然数 n 依次取 1、2、3、……、N 时，算式 ⌊n/2⌋+⌊n/3⌋+⌊n/5⌋ 有多少个不同的值？（注：⌊x⌋ 为取整函数，表示不超过 x 的最大自然数，即 x 的整数部分。）

输入格式：

输入给出一个正整数 N（2≤N≤10^4）。

输出格式：
在一行中输出题面中算式取到的不同值的个数。

输入样例：
2017

输出样例：
1480
*/
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int N; scanf("%d", &N);
  int value[100050] = {0};
  int max = 0, cnt = 0;
  for (int i = 1; i <= N; i++) {
    int t = floor(i/2) + floor(i/3) + floor(i/5);
    value[t] = 1;
    max = t > max ? t : max;
  }
  
  for (int i = max; i >= 0; i--) {
    if (value[i]) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}

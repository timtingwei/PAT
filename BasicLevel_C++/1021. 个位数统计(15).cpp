// Copyright [2018] <mituh>
// 1021. 个位数统计(15).cpp     3:20 -> 3:29
/*
1021 个位数统计（15 point(s)）

给定一个 k 位整数 N=d, 请编写程序统计每种不同的个位数字出现的次数。
例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

输入格式：
每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。

输出格式：
对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。要求按 D 的升序输出。

输入样例：
100311

输出样例：
0:2
1:3
3:1
*/

#include <cstdio>
#include <cstring>

int cnt[11];
char s[1050];
int main() {
  scanf("%s", s);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < strlen(s); i++) {
    cnt[s[i]-'0']++;
  }
  int flag = 0;
  for (int i = 0; i < 10; i++) {
    if (cnt[i]) {
      if (!flag) {
        flag = 1;
      } else {
        printf("\n");
      }
      printf("%d:%d", i, cnt[i]);
    }
  }
  return 0;
}

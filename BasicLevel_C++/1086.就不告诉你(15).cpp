// Copyright [2018] <mituh>
// 1086.就不告诉你(15).cpp
/*
1086 就不告诉你(15)

做作业的时候，邻座的小盆友问你：“五乘以七等于多少？”你应该不失礼貌地围笑着告诉他：“五十三。”本题就要求你，对任何一对给定的正整数，倒着输出它们的乘积。

输入格式：
输入在第一行给出两个不超过 1000 的正整数 A 和 B，其间以空格分隔。

输出格式：
在一行中倒着输出 A 和 B 的乘积。

输入样例：
5 7

输出样例：
53
*/

// 字符串操作
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int a, b; cin >> a >> b;
  string temp = to_string(a*b);
  reverse(temp.begin(), temp.end());
  cout << stoi(temp) << endl;
  return 0;
}

/*
// 手动模拟反转计算
#include <cstdio>
int main() {
  int a, b; scanf("%d %d", &a, &b);
  int n = a*b;
  int arr[10] = {0}, len = 0, t = 1;
  while (n) {
    arr[len++] = n % 10; t *= 10;
    n /= 10;
  }
  t /= 10;  // debug

  int ans = 0;
  for (int i = 0; i < len; i++) {
    ans += arr[i] * t;
    t /= 10;
  }
  printf("%d\n", ans);
  return 0;
}
*/

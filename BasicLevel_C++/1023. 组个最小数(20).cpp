// Copyright [2018] <mituh>
// 1023. 组个最小数(20).cpp   02:38 -> 2:48 -> 2:53
/*
1023 组个最小数（20 point(s)）

给定数字 0-9 各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意 0 不能做首位）。例如：给定两个 0，两个 1，三个 5，一个 8，我们得到的最小的数就是 10015558。

现给定数字，请编写程序输出能够组成的最小的数。

输入格式：
输入在一行中给出 10 个非负整数，顺序表示我们拥有数字 0、数字 1、……数字 9 的个数。整数间用一个空格分隔。10 个数字的总个数不超过 50，且至少拥有 1 个非 0 的数字。

输出格式：
在一行中输出能够组成的最小的数。

输入样例：
2 2 0 0 0 3 0 0 1 0

输出样例：
10015558
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; int first;
  for (int i = 0; i < 10; i++) {
    int cnt; cin >> cnt;
    if (!i) first = cnt;
    for (int j = 0; j < cnt; j++) s += (i + '0');
  }

  if (s[0] == '0') {
    char tmp = s[0]; s[0] = s[first]; s[first] = tmp;
  }
  cout << s << endl;
  return 0;
}

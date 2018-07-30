// Copyright [2018] <mituh>
// 1019. 数字黑洞 (20).cpp    // 35 -> 纠结很长时间
/*
1019 数字黑洞 (20)（20 point(s)）

给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089\ 9810 - 0189 = 9621\ 9621 - 1269 = 8352\ 8532 - 2358 = 6174\ 7641 - 1467 = 6174\ ... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。

输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

输入样例1：
6767
输出样例1：

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：

2222
输出样例2：

2222 - 2222 = 0000


思路:  模拟, 需要递减sort, 再递增排序
字符串转整数, 整数转字符串
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp_str1(const char a, const char b) { return a >= b;}

bool cmp_str2(const char a, const char b) { return a <= b;}


int convert_int(string s) {
  // 从(末尾*10+前一位)*10
  int i = 1, ans = 0;
  for (string::iterator p = s.end()-1; p >= s.begin(); p--) {
    ans += (*p - '0') * i;
    i *= 10;
  }
  // cout << ans << "\n";
  return ans;
}

string convert_str(int h) {
  // 转成4位字符串,
  string ans_s(4, '0');
  int i = 3;
  while (h) {
    ans_s[i--] = h % 10 + '0';
    h /= 10;
  }
  return ans_s;
}

int main() {
  string s1;
  cin >> s1;
  s1 = convert_str(convert_int(s1));   // debug: 0~999需要处理
  string s2 = s1;
  sort(s1.begin(), s1.end(), cmp_str1);
  sort(s2.begin(), s2.end(), cmp_str2);
  if (s1 == s2) {
    cout << s1 << " - " << s1 << " = 0000" << "\n"; return 0;
  }
  while (s1 != "6174") {
    s2 = s1;
    sort(s1.begin(), s1.end(), cmp_str1);
    sort(s2.begin(), s2.end(), cmp_str2);
    int d = convert_int(s1) - convert_int(s2);
    string tmp = convert_str(d);               // debug:按照四位格式输出
    cout << s1 << " - " << s2 << " = " << tmp << "\n";
    s1 = tmp;
  }

  return 0;
}


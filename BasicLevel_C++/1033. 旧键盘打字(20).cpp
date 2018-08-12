// Copyright [2018] <mituh>
// 1033. 旧键盘打字(20).cpp 9:51 -> 10:18
/*
1033 旧键盘打字(20)（20 point(s)）

旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：

输入在2行中分别给出坏掉的那些键、以及应该输入的文字。
其中对应英文字母的坏键以大写给出；
每段文字是不超过10^5^个字符的串。
可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。
题目保证第2行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：

在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：

7+IE.
7_This_is_a_test.
输出样例：

_hs_s_a_tst

思路:
只有打出和打不出两种情况。
打不出分成: 数字字符对应, 英文字符 对应 坏键大写, '+'导致所有大写字符都打不出.
每次输入一个字符去和坏键对比, 可以的字符加入vector

case2 error:

没有一个字符能被打出的情况
abcd
abcd

+
+

+
aabb22BSa2

abc_
a_vs_cs_b

abc
a\bsd_\, 排除不可用字母

debug case2: 第一行 为空的情况!!

abcd

*/

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

// debug case 2: 可用字符就这么几个
int is_ok(char ch) {
  if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')
      || ('0' <= ch && ch <= '9')
      || (ch == ',' || ch == '.' || ch == '-' || ch == '+' || ch == '_'))
    return 1;
  return 0;
}

int main() {
  string bad, input;
  getline(cin, bad); cin >> input;  // debug: 改用空行
  // cin >> bad >> input;           // case2: 通不过的原因, 第一行可能是空行
  for (int i = 0; i < input.length(); i++) {
    int ok = 1;
    if (!is_ok(input[i])) continue;
    for (int j = 0; j < bad.length(); j++) {
      if (input[i] == bad[j]) {ok = 0; break;}   // 直接对应相等
      if (isalpha(input[i]) && (toupper(input[i]) == bad[j]))  {
        ok = 0; break;       // 字符i是字母, 转成大写对应相等
      }
      if (bad[j] == '+' && isupper(input[i])) {
        ok = 0; break;       // 坏键是+, 对应i是大写
      }
    }
    if (ok) cout << input[i];
  }
  cout << "\n";
  return 0;
}
*/

#include <iostream>
#include <string>
using namespace std;
int main() {
  string bad, should;
  getline(cin, bad);
  getline(cin, should);
  for (int i = 0; i < should.length(); i++) {
    if (bad.find(toupper(should[i])) != string::npos) continue;
    if (isupper(should[i]) && bad.find('+') != string::npos) continue;
    cout << should[i];
  }
  return 0;
}

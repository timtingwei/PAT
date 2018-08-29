// Copyright [2018] <mituh>
// 1079 延迟的回文数(20).cpp    04:27 -> 5:00(最后一个case点没过)
/*
1079 延迟的回文数（20 point(s)）

非回文数也可以通过一系列操作变出回文数。首先将该数字逆转，再将逆转数与该数相加，如果和还不是一个回文数，就重复这个逆转再相加的操作，直到一个回文数出现。如果一个非回文数可以变出回文数，就称这个数为延迟的回文数。（定义翻译自 https://en.wikipedia.org/wiki/Palindromic_number ）

给定任意一个正整数，本题要求你找到其变出的那个回文数。

输入格式：
输入在一行中给出一个不超过1000位的正整数。

输出格式：
对给定的整数，一行一行输出其变出回文数的过程。每行格式如下

A + B = C
其中 A 是原始的数字，B 是 A 的逆转数，C 是它们的和。A 从输入的整数开始。重复操作直到 C 在 10 步以内变成回文数，这时在一行中输出 C is a palindromic number.；或者如果 10 步都没能得到回文数，最后就在一行中输出 Not found in 10 iterations.。

输入样例 1：
97152

输出样例 1：
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.

输入样例 2：
196

输出样例 2：
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.

*/

/*
#include <iostream>
#include <string>
using namespace std;

string reverse(string s) {
  string tmp;
  int n = s.length();
  for (int i = n-1; i >= 0; i--) {
    tmp += s[i];
  }
  return tmp;
}

int is_p(string s) {
  int n = s.length();
  for (int i = 0; i <= n / 2; i++) {
    if (s[i] != s[n-1-i]) return 0;
  }
  return 1;
}

long long re_stoi(string s) {
  long long ans = 0;
  int n = s.length(); long long b = 1;
  for (int i = n-1; i >= 0; i--) {
    ans += (s[i] - '0') * b;
    b *= 10;
  }
  return ans;
}

int main() {
  string A; cin >> A;
  int cnt = 0;
  if (is_p(A)) {
    cout << A << " is a palindromic number.\n";
  } else {
    for (;;) {
      string s1, s2;
      s1 = A;
      s2 = reverse(A);
      A = to_string(re_stoi(s1) + re_stoi(s2));         // bug case7
      cout << s1 << " + " << s2 << " = " << A << endl;  // bug1
      if (is_p(A)) {
        cout << A << " is a palindromic number.\n";
        break;
      }
      // 10755470 + 07455701 = 18211171
      // cout << s1 << " + " << s2 << " = " << A << endl;  // bug1
      if (++cnt == 10) {
        cout << "Not found in 10 iterations.\n"; break;
      }
    }
  }

  return 0;
}
*/

/*
6666666666666666666667
6666666666666666666667 + 7666666666666666666666 = 213188061011727701
213188061011727701 + 107727110160881312 = 320915171172609013
320915171172609013 + 310906271171519023 = 631821442344128036
631821442344128036 + 630821443244128136 = 1262642885588256172
1262642885588256172 + 2716528855882462621 = 3979171741470718793
3979171741470718793 + 3978170741471719793 = 7957342482942438586
7957342482942438586 + 6858342492842437597 = -3631059097924675433
-3631059097924675433 + 3345764297909501363- = 7088702077019689060
7088702077019689060 + 0609869107702078807 = 7698571184721767867
7698571184721767867 + 7687671274811758967 = -3060501614176024782
Not found in 10 iterations.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int is_p(string s) {
  if (s.length() == 1) return 1;
  int i = 0, j = s.length() - 1;
  while (i <= j) {
    if (s[i] != s[j]) return 0;
    i++; j--;
  }
  return 1;
}

int main() {
  string A, B, C;
  cin >> A;
  if (is_p(A)) {
    cout << A << " is a palindromic number." << endl;
    return 0;
  }
  int find = 0, cnt = 0;
  while (cnt < 10) {
    string tmp_s = A;
    reverse(tmp_s.begin(), tmp_s.end());
    B.clear(); B = tmp_s;

    int tmp_c = stoi(A) + stoi(B);
    C.clear(); C = to_string(tmp_c);

    cout << A << " + " << B << " = " << C << endl;

    if (is_p(C)) {
      cout << C << " is a palindromic number." << endl;
      find = 1;
      break;
    }
    A.clear(); A = C;
    cnt++;
  }
  if (!find) {
    cout << "Not found in 10 iterations." << endl;
  }
  return 0;
}


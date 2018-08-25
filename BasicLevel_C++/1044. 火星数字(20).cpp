// Copyright [2018] <mituh>
// 1044. 火星数字(20).cpp    06:38 -> 07:17
/*
1044. 火星数字(20)

火星人是以 13 进制计数的：

地球人的 0 被火星人称为 tret。
地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：
输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam

输出样例：
hel mar
may
115
13
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;


map<string, int> mp_low;
map<string, int> mp_high;

int main() {
  int N; cin >> N;
  string low[] = {"tret", "jan", "feb", "mar", "apr", "may",
                  "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
  string high[] = {"tam", "hel", "maa", "huh", "tou", "kes",
                   "hei", "elo", "syy", "lok", "mer", "jou"};  // a-1
  for (int i = 0; i < 13; i++) {
    mp_low[low[i]] = i;
  }
  for (int i = 1; i < 13; i++) {
    mp_high[high[i-1]] = i;
  }

  string s;
  getchar();
  while (N--) {
    getline(cin, s);
    if (isdigit(s[0])) {
      int a = stoi(s) / 13, b = stoi(s) % 13;
      if (a == 0) {
        cout << low[b] << endl;
      } else {
        cout << high[a-1];
        if (b != 0) {             // case2, 4
          cout << " " << low[b];
        }
        cout << endl;
      }
    } else {
      int pos = s.find(" ");
      int ans;
      if (pos != string::npos) {
        string s1 = s.substr(0, 3), s2 = s.substr(pos+1, 3);
        ans = mp_high[s1] * 13 + mp_low[s2];
      } else {
        // ans = mp_low[s];    // eror
        auto it_low = mp_low.find(s);
        if (it_low != mp_low.end()) {
          ans = mp_low[s];
        } else {
          ans = mp_high[s] * 13;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}

// case 2, 4 wrong answer;


/*

8
0
12
13
26
27
tret
jan
hel jan
*/

/*
tret
dec
tam
hel
hel jan
0
1
27
*/

/*
tret
dec
tam tret
hel tret
hel jan
0
1
27
*/

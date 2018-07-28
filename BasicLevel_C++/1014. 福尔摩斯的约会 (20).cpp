// Copyright [2018] <mituh>
// 1014. 福尔摩斯的约会 (20).cpp    // 36 20 ->40min
/*
  思路: 用map存星期和钟头, 哪一分钟用索引

大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
输出样例：

THU 14:04

即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;
map<char, string> DAY;
map<char, int> HH;


// 计算一个数有几位数
int number_of_d(int n) {
  int ans = 0;
  if (n == 0) return 1;
  while (n) {
    ans++;
    n /= 10;
  }
// cout << "ans=" << ans << "\n";
  return ans;
}

void init() {
  DAY['A'] = "MON", DAY['B'] = "TUE", DAY['C'] = "WED", DAY['D'] = "THU",
                        DAY['E'] = "FRI", DAY['F'] = "SAT", DAY['G'] = "SUN";

  HH['0'] = 0, HH['1'] = 1, HH['2'] = 2, HH['3'] = 3, HH['4'] = 4,
      HH['5'] = 5, HH['6'] = 6, HH['7'] = 7, HH['8'] = 8, HH['9'] = 9,
      HH['A'] = 10, HH['B'] = 11, HH['C'] = 12, HH['D'] = 13, HH['E'] = 14,
      HH['F'] = 15, HH['G'] = 16, HH['H'] = 17, HH['I'] = 18, HH['J'] = 19,
      HH['K'] = 20, HH['L'] = 21, HH['M'] = 22, HH['N'] = 23;
}

int main() {
  init();
  string s1, s2, s3, s4, ans_d;
  int ans_h, ans_s;
  if (cin >> s1 >> s2 >> s3 >> s4) {
    int d_cnt = 0;
    int length1, length2;
    length1 = (s1.length() < s2.length()) ? s1.length() : s2.length();
    for (int i = 0; i < length1; i++) {
      if (s1[i] == s2[i] && DAY.count(s1[i]) && (!d_cnt)) {
        ans_d = DAY[s1[i]];
// cout << "ans_d = " << ans_d << " s1[i] = "<< tolower(s1[i]) << "\n";
        d_cnt = 1; continue;
      }
      if (s1[i] == s2[i] && HH.count(s1[i]) && (d_cnt == 1)) {
// cout << s1[i] << "\n";
        ans_h = HH[s1[i]]; break;  // 一旦连第二对都找到了, 退出循环
      }
    }

    length2 = (s3.length() < s4.length()) ? s3.length() : s4.length();
    for (int i = 0; i < length2; i++) {
      if (s3[i] == s4[i] && isalpha(s3[i])) { ans_s = i; break;}
    }

    cout << ans_d << " ";
    (number_of_d(ans_h) == 1) ? cout << "0" << ans_h : cout << ans_h;
    cout << ":";
    (number_of_d(ans_s) == 1) ? cout << "0" << ans_s : cout << ans_s;
    cout << "\n";
  }

  return 0;
}

/*
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgafdkautcfbae
d&Hybcvnmbcsrffe


./a.out
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgafdkautcfbae
d&Hybcvnmbcsrffe

THU 14:00

./a.out
3485djDkxh4hhGE 
2984akDfkk4kggEdsb 
s&hgsfdk 
d&Hyscvnm
THU 4:04
*/

// Copyright [2018] <mituh>
// 1024 科学计数法 (20).cpp   11:25 -> 11:46（P）-> 11:53(S) 1:06 => 1:20
/*
1024 科学计数法 (20)（20 point(s)） 

科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

输入格式：

每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

输出格式：

对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

输入样例1：
+1.23400E-03

输出样例1：
0.00123400

输入样例2：
-1.2E+10

输出样例2：
-12000000000

思路:
(可最后用前面计算出的数值, 配合小数点拼出了一个string)
第一个正负号作为输出时, +不输出, -输出负作为开头,
把符号和E中间的数组放入字符串
E后符号-, 小数点向左移动位置, 整数部分数字个数 in
  符号+, 小数点向右移动位置, 小数部分数字个数 fn

 符号后字符串转化成整数, syb_n,

 第二个[+-]决定, back/front, fn/in, 小数点左移/右移

 flag == 0:
-1.23E+03   fn=2, syb_n=3, 末尾添1个0
-1.230
-1.2E+10    fn=1, syb_n=10, back=syb_n-fn=9  push_back 9个0, .右移syb_n

-1.234E+03  fn=3, syb_n=3，末尾添入0个0 syb_n-fn>0添syb-n个0
-1.234

flag == 1;
+17.56E-01  in=2, syb_n=1, 1-2+1=0 不添0, 小数点左移1位  添入几个0 syb_n-in+1 <= 0 不添 
+17.56E-02  in=2, syb_n=2, 2-2+1=0, 添1个0 小数点左移2位  front=sys_n-in+1, .左移syb_n

*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main() {
  char c;
  c = getchar();
  if (c == '-') cout << "-";
  string s;     // 数组和小数点部分
  int in = 0, fn = 0, ok = 0;   // 科学计数法的整数和小数部分个数, 转换标示
  while ((c = getchar()) && c != 'E') {
    if (c == '.') {ok = 1; continue;}
    s.push_back(c);
    ok ? fn++ : in++;
  }
  // 读第二个正负号
  c = getchar();
  int flag = (c == '+') ? 0 : 1;
  // 读syb_n字符
  vector<int> syb_v;
  while ((c = getchar()) && (c != '\n') && (c != '\r')) {
    syb_v.push_back(c - '0');
  }
  // 计算syb_n
  int syb_n = 0, k = 1;
  for (int i = syb_v.size() - 1; i >= 0; i--) {
    syb_n += k * syb_v[i];
    k *= 10;
  }

  int front = syb_n-in+1, back = syb_n-fn;
  if (flag == 1) {
    if (front > 0) cout << "0.";
    for (int i = 0; i < front-1; i++) cout << "0";
    cout << s;
  }
  if (flag == 0) {
    if (back < 0) {
      int len = s.size();
      for (int i = 0; i < len; i++) {
        if (i == len+back) cout << ".";
        cout << s[i];
      }
    } else {
      cout << s;
      for (int i = 0; i < back; i++) cout << "0";
    }
  }
  cout << "\n";
  return 0;
}

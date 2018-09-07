// Copyright [2018] <mituh>
/* 1084. 外观数列.cpp 00:33 -> 1:34
1084 外观数列（20 point(s)）

外观数列是指具有以下特点的整数序列：

d, d1, d111, d113, d11231, d112213111, ...
它从不等于 1 的数字 d 开始，序列的第 n+1 项是对第 n 项的描述。
比如第 2 项表示第 1 项有 1 个 d，所以就是 d1；
第 2 项是 1 个 d（对应 d1）和 1 个 1（对应 11），所以第 3 项就是 d111。
又比如第 4 项是 d113，其描述就是 1 个 d，2 个 1，1 个 3，所以下一项就是 d11231。
当然这个定义对 d = 1 也成立。

本题要求你推算任意给定数字 d 的外观数列的第 N 项。

输入格式：

输入第一行给出 [0,9] 范围内的一个整数 d、以及一个正整数 N（≤ 40），用空格分隔。

输出格式：

在一行中给出数字 d 的外观数列的第 N 项。

输入样例：

1 8
输出样例：

1123123111

// map怎么插入一个元素, 某个元素数量+1
// map按照字典序进行排列, 不是我的原意
观察数据构造, 发现之前理解有问题..
*/

/*
// 第一遍做
#include <iostream>
#include <map>
using namespace std;

string perform(string s) {
  string tmp;
  int i = 0;
  while (i < s.length()) {
    tmp += s[i];
    int cnt = 1, j = i + 1;
    while (s[i] == s[j] && j < s.length()) { cnt++; j++;}
    tmp += cnt + '0';
    i = j;
  }
  return tmp;
}

int main() {
  string s; int N;
  cin >> s >> N;
  for (int i = 0; i < N - 1; i++) { s = perform(s); }
  std::cout << s << std::endl;
  return 0;
}
*/

// 14:23

#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; int N; cin >> s >> N;
  N--;
  while (N--) {
    string next_s = "";
    s += " ";
    int i = 1, len = s.length();
    while (i < len) {
      int cnt = 1;
      while (i < len && s[i] == s[i-1]) {
        i++;
        cnt++;
      }
      next_s += s[i-1];
      next_s += cnt + '0';
      i++;
    }
    s = next_s;
  }
  cout << s << endl;
  return 0;
}

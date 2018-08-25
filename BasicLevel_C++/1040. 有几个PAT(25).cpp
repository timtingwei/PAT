// Copyright [2018] <mituh>
// 1040. 有几个PAT(25).cpp   06:23
/*
1040 有几个PAT(25)

字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。

现给定字符串，问一共可以形成多少个 PAT？
输入格式：

输入只有一行，包含一个字符串，长度不超过10^5 ，只包含 P、A、T 三种字母。

输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。

输入样例：
APPAPT

输出样例：
2
*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; cin >> s;
  int n = s.length(), cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P') {
      for (int j = i+1; j < n; j++) {
        if (s[j] == 'A') {
          for (int k = j+1; k < n; k++) {
            if (s[k] == 'T') {
              cnt++;
            }
          }
        }
      }
    }
  }
  printf("%d\n", cnt ? cnt % 1000000007 : 0);
  return 0;
}

// 1,2AC, 后三个超时, 15分
// 如何解决3sum问题?

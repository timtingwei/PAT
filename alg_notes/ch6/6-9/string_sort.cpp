// Copyright [2018] <mituh>
// string_sort.cpp
// 按照字符串长度排序
#include <iostream>
#include <string>
using namespace std;
bool cmp(string a, string b) {
  return a.length() < b.length();
}

int main() {
  string a[3] = {"bbb", "aa", "cccc"};
  sort(a, a+3, cmp);
  for (int i = 0; i < 3; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}


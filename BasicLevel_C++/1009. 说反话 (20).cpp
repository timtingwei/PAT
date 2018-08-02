// Copyright [2018] <mituh>
// 1009. 说反话 (20).cpp
/*
Hello World Here I Come

Come I Here World Hello

思路:
1, 数组下标运算,
2, 读取字符串时入栈, 出栈输出
*/

/* 数组下标运算
#include <stdio.h>
#define MAXN 50
char s[MAXN][MAXN];
int main() {
  int n = 0;
  while (scanf("%s", s[n]) == 1) {
    n++;
  }
  for (int i = n-1; i >= 0; i--) {
    if (i != n-1) printf(" ");
    printf("%s", s[i]);
  }
  printf("\n");

  return 0;
}
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  stack<string> S;
  string elem;
  while (cin >> elem) {S.push(elem);}
  int flag = 0;
  while (!S.empty()) {
    if (flag) {
      cout << " ";
    } else {flag = 1;}
    cout << S.top();
    S.pop();
  }
  cout << endl;

  return 0;
}

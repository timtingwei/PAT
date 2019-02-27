/* Copyright [2019] <mituh> */
/* 1130-infix-expression.cpp */
/* 中缀表达树转中缀表达式, dfs  */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MaxSize 25
struct TNode {
  int l, r;
  string Data;
} T[MaxSize];

int have[MaxSize] = {0};
int ReadData(int n) {
  int i, l, r, Root; string s;
  for (i = 1; i <= n; i++) {
    cin >> s >> l >> r;
    T[i].l = l; T[i].r = r; T[i].Data = s;
    if (l != -1) have[l] = 1;
    if (r != -1) have[r] = 1;
  }
  for (Root = 1; have[Root] != 0; Root++) {}
  return Root;
}
vector<string> op = {"+", "-", "*", "/", "\\", "%"};
int IsOpr(string s) {
  int i;
  for (i = 0; i < op.size(); i++) {
    if (s == op[i]) return 1;
  }
  return 0;
}

string dfs(int Root) {
  if (Root == -1) return "";
  string ans;
  if (IsOpr(T[Root].Data)) {
    ans = "(" + dfs(T[Root].l) + T[Root].Data
        + dfs(T[Root].r) + ")";
  } else {
    ans = T[Root].Data;
  }
  return ans;
}

int main() {
  int n, Root; string ans;
  cin >> n;
  Root = ReadData(n);
  ans = dfs(T[Root].l) + T[Root].Data + dfs(T[Root].r);
  cout << ans << endl;
  return 0;
}


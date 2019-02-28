/* Copyright [2019] <mituh> */
/* 1120-friend-numbers-20.cpp */
/* set应用, hash表? */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MaxSize 10050
int have[MaxSize] = {0};
vector<int> ans;
bool cmp(int a, int b) { return a < b; }
int main() {
  int n, i, j, sum;
  string s;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    sum = 0;
    /* j中的下标别写成i */
    for (j = 0; j < s.size(); j++) { sum += (s[j] - '0'); }
    if (have[sum] == 0) {
      ans.push_back(sum);
      have[sum] = 1;
    }
  }
  sort(ans.begin(), ans.end(), cmp);
  cout << ans.size() << endl;
  int flag;
  for (i = 0, flag = 0; i < ans.size(); i++) {
    if (flag) {
      cout << " ";
    } else {
      flag = 1;
    }
    cout << ans[i];
  }
  return 0;
}

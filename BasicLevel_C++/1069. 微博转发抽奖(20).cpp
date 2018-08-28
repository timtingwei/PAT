// Copyright [2018] <mituh>
// 1069. 微博转发抽奖(20).cpp     07:27, 07:42, 08:00
/*
1069. 微博转发抽奖(20)
小明 PAT 考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔 N 个人就发出一个红包。请你编写程序帮助他确定中奖名单。

输入格式：
输入第一行给出三个正整数 M（≤ 1000）、N 和 S，分别是转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号（编号从 1 开始）。随后 M 行，顺序给出转发微博的网友的昵称（不超过 20 个字符、不包含空格回车的非空字符串）。

注意：可能有人转发多次，但不能中奖多次。所以如果处于当前中奖位置的网友已经中过奖，则跳过他顺次取下一位。

输出格式：
按照输入的顺序输出中奖名单，每个昵称占一行。如果没有人中奖，则输出 Keep going...。

输入样例 1：
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain

输出样例 1：
PickMe
Imgonnawin!
TryAgainAgain

输入样例 2：
2 3 5
Imgonnawin!
PickMe

输出样例 2：
Keep going...
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, int> mp;
vector<string> v;
int main() {
  int M, N, S; cin >> M >> N >> S;
  int keep = 1;
  getchar();
  // debug, 读入问题
  for (int i = 0; i < M; i++) {
    string tmp_s; getline(cin, tmp_s);
    v.push_back(tmp_s);
  }
  for (int i = 0; i < M; i++) {
    if (i == S-1) {
      keep = 0;
      cout << v[i] << endl;
      mp[v[i]] = 1;
      int j = i + N;
      while (j <= M-1) {
        auto it = mp.find(v[j]);
        if (it != mp.end()) {
          j = j+1;
        } else {
          cout << v[j] << endl;
          mp[v[j]] = 1;
          j = j+N;
        }
      }
      break;
    }
  }
  if (keep) {
    cout << "Keep going..." << endl;
  }
  return 0;
}

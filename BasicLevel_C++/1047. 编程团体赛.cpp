// Copyright [2018] <mituh>
// 1047. 编程团体赛.cpp 9:25 -> 9:38
/*
1047 编程团体赛（20 point(s)）

编程团体赛的规则为：每个参赛队由若干队员组成；所有队员独立比赛；参赛队的成绩为所有队员的成绩和；成绩最高的队获胜。

现给定所有队员的比赛成绩，请你编写程序找出冠军队。

输入格式：

输入第一行给出一个正整数 N（≤10
​4
​​ ），即所有参赛队员总数。随后 N 行，每行给出一位队员的成绩，格式为：队伍编号-队员编号 成绩，其中队伍编号为 1 到 1000 的正整数，队员编号为 1 到 10 的正整数，成绩为 0 到 100 的整数。

输出格式：

在一行中输出冠军队的编号和总成绩，其间以一个空格分隔。注意：题目保证冠军队是唯一的。

输入样例：

6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
输出样例：

11 176
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int scores[1000];

int main() {
  int N; string s;
  cin >> N;
  memset(scores, 0, sizeof(scores));
  getchar();
  int max = 0;
  while (N--) {
    getline(cin, s);
    string team = s.substr(0, s.find("-"));
    string score = s.substr(s.find(" ")+1, s.length());
    int i_team = stoi(team);
    scores[i_team] += stoi(score);
    if (scores[i_team] > scores[max]) max = i_team;
  }
  cout << max << " " << scores[max] << endl;
  return 0;
}

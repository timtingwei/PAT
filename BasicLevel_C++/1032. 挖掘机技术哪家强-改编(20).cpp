// Copyright [2018] <mituh>
// 1032. 挖掘机技术哪家强-改编(20).cpp
/*
1032 挖掘机技术哪家强(20)（20 point(S)）

为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

输入格式：

输入在第1行给出不超过10^5^的正整数N，即参赛人数。随后N行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

输出格式：

在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。

输入样例：

6
3 65
2 80
1 100
2 70
3 40
3 0
输出样例：

2 150
*/

// 改变题目, 如果有队伍分数并列, 按照队伍成绩先出的先后排序

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
  int team;
  int score;
  int r;
};

bool cmp(Node n1, Node n2) {
  if (n1.score != n2.score) return n1.score > n2.score;
  return n1.r < n2.r;
}

const int MAXN = 100050;
Node S[MAXN];

int main() {
  int N; cin >> N;
  memset(S, 0, sizeof(S));

  int r = 1, max = 1;
  vector<Node> v;
  for (int i = 0; i < N; i++) {
    int t, score; cin >> t >> score;
    if (!S[t].r) {
      S[t].r = r++;
      S[t].team = t;
    }
    S[t].score += score;
    if (S[t].score > S[max].score) {
      v.clear();
      v.push_back(S[t]);
      max = t;
    } else if (S[t].score == S[max].score) {
      v.push_back(S[t]);
    }
  }

  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].team << " " << v[i].score << " " << endl;
  }

  return 0;
}



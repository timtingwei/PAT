// Copyright [2018] <mituh>
// 1080. MOOC期终成绩(25).cpp        11:11 -> 12:19
/*
1080 MOOC期终成绩（25 point(s)）

对于在中国大学MOOC（http://www.icourse163.org/ ）学习“数据结构”课程的学生，想要获得一张合格证书，必须首先获得不少于200分的在线编程作业分，然后总评获得不少于60分（满分100）。总评成绩的计算公式为 G=(G​mid−term×40%+G final×60%)，如果 Gmid−term>Gfinal；否则总评 G 就是 G​final。这里 Gmid−term和 Gfinal分别为学生的期中和期末成绩。

现在的问题是，每次考试都产生一张独立的成绩单。本题就请你编写程序，把不同的成绩单合为一张。

输入格式：

输入在第一行给出3个整数，分别是 P（做了在线编程作业的学生数）、M（参加了期中考试的学生数）、N（参加了期末考试的学生数）。每个数都不超过10000。

接下来有三块输入。第一块包含 P 个在线编程成绩 Gp
​​ ；第二块包含 M 个期中考试成绩 G​mid−term
​​ ；第三块包含 N 个期末考试成绩 G​final
​​ 。每个成绩占一行，格式为：学生学号 分数。其中学生学号为不超过20个字符的英文字母和数字；分数是非负整数（编程总分最高为900分，期中和期末的最高分为100分）。

输出格式：

打印出获得合格证书的学生名单。每个学生占一行，格式为：

学生学号 G​p G​mid−term G​final G

如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“−1”。输出顺序为按照总评分数（四舍五入精确到整数）递减。若有并列，则按学号递增。题目保证学号没有重复，且至少存在1个合格的学生。

输入样例：

6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
输出样例：

missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
  string id;
  int p = -1;
  int mid = -1;
  int final = -1;
  int total = -1;
};
vector<Node> v;

bool cmp(Node n1, Node n2) {
  if (n1.total != n2.total) return n1.total > n2.total;
  return n1.id <= n2.id;
}

int main() {
  int P, M, N;
  cin >> P >> M >> N;
  map<string, Node> mp;
  string tmp_id; int tmp_p, tmp_mid, tmp_final;
  while (P--) {
    cin >> tmp_id >> tmp_p;
    mp[tmp_id].id = tmp_id;
    mp[tmp_id].p = tmp_p;
  }
  while (M--) {
    cin >> tmp_id >> tmp_mid;
    mp[tmp_id].id = tmp_id;
    mp[tmp_id].mid = tmp_mid;
  }
  while (N--) {
    cin >> tmp_id >> tmp_final;
    mp[tmp_id].id = tmp_id;
    mp[tmp_id].final = tmp_final;
  }

  for (auto it = mp.begin(); it != mp.end(); it++) {
    // cout << it->second.id << endl;
    tmp_p = (it->second.p == -1) ? 0 : it->second.p;
    tmp_mid = (it->second.mid == -1) ? 0 : it->second.mid;
    tmp_final = (it->second.final == -1) ? 0 : it->second.final;

    if (tmp_p >= 200) {
      int total = (tmp_mid > tmp_final) ?
          floor((tmp_mid * 0.4 + tmp_final * 0.6) + 0.5) : tmp_final;
      it->second.total = total;
      if (it->second.mid == -1 && it->second.final == -1) it->second.total = -1;
      if (total >= 60) {
        v.push_back(it->second);
      }
    }
  }

  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].id << " " << v[i].p << " " << v[i].mid
         << " " << v[i].final << " " << v[i].total << endl;
  }

  return 0;
}

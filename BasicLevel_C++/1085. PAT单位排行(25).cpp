// Copyright [2018] <mituh>
// 1085. PAT单位排行(25).cpp    06:00->06:46(case5WA)->07:11(debug case5)
/*
1085 PAT单位排行（25 point(s)）

每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个功能。

输入格式：
输入第一行给出一个正整数 N（≤10^​5），即考生人数。随后 N 行，每行按下列格式给出一个考生的信息：
准考证号 得分 学校
其中准考证号是由 6 个字符组成的字符串，其首字母表示考试的级别：B代表乙级，A代表甲级，T代表顶级；得分是 [0, 100] 区间内的整数；学校是由不超过 6 个英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。

输出格式：
首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：
排名 学校 加权总分 考生人数
其中排名是该单位的排名（从 1 开始）；学校是全部按小写字母输出的单位码；加权总分定义为乙级总分/1.5 + 甲级总分 + 顶级总分*1.5的整数部分；考生人数是该属于单位的考生的总人数。

学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。

输入样例：
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu

输出样例：
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/

// 第三次做
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;


struct Node_a {
  string school;
  double full_score;
  int num;
};

struct Node_b {
  double score;
  int num;
};

int db_equal(double d1, double d2) {
  return (-0.005 < d1 - d2) && (d1-d2 < 0.005);
}

/*
bool cmp(Node_a n1, Node_a n2) {
  if (!(db_equal(n1.full_score, n2.full_score))) return n1.full_score > n2.full_score;
  if (n1.num != n2.num) return n1.num < n2.num;
  return n1.school < n2.school;
}
*/
bool cmp(Node_a n1, Node_a n2) {
  if ((int)n1.full_score != (int)n2.full_score) return (int)n1.full_score > (int)n2.full_score;
  if (n1.num != n2.num) return n1.num < n2.num;
  return n1.school < n2.school;
}

int main() {
  int N; cin >> N;
  unordered_map<string, Node_b> mp;
  while (N--) {
    string id, school; double score;
    cin >> id >> score >> school;
    for (int i = 0; i < school.length(); i++) {
      school[i] = tolower(school[i]);     // lower all school chars
    }
    // convert score;
    if (id[0] == 'B') {
      score = score / 1.5;
    } else if (id[0] == 'T') {
      score = score * 1.5;
    }
    auto it = mp.find(school);
    if (it != mp.end()) {
      it->second.score += score;
      it->second.num++;
    } else {
      Node_b node;
      node.score = score; node.num = 1;
      mp[school] = node;
    }
  }
  vector<Node_a> v;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    v.push_back({it->first, it->second.score, it->second.num});
  }

  sort(v.begin(), v.end(), cmp);

  cout << v.size() << endl;
  int rank = 1;
  cout << rank << " " << v[0].school << " " << (int)v[0].full_score << " " << v[0].num << endl;
  for (int i = 1; i < v.size(); i++) {
    if ((int)v[i].full_score != (int)v[i-1].full_score) rank = i+1;
    cout << rank << " " << v[i].school << " " << (int)v[i].full_score << " " << v[i].num << endl;
  }


  return 0;
}

/*
// 第二次做
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
  string name;
  int score;
  int num;
};

unordered_map<string, Node> mp;
unordered_map<string, double> sum;
unordered_map<string, int> num;

vector<Node> v;   // bug01

bool cmp(Node n1, Node n2) {
  if (n1.score != n2.score) return n1.score >= n2.score;
  if (n1.num != n2.num) return n1.num < n2.num;
  return n1.name < n2.name;
}

int main() {
  int N; scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    string id, school; double score;
    cin >> id;
    scanf("%lf", &score);
    cin >> school;
    for (int i = 0; i < school.length(); i++) {
      school[i] = tolower(school[i]);
    }
    if (id[0] == 'B') {
      score = score / 1.5;
    } else if (id[0] == 'T') {
      score = score * 1.5;
    }
    if (!mp.count(school)) {
      mp[school].name = school;
    }
    sum[school] += score;   // bug05
    num[school]++;
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    v.push_back(Node{it->first, (int)sum[it->first], num[it->first]});
  }
  // case7在排序时候已经在比较score
  sort(v.begin(), v.end(), cmp);

  cout << v.size() << endl;                 // bug07
  int r = 1;
  cout << r << " " << v[0].name << " " << v[0].score << " " << v[0].num << endl;
  for (int i = 1; i < v.size(); i++) {
    if (v[i].score != v[i-1].score) {
      r = i + 1;
    }
    cout << r << " " << v[i].name << " " << v[i].score << " " << v[i].num << endl;
  }
  return 0;
}
*/

/*
// 第一次实现的版本
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
  string name;
  double score = 0;
  int num = 0;
};

map<string, Node> mp;
vector<Node> v;   // bug01

bool cmp(Node n1, Node n2) {
  if (n1.score != n2.score) return n1.score >= n2.score;
  if (n1.num != n2.num) return n1.num < n2.num;
  return n1.name < n2.name;
}

const double EP = 0.2;
int main() {
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    string id, school; double score;
    cin >> id >> score >> school;
    // string tolower   bug04
    for (int i = 0; i < school.length(); i++) {
      school[i] = tolower(school[i]);
    }
    if (id[0] == 'B') {
      // score /= 1.5;
      score = score / 1.5;
    } else if (id[0] == 'T') {
      // score *= 1.5;
      score = score * 1.5;
    }
    // if (!mp.find(id)) {     // bug03
    if ((mp.find(id)->second.name).empty()) {   // why?
      mp[school].name = school;
    }
    // mp[school].score = score;
    mp[school].score += score;   // bug05
    mp[school].num++;
  }

  for (auto it = mp.begin(); it != mp.end(); it++) {
    // v.push(it->second);   // bug02 + bug06
    Node node;
    node.name = it->second.name;
    node.score = (int)it->second.score;    // important!
    node.num = it->second.num;
    // v.push_back(Node{it->second.name, (int)it->second.score, it->second.num});
    v.push_back(node);
  }
  // case7在排序时候已经在比较score
  sort(v.begin(), v.end(), cmp);

  cout << v.size() << endl;                 // bug07
  int r = 1;
  cout << r << " " << v[0].name << " " << v[0].score << " " << v[0].num << endl;
  for (int i = 1; i < v.size(); i++) {
    // if (v[i].score != v[i-1].score) {    // bug06
    // int score1 = (int)v[i].score, score2 = (int)v[i-1].score;
    // if (-EP < v[i].score - v[i-1].score
    //     && v[i].score - v[i-1].score < EP) {
    // double d = v[i].score - v[i-1].score;
    // cout << v[i].score << " " <<  v[i-1].score << "d = " << d << endl;
    // if (-EP < d && d < EP) {
    //  // ..
    // } else {
    //   r = i + 1;
    // }
    if (v[i].score != v[i-1].score) {
      r = i + 1;
    }
    // if (v[i].score != v[i-1].score) {
    //   r = i + 1;
    // }  // else r = r;
    cout << r << " " << v[i].name << " " << v[i].score << " " << v[i].num << endl;
  }
  return 0;
}


// case5 wrong ans

*/

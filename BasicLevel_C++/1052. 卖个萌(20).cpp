// Copyright [2018] <mituh>
// 1052. 卖个萌(20).cpp 22:24 -> 23:51 这题真烦 -> 12:53
/*
1052 卖个萌（20 point(s)）

萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：

[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。

输入格式：

输入首先在前 三 行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号 []内。
题目保证每个集合都至少有一个符号，并不超过 10 个符号；
每个符号包含 1 到 4 个非空字符。

之后一行给出一个正整数 K，为用户请求的个数。
随后 K 行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从 1 开始），数字间以空格分隔。

输出格式：

对每个用户请求，在一行中输出生成的表情。
若用户选择的序号不存在，则输出 Are you kidding me? @\/@。

输入样例：

[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
输出样例：

╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@


思路:
二维数组存{ 手, 眼, 口}
           1   2  3
用户给出的对应 (1,x) (2,x) (3,x)  (2,x)  (1,x)


case 1: Presentation Error
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3

case 2: a, b, c, d, e不能小于1, 要控制输入的合法性
*/

/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
  vector<vector<string> > v;
  for (int i = 0; i < 3; i++) {
    string s;
    getline(cin, s);
    vector<string> row;
    int j = 0, k = 0;
    while (j < s.length()) {
      if (s[j] == '[') {
        k = j+1;
        while (k < s.length()) {
          if (s[k] == ']') {
            row.push_back(s.substr(j+1, k-j-1));
// cout << s.substr(j+1, k-j-1) << endl;
            break;
          }
          k++;
        }
      }
      j++;
    }
    v.push_back(row);
  }
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b, c, d, e;   // 0 1 2 1 0
    cin >> a >> b >> c >> d >> e;
    if (a > v[0].size() || b > v[1].size() || c > v[2].size()
        || d > v[1].size() || e > v[0].size()
        || a < 1 || b < 1 || c < 1 || d < 1 || e < 1) {  // case 2
      cout << "Are you kidding me? @\\/@" << endl;
      continue;
    }
    cout << v[0][a-1]
         << "(" << v[1][b-1] << v[2][c-1] << v[1][d-1] << ")"
         << v[0][e-1] << endl;
  }
  return 0;
}
*/


/*
vector<vector<string> > emoji;
int main() {
  string line; vector<string> row;
  for (int i = 0; i < 3; i++) {
    getline(cin, line);
    int j = 0;
    string an_emoji; int flag = 0;
    while (j < line.length()) {
      if (line[j] == '[') {
        flag = 0; j++; continue;
      } else if (line[j] == ']') {
        flag = 1;
        row.push_back(an_emoji);
// cout << "an_emoji= " << an_emoji << "\n";
        an_emoji.clear();
      }
      if (flag == 0) {an_emoji += line[j];}
      j++;
    }
    emoji.push_back(row);
    row.clear();
// cout << "len=" << row.size() << "\n";
// cout << line << "\n";
  }

  int N;
  cin >> N;
  // 左手、左眼、口、右眼、右手
  for (int i = 0; i < N; i++) {
    int left_h, left_e, m, right_e, right_h;
    cin >> left_h >> left_e >> m >> right_e >> right_h;
    // --left_h, --left_e, --m, --right_e, --right_h;
    if (left_h > emoji[0].size() || left_e > emoji[1].size()
        || m > emoji[2].size() || right_e > emoji[1].size()
        || right_h > emoji[0].size()) {
      cout << "Are you kidding me? @\\/@" << endl;
      continue;
    }
    cout << emoji[0][left_h-1] << "("
         << emoji[1][left_e-1] << emoji[2][m-1] << emoji[1][right_e-1] << ")"
         << emoji[0][right_h-1] << endl;
  }

  return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string> > emoji;
int order[6] = {0, 1, 2, 1, 0};

int main() {
  for (int k = 0; k < 3; k++) {
    string s;
    getline(cin, s);
    int n = s.length();
    vector<string> row;
    int i = 0, j = 0;
    while (i < n) {
      if (s[i] == '[') {
        string tmp_s;
        j = i+1;
        while (j < n && s[j] != ']') j++;
        tmp_s = s.substr(i+1, j-i-1);                 // bug02
        row.push_back(tmp_s);
        i = j;
      } else {
        i++;
      }
    }
    emoji.push_back(row);
  }

  int K; cin >> K;
  for (int k = 0; k < K; k++) {
    if (k) cout << endl;
    string ans_s; int ok = 1;
    for (int i = 0; i < 5; i++) {
      int tmp; cin >> tmp;
      int n = emoji[order[i]].size();
      // if (tmp < 0 || tmp > n-1) {                  // bug04
      if (tmp < 1 || tmp > n) {
        // cout << "Are you kidding me? @\\/@\n";     // bug01
        ok = 0;
        break;
      }
      if (i == 1) ans_s += "(";
      else if (i == 4) ans_s += ")";
      ans_s += emoji[order[i]][tmp-1];
    }
    if (ok) {
      cout << ans_s;
    } else {
      cout << "Are you kidding me? @\\/@";            // bug03
    }
  }
  return 0;
}

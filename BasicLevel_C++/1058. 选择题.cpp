// Copyright [2018] <mituh>
// 1058. 选择题.cpp 02:31 -> 04:55  仍旧没有debug完
/*
1058 选择题（20 point(s)）

批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。

输入格式：

输入在第一行给出两个正整数 N（≤ 1000）和 M（≤ 100），分别是学生人数和多选题的个数。
随后 M 行，每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。
注意每题的选项从小写英文字母 a 开始顺次排列。
各项间以 1 个空格分隔。
最后 N 行，每行给出一个学生的答题情况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。
注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。



#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef struct Node {
  int score, n, right_n;
  char right_s[6];
} *NodePtr;

vector<NodePtr> v;
int wrong[105];


void_print_wrong(int *wrong, int M) {
  sort(wrong, wrong, M);    // 在数组中做只是因为处理不好vector索引添加
  vector<int> wrong_v;
  for (int i = 0; i < M; i++) wrong_v.push_back(wrong[i]);
  vector<int> min_i;
  sort(wrong_v, wrong_v.begin(), wrong_v.end());
  for (int i = 0; i < M; i++) {
    if (wrong_v[0] == wrong[i]) min_i.push_back(i);
  }
  for (int i = 0; i < min_i.size(); i++) {
    cout << wrong_v[0] << " ";
  }

  for (int i = 0; i < min_i.size(); i++) {
    cout << min_i[i] << " ";
  }
  cout << endl;
}

int main() {
  int N, M;    // 学生人数和题数
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> v[i]->score >> v[i]->n >> v[i]->right_n;
    for (int j = 0; j < (v[i]->right_n); j++) cin >> v[i]->right_s[j];
  }
  memset(wrong, 0, sizeof(wrong));
  for (int i = 0; i < N; i++) {
    string s;
    getline(cin, s);
    int j = 0;
    int qi = 0;                  // 正在回答第几题
    int sum = 0;               // 总分
    while (j < s.length()) {       // 遍历一个同学的回答
      if (s[j] == '(') {           // 判断某一题答案是否匹配
        int n = s[j+1];
        if (n != v[i]->right_n) { wrong[qi++]++; j += (n+1)*2; continue;}  // 答错 ??
        string sub = s.substr(j+1, 2*n);
        int opi = 0;               // 正在回答第几个选项
        int ok = 1;
        for (int x = 0; x < sub.length(); x++) {
          if (sub[x] == ' ') continue;
          if (sub[x] != v[qi]->right_s[opi++]) { ok = 0; wrong[qi++]++; break;}
        }
        if (ok) sum += v[qi]->score;   // 如果正确总分就要加
        j += (n+1)*2;                  // 结束这题目的字符判断
      }
      j++;
    }
    printf("sum=%d\n", sum);   // 打印总分
  }
  print_wrong(M);
}






输出格式：

按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从 1 开始编号）。如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出 Too simple。

输入样例：

3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
输出样例：

3
6
5
2 2 3 4

思路: 题的信息放在一个Node里, Node用vector保存, 对每个同学来说, 判断M道题哪几道做错的, 每题做错的放在一个数组里, 若有错误, 输出错误最大的题错误次数和编号, 并列编号递增.每个同学答案先读取整行string, 找到一个括号开始读数字, 数字后, 若数字不同直接判错, 否则, 用下标读取答案, 读到一个字符就比较答案, 跟正确答案对比(顺序一样), 正确在总分上累加该题分数, 判断完一行后输出分数.
 */


// /*
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node {
  int score, n, right_n;
  // char right_s[6];
  vector<char> right_s;
} *NodePtr;

vector<NodePtr> v;
int wrong[105];


void print_wrong(int M) {
  // sort(wrong, wrong, M);    // 在数组中做只是因为处理不好vector索引添加
  vector<int> wrong_v;
  for (int i = 0; i < M; i++) {
    cout << wrong[i] << endl;
    wrong_v.push_back(wrong[i]);
  }
  vector<int> min_i;
  sort(wrong_v.begin(), wrong_v.end());
  for (int i = 0; i < M; i++) {
    if (wrong_v[0] == wrong[i]) min_i.push_back(i);
  }
  for (int i = 0; i < min_i.size(); i++) {
    cout << wrong_v[0] << " ";
  }

  for (int i = 0; i < min_i.size(); i++) {
    cout << min_i[i] << " ";
  }
  cout << endl;
}

int main() {
  int N, M;    // 学生人数和题数
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    NodePtr pNode;
    if (!(pNode = (NodePtr) malloc (sizeof(Node))))  // debug1, 使用结点分配空间
      exit(-1);
    cin >> pNode->score >> pNode->n >> pNode->right_n;
    cout << "i = " << i << " right_n = " << pNode->right_n << endl;
    for (int j = 0; j < pNode->right_n; j++) {
      char ch; cin >> ch;
      pNode->right_s.push_back(ch);
    }
    v.push_back(pNode);
  }

  memset(wrong, 0, sizeof(wrong));
  int i = 0;
  while (i < N) {
    // for (int i = 0; i < N; i++) {
    string s;
    getline(cin, s);                // debug2:getline读到空行
    if (s.empty()) continue;
    cout << "s=" << s << endl;
    int j = 0;
    int qi = 0;                     // 正在回答第几题
    int sum = 0;                    // 总分
    while (j < s.length()) {        // 遍历一个同学的回答
// printf("j = %d\n", j);
      if (s[j] == '(') {            // 判断某一题答案是否匹配
        int n = s[j+1] - '0';       // debug3: 字符转数字
        if (n != v[qi]->right_n) {  // debug4: 题号写成i
          wrong[qi]++;
        } else {
          string sub = s.substr(j+2, 2*n);
          int opi = 0;               // 正在回答第几个选项
          int ok = 1;
          for (int x = 0; x < sub.length(); x++) {
            if (sub[x] == ' ') continue;
            if (sub[x] != v[qi]->right_s[opi++]) { ok = 0; break;}
          }
          if (ok) {
            sum += v[qi]->score;      // 如果正确总分就要加
          } else {
            wrong[qi]++;              // 错误统计
          }
        }
        j += (n+1)*2;                // 结束这题目的字符判断
        qi++;                       // debug5: 没有把题号加上
      }
      j++;
    }
    printf("sum=%d\n", sum);   // 打印总分
    i++;
  }
  print_wrong(M);
  return 0;
}

// */

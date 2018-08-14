// Copyright [2018] <mituh>
// 1083. 是否存在相等的差(20).cpp  09:49 -> 10:12
/*
1083 是否存在相等的差（20 point(s)）

给定 N 张卡片，正面分别写上 1、2、……、N，然后全部翻面，洗牌，在背面分别写上 1、2、……、N。将每张牌的正反两面数字相减（大减小），得到 N 个非负差值，其中是否存在相等的差？

输入格式：

输入第一行给出一个正整数 N（2 ≤ N ≤ 10 000），随后一行给出 1 到 N 的一个洗牌后的排列，第 i 个数表示正面写了 i 的那张卡片背面的数字。

输出格式：

按照“差值 重复次数”的格式从大到小输出重复的差值及其重复的次数，每行输出一个结果。

输入样例：

8
3 5 8 6 2 1 4 7
输出样例：

5 2
3 3
2 2
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 10000
typedef struct {
  int delta;
  int cnt;
} Node;

int cnt[MAXN];
vector<Node> ans;

int cmp(Node n1, Node n2) {
  return  n1.delta > n2.delta;
}

int main() {
  int N, v;
  cin >> N;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < N; i++) {
    cin >> v;
    int d = (i < v) ? v-(i+1) : (i+1)-v;
    cnt[d]++;
  }

  for (int i = 0; i < MAXN; i++) {
    if (cnt[i] > 1) {
      Node node;
      node.delta = i; node.cnt = cnt[i];
      ans.push_back(node);
    }
  }

  sort(ans.begin(), ans.end(), cmp);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].delta << " " << ans[i].cnt << endl;
  }
  return 0;
}

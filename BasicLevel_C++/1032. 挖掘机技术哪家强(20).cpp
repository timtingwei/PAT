// Copyright [2018] <mituh>
// 1032. 挖掘机技术哪家强(20).cpp 21:32 -> 21:45  十分钟秒
/*
1032 挖掘机技术哪家强(20)（20 point(s)）

为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

输入格式：

输入在第1行给出不超过10^5^的正整数N，即参赛人数。
随后N行，每行给出一位参赛者的信息和成绩，
包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

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

思路: 用数组存各个学校的总分, 计算完成之后, 得出总分最高的索引和总分
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 100050;
int scores[MAXN];

int main() {
  int N, max_i = -1, max_score = -1;
  // memset(scores, 0, sizeof(scores));   // 这句造成编译错误
  cin >> N;
  for (int i = 0; i < N; i++) {
    int j, tmp_s;
    cin >> j >> tmp_s;
    scores[j] += tmp_s;
    if (scores[j] > max_score) { max_i = j; max_score = scores[j];}
  }
  cout << max_i << " " << max_score << "\n";
  return 0;
}

/*
// 第二遍做
#include <cstdio>
using namespace std;

int score[100500] = {0};
int main() {
  int N, max_id; scanf("%d", &N);
  int max = 0;
  while (N--) {
    int id, temp;
    scanf("%d %d", &id, &temp);
    score[id] += temp;
    if (score[id] > max) {
      max_id = id; max = score[id];
    }
  }
  printf("%d %d\n", max_id, max);
  return 0;
}

*/

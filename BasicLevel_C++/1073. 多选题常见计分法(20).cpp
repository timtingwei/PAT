// Copyright [2018] <mituh>
// 1073. 多选题常见计分法(20).cpp        22:47->23:16(敲和调试)
/*
1073 多选题常见计分法(20)

批改多选题是比较麻烦的事情，有很多不同的计分方法。有一种最常见的计分方法是：如果考生选择了部分正确选项，并且没有选择任何错误选项，则得到 50% 分数；如果考生选择了任何一个错误的选项，则不能得分。本题就请你写个程序帮助老师批改多选题，并且指出哪道题的哪个选项错的人最多。

输入格式：
输入在第一行给出两个正整数 N（≤1000）和 M（≤100），分别是学生人数和多选题的个数。随后 M 行，每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母 a 开始顺次排列。各项间以 1 个空格分隔。最后 N 行，每行给出一个学生的答题情况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行，输出小数点后 1 位。最后输出错得最多的题目选项的信息，格式为：错误次数 题目编号（题目按照输入的顺序从1开始编号）-选项号。如果有并列，则每行一个选项，按题目编号递增顺序输出；再并列则按选项号递增顺序输出。行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出 Too simple。

输入样例 1：
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)

输出样例 1：
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b

输入样例 2：
2 2 
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)

输出样例 2：
5.0
5.0
Too simple
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 105;

int main() {
  int N, M;
  int temp = 0, full_score[MAXN], right_num[MAXN], opts_num[MAXN],
      right_opts[MAXN], opts[1005][MAXN], err_cnt[105][6];
  char c;
  memset(full_score, 0, sizeof(full_score));
  memset(right_opts, 0, sizeof(right_opts));
  memset(opts, 0, sizeof(opts));
  memset(err_cnt, 0, sizeof(err_cnt));
  int hash[] = {1, 2, 4, 8, 16};
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &full_score[i], &opts_num[i], &right_num[i]);
    for (int j = 0; j < right_num[i]; j++) {
      scanf(" %c", &c);
      right_opts[i] += hash[c-'a'];
    }
  }

  for (int i = 0; i < N; i++) {
    double score = 0.0;
    for (int j = 0; j < M; j++) {
      getchar();
      getchar();  // "("
      scanf("%d", &temp);
      for (int k = 0; k < temp; k++) {
        scanf(" %c", &c);
        opts[i][j] += hash[c - 'a'];
      }
      getchar();  // ")"      // debug01
      int el = opts[i][j] ^ right_opts[j];

      if (el) {
        if ((opts[i][j] | right_opts[j]) == right_opts[j]) {
          score += 0.5*full_score[j];
        }

        if (el & hash[0]) err_cnt[j][0]++;   // a
        if (el & hash[1]) err_cnt[j][1]++;   // b
        if (el & hash[2]) err_cnt[j][2]++;   // c
        if (el & hash[3]) err_cnt[j][3]++;   // d
        if (el & hash[4]) err_cnt[j][4]++;   // e
      } else {
        score += full_score[j];
      }
    }
    printf("%.1lf\n", score);
  }

  int max_cnt = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 5; j++) {
      max_cnt = err_cnt[i][j] > max_cnt ? err_cnt[i][j] : max_cnt;
    }
  }

  if (max_cnt) {
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < 5; j++) {
        if (err_cnt[i][j] == max_cnt) {
          printf("%d %d-%c\n", max_cnt, i+1, j+'a');
        }
      }
    }
  } else {
    printf("Too simple\n");
  }

  return 0;
}

/*
int main() {
  int ans, b, temp = 0;
  int hash[] = {1, 2, 4, 8, 16};
  scanf("%d", &temp);
  for (int i = 0; i < temp; i++) {
    char c;
    scanf(" %c", &c);
    ans += hash[c-'a'];
  }

  scanf("%d", &temp);
  for (int i = 0; i < temp; i++) {
    char c;
    scanf(" %c", &c);
    b += hash[c-'a'];
  }

  printf("ans ^ b = %d\n", ans ^ b);
  return 0;
}
*/

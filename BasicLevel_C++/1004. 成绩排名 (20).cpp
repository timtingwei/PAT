// copyright [2018] <mituh>
// 1004. 成绩排名 (20).cpp
/*
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：

Mike CS991301
Joe Math990112
*/
#include <stdio.h>
#include <string.h>
#define MAXN 100 + 10
char name[MAXN][15];
char id[MAXN][15];
int grade[MAXN];

int main() {
  int n;
  if (scanf("%d", &n) != EOF && n) {
    for (int i = 0; i < n; i++) scanf("%s %s %d", name[i], id[i], &grade[i]);
    int max_i = 0, min_i = 0;
    for (int i = 1; i < n; i++) {
      if (grade[i] > grade[max_i]) max_i = i;
      if (grade[i] < grade[min_i]) min_i = i;
    }
    printf("%s %s\n", name[max_i], id[max_i]);
    printf("%s %s\n", name[min_i], id[min_i]);
  }

  return 0;
}

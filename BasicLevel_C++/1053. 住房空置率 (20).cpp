// Copyright [2018] <mituh>
// 1053. 住房空置率 (20).cpp 01:10 -> 2:45, 思路出错, case2, 3不能ac

/*
1053. 住房空置率 (20)
在不打扰居民的前提下，统计住房空置率的一种方法是根据每户用电量的连续变化规律进行判断。判断方法如下：
在观察期内，若存在超过一半的日子用电量低于某给定的阈值e，则该住房为“可能空置”；
若观察期超过某给定阈值D天，且满足上一个条件，则该住房为“空置”。
现给定某居民区的住户用电量数据，请你统计“可能空置”的比率和“空置”比率，即以上两种状态的住房占居民区住房总套数的百分比。

输入格式：
输入第一行给出正整数N（<=1000），为居民区住房总套数；正实数e，即低电量阈值；正整数D，即观察期阈值。随后N行，每行按以下格式给出一套住房的用电量数据：
K E1 E2 … EK
其中K为观察的天数，Ei为第i天的用电量。

输出格式：
在一行中输出“可能空置”的比率和“空置”比率的百分比值，其间以一个空格分隔，保留小数点后1位。

输入样例：
5 0.5 10
6 0.3 0.4 0.5 0.2 0.8 0.6
10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5
5 0.4 0.3 0.5 0.1 0.7
11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1
11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1

输出样例：
40.0% 20.0%
（样例解释：第2、3户为“可能空置”，第4户为“空置”，其他户不是空置。）

// 思路出错, 观察期k超过D, 且满足条件1, 判断为空置
*/

#include <cstdio>
int main() {
  int N, D; double e;
  scanf("%d %lf %d", &N, &e, &D);
  int cnt_may = 0, cnt_empty = 0;
  for (int i = 0; i < N; i++) {
    int k, cnt = 0;
    double tmp;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%lf", &tmp);
      if (tmp < e) {            // bug3?
        cnt++;
      }
    }
    if (cnt > k/2 && k > D) {   // case2, 3
      cnt_empty++;
    } else if (cnt > k/2) {
      cnt_may++;
    }
  }
  printf("%.1lf%% %.1lf%%\n", (double)cnt_may / N * 100, (double)cnt_empty / N * 100);  // why

  return 0;
}


/*
#include <cstdio>
int main() {
  int N, D; double e; scanf("%d %lf %d", &N, &e, &D);
  int cnt_may = 0, cnt_empty = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int k; scanf("%d", &k);
    int j = 0, cnt = 0, flag = 0;
    double tmp;
    while (j < k && j < D) {
      scanf("%lf", &tmp);
      if (tmp < e) {
        cnt++;
        if (cnt > D/2) {flag = 1; break;}
      }
      j++;
    }
    
    while (j < k && flag == 1) {
      scanf("%lf", &tmp);
      if (tmp < e) {
        cnt++;
        if (cnt > D) {flag = 2; break;}
      }
      j++;
    }
    if (flag == 1) cnt_may++;
    else if (flag == 2) cnt_empty++;
  }
  printf("%.1f%c %.1f%c\n", double(cnt_may*100) / N, '%', double(cnt_empty*100) / N, '%');
  
  return 0;
}
*/

/*
#include <cstdio>
int main() {
  int N, D; double e;
  scanf("%d %lf %d", &N, &e, &D);
  int cnt_may = 0, cnt_empty = 0;
  for (int i = 0; i < N; i++) {
    int k; scanf("%d", &k);
    int cnt = 0, flag = 0;
    double tmp;
    for (int j = 0; j < k; j++) {
      scanf("%lf", &tmp);
      if (tmp - e < -0.0000000005) {    // bug2?
        cnt++;
        if (cnt > k/2 && flag == 0) flag = 1;    // bug2
        else if (cnt > D && flag == 1) flag = 2;
      }
    }
    if (flag == 1) cnt_may++;
    else if (flag == 2) cnt_empty++;
// printf("flag = %d\k", flag);
  }
  printf("%.1f%c %.1f%c\n", double(cnt_may*100) / N, '%', double(cnt_empty*100) / N, '%');  // why

  return 0;
}

// case1, 2, 5 wrong answer;

*/


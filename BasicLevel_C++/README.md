## Basic-PAT-C++
### 1053. 住房空置率 (20)
在不打扰居民的前提下，统计住房空置率的一种方法是根据每户用电量的连续变化规律进行判断。判断方法如下：
在观察期内，若存在超过一半的日子用电量低于某给定的阈值e，则该住房为“可能空置”；
若观察期超过某给定阈值D天，且满足上一个条件，则该住房为“空置”。
现给定某居民区的住户用电量数据，请你统计“可能空置”的比率和“空置”比率，即以上两种状态的住房占居民区住房总套数的百分比。

#### 输入格式：
输入第一行给出正整数N（<=1000），为居民区住房总套数；正实数e，即低电量阈值；正整数D，即观察期阈值。随后N行，每行按以下格式给出一套住房的用电量数据：
K E1 E2 … EK
其中K为观察的天数，Ei为第i天的用电量。

#### 输出格式：
在一行中输出“可能空置”的比率和“空置”比率的百分比值，其间以一个空格分隔，保留小数点后1位。

#### 输入样例：
5 0.5 10
6 0.3 0.4 0.5 0.2 0.8 0.6
10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5
5 0.4 0.3 0.5 0.1 0.7
11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1
11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1

#### 输出样例：
40.0% 20.0%
（样例解释：第2、3户为“可能空置”，第4户为“空置”，其他户不是空置。）

#### Solution:

<span style="color:red">思路出错, 观察期k超过D, 且满足条件1, 判断为空置</span>

case2, 3一直过不了。我刚开始认为低于阈值e的天数超过D的时候, 就判为空, 但后来再仔细看, 题目明显是在说, 观察期k超过D。

<span style="color:red">以后条件判断有嵌套和层级的, 一定要注意他们之间的关系, 条件具体是什么, 是否互斥</span>

坑点:
1, 可能空置和空置是互斥的, 因此用if .. else if
2, 这里虽然是double类型, 但是对于double类型来说, 判等需要注意精度问题, 如代码2
3, printf输出保留一位的double类型, `printf("%.1lf", db);`  打印`%`, `printf("%%");`


代码2:
```cpp
const int EPSINON = 0.000001;
// if (db1 == db2) {// ..}
if (db1 - db2 >= -EPSINON && db1 - db2 <= EPSINON) {//..}
```


代码3:
```cpp
// c++ cout用setprecision(n), 设置精度, 搭配fixed, 需要iomanip头文件
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  double v = 10;
  cout << fixed << setprecision(8) << v << endl;
  return 0;
}
```



```cpp
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
```


### 1050 螺旋矩阵（25 point(s)）

本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。
#### 输入格式：
输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过10^4​​, 相邻数字以空格分隔。
#### 输出格式：
输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。
#### 输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
#### 输出样例：
98 95 93
42 37 81
53 20 76
58 60 76
#### Solution:

从1开始递增m, m >= n且差值较小但比0大时候更新min_m, (这里坑点是m能取到N, N = 19, m = 19, n = 1)

用i,j下标代表一个pointer, 移动pointer就是移动i,j; 用flag标记移动的方向, 再设置好上下左右四个边界, 对触碰到边界的情况, 移动的指针回撤, 某个边界缩短(下回不能在进入了), 指针方向改变.

case2, 答案错误, 应该是1 1 输出1的情况
case6, 7 段错误, 在submit的时候, 一阵乱试。回头想, 如果数组开在外面还发生段错误, 那就是数组开的太小了. 但是如果数组开大又超时的话, 把对二维数组来说, 外层开得大些, 内层开的小些.

需要多练习一些模拟题, 模拟题跟那些有明确tag的题不同, 题目出的比较活, 在某种思路下, 可以需要多种算法组合.


```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 10000;          // case bug, 开太大超时
int ans[MAXN][300];              // case6, 7 开太大超时, 开太小段错误
int a[MAXN];

bool cmp(int a, int b) {
  return a >= b;
}

int main() {
  int N; scanf("%d", &N);
  for (int i = 0; i < N; i++) { scanf("%d", &a[i]); }

  int m = 1, n, min_m = m, d;
  while (m <= N) {                              // debug, m能取到N
    if (N % m == 0 && m >= N/m) {
      n = N / m;     int min_n = N / min_m;
      d = m - n;     int min_d = min_m - min_n;
      if (d < min_d || min_d < 0) min_m = m;    // debug, case2, 1 1
    }
    m++;
  }
  m = min_m; n = N / m;

  sort(a, a+N, cmp);   // bug2, 忘记cmp

  int k, flag = 0;
  int right_n = n, down_m = m, left_n = -1, up_m = -1;   // bug4
  int i = 0, j = 0;
  ans[0][0] = a[0]; k = 1;
  while (k < N) {
    if (flag == 0) {
      if (++j == right_n) {
        j--; up_m++; flag = 1; continue;
      }
    } else if (flag == 1) {
      if (++i == down_m) {
        i--; right_n--; flag = 2; continue;
      }
    } else if (flag == 2) {
      if (--j == left_n) {
        j++; down_m--; flag = 3; continue;
      }
    } else if (flag == 3) {
      if (--i == up_m) {
        i++; left_n++; flag = 0; continue;
      }
    }
    ans[i][j] = a[k++];
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (j) printf(" ");
      printf("%d", ans[i][j]);   // bug, 并不需要两位
    }
    printf("\n");
  }

  return 0;
}
```

    
### 1059 C语言竞赛（20 point(s)）

C 语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：

0、冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
1、排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
2、其他人将得到巧克力。
给定比赛的最终排名以及一系列参赛者的 ID，你要给出这些参赛者应该获得的奖品。

#### 输入格式：

输入第一行给出一个正整数 N（≤10^4),是参赛者人数。随后 N 行给出最终排名，每行按排名顺序给出一位参赛者的 ID（4 位数字组成）。接下来给出一个正整数 K 以及 K 个需要查询的 ID。

#### 输出格式：

对每个要查询的 ID，在一行中输出 ID: 奖品，其中奖品或者是 Mystery Award（神秘大奖）、或者是 Minion（小黄人）、或者是 Chocolate（巧克力）。如果所查 ID 根本不在排名里，打印 Are you kidding?（耍我呢？）。如果该 ID 已经查过了（即奖品已经领过了），打印 ID: Checked（不能多吃多占）。

#### 输入样例：

6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222

#### 输出样例：

8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?

#### Solution:

建三张Hash表, award的key值是编号id, 对应的value是奖品类型的索引, 0, 1, 2; ans用于存放奖品对应的字符串; check以id编号作为key, 可以确定是否奖品被用过。

坑点:
1, 查找时用的索引不是i, 是Hash表key值, 也就是编号id, 刚开始伪代码里写没写清楚
2, 排名从1开始, 索引从0开始, i+1, 老是忘记.
3,4 判断素数刚开始写错, 改了改, 循环外判断1, 循环内从2开始判断, i<=floor(sqrt(v) + 0.5)
 

```cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const int MAXN = 10050;
int check[MAXN];
int award[MAXN];
vector<string> ans = {"Mystery Award", "Minion", "Chocolate"};

int is_prime(int v) {
  int st = floor(sqrt(v) + 0.5);
  if (v == 1) return 0;
  // for (int i = 3; i <= st; i++) {    // bug4
  for (int i = 2; i <= st; i++) {
    // if (v % 2 == 0) return 0;        // bug3
    if (v % i == 0) return 0;
  }
  return 1;
}


int main() {
  int N; cin >> N;
  memset(check, 0, sizeof(check));
  memset(award, -1, sizeof(award));

  string id_s; int id;
  for (int i = 0; i < N; i++) {
    cin >> id_s; id = stoi(id_s);
    if (!i) {
      award[id] = 0;
    } else {
      award[id] = (is_prime(i+1)) ? 1 : 2;    // bug2, 排名为素数
    }
  }

  int K; cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> id_s; id = stoi(id_s);
    cout << id_s << ": ";
    if (award[id] != -1) {     // bug, award[i]
      if (!check[id]) {
        cout << ans[award[id]] << endl;
        check[id] = 1;
      } else {
        cout << "Checked\n";
      }
    } else {
      cout << "Are you kidding?\n";
    }
  }
  return 0;
}
```



### 1060 爱丁顿数（25 point(s)）

英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数” E ，即满足有 E 天骑车超过 E 英里的最大整数 E。据说爱丁顿自己的 E 等于87。

现给定某人 N 天的骑车距离，请你算出对应的爱丁顿数 E（≤N）。

#### 输入格式：

输入第一行给出一个正整数 N (≤10^5)，即连续骑车的天数；第二行给出 N 个非负整数，代表每天的骑车距离。

#### 输出格式：
在一行中给出 N 天的爱丁顿数。

#### 输入样例：
10
6 7 6 9 3 10 8 2 7 8

#### 输出样例：
6

#### Solution:

刚开始的思路是从天数为1开始往后遍历, 记录里程数比超过天数的次数cnt, 在判断次数是否达到天数, 且天数比记录的最大天数大。

但是这个思路写出来的代码, case4超时.

<span style="color:red">改下思路, 从天数最大N-1+1向下找, 一旦找到符合条件的, 不用比较当前天数是否是最大天数, 可以直接作为爱丁顿数。</span>

这个思路无论是c++, 是c写都不会超时.

```cpp
#include <stdio.h>

int a[100050];

int main() {
  int N; scanf("%d", &N);
  for (int i = 0; i < N; i++) {scanf("%d", &a[i]);}
  int E = 0;
  for (int i = N-1; i >= 0; i--) {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if (a[j] > i+1) cnt++;
    }
    if (cnt >= i+1) { E = i+1; break;}
  }
  printf("%d\n", E);
  return 0;
}
```

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


### 1061 判断题（15 point(s)）

判断题的评判很简单，本题就要求你写个简单的程序帮助老师判题并统计学生们判断题的得分。

#### 输入格式：
输入在第一行给出两个不超过 100 的正整数 N 和 M，分别是学生人数和判断题数量。第二行给出 M 个不超过 5 的正整数，是每道题的满分值。第三行给出每道题对应的正确答案，0 代表“非”，1 代表“是”。随后 N 行，每行给出一个学生的解答。数字间均以空格分隔。

#### 输出格式：
按照输入的顺序输出每个学生的得分，每个分数占一行。

#### 输入样例：
3 6
2 1 3 3 4 5
0 0 1 0 1 1
0 1 1 0 0 1
1 0 1 0 1 0
1 1 0 0 1 1

#### 输出样例：
13
11
12

#### Solution:

答案, 分值用数组储存, 对每个学生一个记总分的变量score, 判断每个答案, 根据对应题目分值修改总分.


```cpp
#include <cstdio>

int ans[1000];
int scores[1000];

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) scanf("%d", &scores[i]);
  for (int i = 0; i < M; i++) scanf("%d", &ans[i]);

  for (int i = 0; i < N; i++) {
    int score = 0;
    for (int j = 0; j < M; j++) {
      int tmp; scanf("%d", &tmp);
      if (tmp == ans[j]) score += scores[j];
    }
    printf("%d\n", score);
  }
  return 0;
}
```


### 1078 字符串压缩与解压（20 point(s)）

文本压缩有很多种方法，这里我们只考虑最简单的一种：把由相同字符组成的一个连续的片段用这个字符和片段中含有这个字符的个数来表示。例如 ccccc 就用 5c 来表示。如果字符没有重复，就原样输出。例如 aba 压缩后仍然是 aba。

解压方法就是反过来，把形如 5c 这样的表示恢复为 ccccc。

本题需要你根据压缩或解压的要求，对给定字符串进行处理。这里我们简单地假设原始字符串是完全由英文字母和空格组成的非空字符串。

#### 输入格式：

输入第一行给出一个字符，如果是 C 就表示下面的字符串需要被压缩；如果是 D 就表示下面的字符串需要被解压。第二行给出需要被压缩或解压的不超过 1000 个字符的字符串，以回车结尾。题目保证字符重复个数在整型范围内，且输出文件不超过 1MB。

#### 输出格式：

根据要求压缩或解压字符串，并在一行中输出结果。

#### 输入样例 1：
C
TTTTThhiiiis isssss a   tesssst CAaaa as

#### 输出样例 1：

5T2h4is i5s a3 te4st CA3a as
输入样例 2：

D
5T2h4is i5s a3 te4st CA3a as10Z

#### 输出样例 2：
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ

#### Solution:
tags: 字符串, two pointers, 栈

<span style="color:red">双指针的解法:</span>
每次读入一个操作符后, 读入一整行,
如果是C压缩, 如果s[i]==s[i+1], 计数器+1, 否则的话, 就根据计数器进行一次输出.
如果是D解压缩, 用指针i扫描字符串。如果i对应的是数字的话, 用一个临时j指针, 从i+1开始扫描, 直到j对应的不为数字为止, "数字"字符串转成数字, 作为打印的次数, 打印数字后跟着的字符; 如果i对应的是字符的话, 可以直接打印输出.

坑点, 
1, 上述压缩方法中, 需要在字符串末尾添加一个'0', 用来使得遍历整个字符串不会出错
2, j扫描完数字之后, i需要移动到下一组, （数字+字符）or （字符）, 而不是次数字后面跟着的字符, 如果是这样, 下一次进入循环时, 判断出这是一个字符, 就会打印这个字符. 导致case1, 5;

<span style="color:red">栈的解法:</span>
对于C压缩来说, 将每个读入的字符, 判断是否和栈顶元素相同, 若不同, "清空"一次栈, 打印当前栈大小的次的栈顶字符, 也就是压缩之前的字符串,; 否则若字符与栈顶元素相同, 压入栈。
对于D解压缩来说, 每次读入一个字符, 如果是数字push; 如果是字母, 获得栈内数字后清空栈, 打印计算得到的次数的栈顶字符, 


坑点:
1, 对于压缩来说, 最后组字符串的压缩还需要后一个字符来判断, 这里我利用读到的"\n"进行区分判断.
2, 对于解压缩来说, 注意字符情况下又是空栈, 说明只有ch单个字母, 直接putchar()

<span style="color:red">还考虑了将栈换成队列的版本, 但队列在字符转换成数字时候, 虽然是顺序输出, 但需要用stoi进行转换, 这个算量我不太清楚; 但是对栈的版本, 可以从个位数x1开始, 十位数x10, 很自然的计算上去, 因此还是选择用栈合理.</span>


two pointer版本:
```cpp
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
  char op; scanf("%c", &op);
  string s;
  getchar();
  if (op == 'C') {
    getline(cin, s); s += '0';
    int N = s.length()-1;
    int i = 0, cnt = 1;
    while (i < N) {
      if (s[i] == s[i+1]) {
        cnt++;
      } else  {
        if (cnt == 1) {
          printf("%c", s[i]);
        } else {
          printf("%d%c", cnt, s[i]); cnt = 1;
        }
      }
      i++;
    }
  } else if (op == 'D') {
    getline(cin, s);
    int N = s.length();
    int i = 0;
    while (i < N) {
      if (isdigit(s[i])) {
        int j = i+1;
        while (j < N && isdigit(s[j])) j++;
        int n = stoi(s.substr(i, j));
        for (int k = 0; k < n; k++) {
          printf("%c", s[j]);
        }
        i = j+1;                   // case1, 5
      } else {
        printf("%c", s[i]); i++;
      }
    }
  }
  printf("\n");
  return 0;
}
```

栈版本:
```cpp
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

int main() {
  char op; cin >> op;
  stack<char> s; char ch;
  getchar();
  if (op == 'C') {
    while (scanf("%c", &ch) != EOF) {
      if (s.empty() || s.top() == ch) {
        s.push(ch);
      } else {
        int cnt = s.size(); char old_ch = s.top();
        while (!s.empty()) s.pop();
        s.push(ch);

        if (cnt != 1) printf("%d", cnt);    // optimisize
        printf("%c", old_ch);
      }
    }
  } else if (op == 'D') {
    while (scanf("%c", &ch) != EOF && ch != '\n' && ch != '\r') {
      if (isdigit(ch)) {
        s.push(ch);
      } else {
        if (s.empty()) {
          putchar(ch);
        } else {
          int n = 0, b = 1;
          while (!s.empty()) {
            n += b * (s.top()-'0');
            s.pop();
            b *= 10;
          }
          while (n--) putchar(ch);
        }
      }
    }
  }
  printf("\n");
  return 0;
}
```


### 1019 数字黑洞 (20)（20 point(s)）

给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089\ 9810 - 0189 = 9621\ 9621 - 1269 = 8352\ 8532 - 2358 = 6174\ 7641 - 1467 = 6174\ ... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

#### 输入格式：

输入给出一个(0, 10000)区间内的正整数N。

#### 输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

#### 输入样例1：
6767

#### 输出样例1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174

#### 输入样例2：
2222

#### 输出样例2：

2222 - 2222 = 0000

#### Solution:

老方法是自己实现了字符串转整数, 整数转字符串的函数,
新方法是用现有的函数库, stoi和to_string, 进行上述转换, 再用s.insert(0, 4-s.length(), '0');

学到新技巧, s.insert(插入第一位置, 重复的次数, 字符串)

坑点:
1, 0~999前面需要+1
2, 9998 - 8999 = 0999, 而不是999

stoi和to_string版本
```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp_down(char a, char b) return a > b;
bool cmp_up(char a, char b) return a < b;
int main() {
  int v, v1, v2; string s;
  cin >> s;
  int ok = 0; char first = s[0];
  for (int i = 1; i < 4; i++) {
    if (s[i] != s[0]) { ok = 1; break;}
  }
  if (!ok) {
    cout << s << " - " << s << " = 0000" << endl;
  } else {
    s.insert(0, 4-s.length(), '0');
    do {
      sort(s.begin(), s.end(), cmp_down);
      v1 = stoi(s);
      sort(s.begin(), s.end(), cmp_up);
      v2 = stoi(s);
      v = v1 - v2;
      s = to_string(v);
      s.insert(0, 4-s.length(), '0');
      printf("%04d - %04d = %04d\n", v1, v2, v);
    } while (s != "6174");
  }
  return 0;
}
```

原先的方法:
```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp_str1(const char a, const char b) { return a >= b;}

bool cmp_str2(const char a, const char b) { return a <= b;}


int convert_int(string s) {
  // 从(末尾*10+前一位)*10
  int i = 1, ans = 0;
  for (string::iterator p = s.end()-1; p >= s.begin(); p--) {
    ans += (*p - '0') * i;
    i *= 10;
  }
  // cout << ans << "\n";
  return ans;
}

string convert_str(int h) {
  // 转成4位字符串,
  string ans_s(4, '0');
  int i = 3;
  while (h) {
    ans_s[i--] = h % 10 + '0';
    h /= 10;
  }
  return ans_s;
}

int main() {
  string s1;
  cin >> s1;
  s1 = convert_str(convert_int(s1));   // debug: 0~999需要处理
  string s2 = s1;
  sort(s1.begin(), s1.end(), cmp_str1);
  sort(s2.begin(), s2.end(), cmp_str2);
  if (s1 == s2) {
    cout << s1 << " - " << s1 << " = 0000" << "\n"; return 0;
  }
  while (s1 != "6174") {
    s2 = s1;
    sort(s1.begin(), s1.end(), cmp_str1);
    sort(s2.begin(), s2.end(), cmp_str2);
    int d = convert_int(s1) - convert_int(s2);
    string tmp = convert_str(d);               // debug:按照四位格式输出
    cout << s1 << " - " << s2 << " = " << tmp << "\n";
    s1 = tmp;
  }

  return 0;
}
```


### 1023 组个最小数（20 point(s)）

给定数字 0-9 各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意 0 不能做首位）。例如：给定两个 0，两个 1，三个 5，一个 8，我们得到的最小的数就是 10015558。

现给定数字，请编写程序输出能够组成的最小的数。

#### 输入格式：
输入在一行中给出 10 个非负整数，顺序表示我们拥有数字 0、数字 1、……数字 9 的个数。整数间用一个空格分隔。10 个数字的总个数不超过 50，且至少拥有 1 个非 0 的数字。

#### 输出格式：
在一行中输出能够组成的最小的数。

#### 输入样例：
2 2 0 0 0 3 0 0 1 0

#### 输出样例：
10015558

#### Solution:

贪心, 要让整个数小, 就是数越小就排在越前面。
观察数列的构造,

"排序"后的数组,

00115558
10015558

<span style="color:red">0不能作为数的首位, 也就是说拿一个0以外的最小值放在最前面.</span>

12345566
12345566

直接输出


坑点:
1, 因为给出的每个位置的个数是从0~9的, 字符串本身排列是顺序的, 不需要sort.
2, 用字符串表示一个整数, 选择一个位置的数字时, 注意它是字符.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  for (int i = 0; i < 10; i++) {
    int cnt; cin >> cnt;
    for (int j = 0; j < cnt; j++) s += (i + '0');
  }

  if (s[0] == '0') {
    int i = 1;
    while (i < s.length() && s[i] == '0') i++;
    char tmp = s[0]; s[0] = s[i]; s[i] = tmp;
  }
  cout << s << endl;
  return 0;
}
```


在寻找第一个非0的数字索引的时候, 不需要遍历, 记录有几个0就可以了。
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; int first;
  for (int i = 0; i < 10; i++) {
    int cnt; cin >> cnt;
    if (!i) first = cnt;
    for (int j = 0; j < cnt; j++) s += (i + '0');
  }

  if (s[0] == '0') {
    char tmp = s[0]; s[0] = s[first]; s[first] = tmp;
  }
  cout << s << endl;
  return 0;
}
```

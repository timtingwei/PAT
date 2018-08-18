## Basic-PAT-C++

### 1077 互评成绩计算（20 point(s)）


在浙大的计算机专业课中，经常有互评分组报告这个环节。一个组上台介绍自己的工作，其他组在台下为其表现评分。最后这个组的互评成绩是这样计算的：所有其他组的评分中，去掉一个最高分和一个最低分，剩下的分数取平均分记为 G1老师给这个组的评分记为 G2。该组得分为 (G1+G2)/2，最后结果四舍五入后保留整数分。本题就要求你写个程序帮助老师计算每个组的互评成绩。

#### 输入格式：
输入第一行给出两个正整数 N（> 3）和 M，分别是分组数和满分，均不超过 100。随后 N 行，每行给出该组得到的 N 个分数（均保证为整型范围内的整数），其中第 1 个是老师给出的评分，后面 N−1 个是其他组给的评分。合法的输入应该是 [0,M] 区间内的整数，若不在合法区间内，则该分数须被忽略。题目保证老师的评分都是合法的，并且每个组至少会有 3 个来自同学的合法评分。

#### 输出格式：
为每个组输出其最终得分。每个得分占一行。

#### 输入样例：
6 50
42 49 49 35 38 41
36 51 50 28 -1 30
40 36 41 33 47 49
30 250 -25 27 45 31
48 0 0 50 50 1234
43 41 36 29 42 29

#### 输出样例：
42
33
41
31
37
39

#### Solution:

读入一个学生分数, 不合法的continue, 合法的放入vector, 对vector排序后, 取[1, size-1)下标对应的值.

坑点:
1, 有N个组, 计算每组分数外层循环N次, 内层循环N-1次.
2, 四舍五入用 floor(a + 0.5);
3, 定义double类型时, 要给初始值(刚开始错了)

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    int aveg; double g1, g2, tmp;
    cin >> g2;
    vector<double> scores;
    for (int j = 0; j < N-1; j++) {
      cin >> tmp;
      if (tmp < 0 || tmp > M) continue;
      scores.push_back(tmp);
    }
    sort(scores.begin(), scores.end());
    for (int j = 1; j < scores.size() - 1; j++) { g1 += scores[j];}
    g1 = g1/(scores.size()-2);
    aveg = floor((g1+g2)/2 + 0.5);
    cout << aveg << endl;
  }
  return 0;
}
```

### 1045 快速排序（25 point(s)）

著名的快速排序算法里有一个经典的划分过程：我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 给定划分后的 N 个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？

例如给定 $N = 5$, 排列是1、3、2、4、5。则：

1 的左边没有元素，右边的元素都比它大，所以它可能是主元；
尽管 3 的左边元素都比它小，但其右边的 2 比它小，所以它不能是主元；
尽管 2 的右边元素都比它大，但其左边的 3 比它大，所以它不能是主元；
类似原因，4 和 5 都可能是主元。
因此，有 3 个元素可能是主元。

#### 输入格式：

输入在第 1 行中给出一个正整数 N（≤10^5​​); 第 2 行是空格分隔的 N 个不同的正整数，每个数不超过 10^9​​。

#### 输出格式：

在第 1 行中输出有可能是主元的元素个数；在第 2 行中按递增顺序输出这些元素，其间以 1 个空格分隔，行首尾不得有多余空格。

#### 输入样例：
5
1 3 2 4 5

#### 输出样例：
3
1 4 5

#### Solution:

这道题不错, 原以为很简单, 不像是25分的题目, 就开始盲目做了。
思路1: 用p扫描数组的同时, 用i = p-1; j =  p+1;分别向前和向后扫描, 结果5分钟写完, 1, 3超时,
思路2: 观察数组排序后的特性, 主元是对应i的位置两个元素相等的元素. 但还有一个条件, 比如 1 1 1, 主元应该只有1; 再例如, 6 2 4 3 1, 排序后是 1 2 3 4 6, 2不是主元, 因此除了相等外, 还需要原数列该位置的数左边均小于这个数。



坑点：
1, 即使这样的思路下, 如果用遍历检查当前位置之前的元素 是否 均小于这个元素, 那么同样会超时, 因此只用一个max量来记录每次操作的元素是否是整个操作的最大值, 只通过max来确定条件2

思路2, max代替条件2的正确代码
```cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, tmp;
  scanf("%d", &N);
  vector<int> v;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    v.push_back(tmp);
  }

  vector<int> ans;
  vector<int> tmp_v = v;
  sort(v.begin(), v.end());
  int max_i = 0;
  for (int i = 0; i < N; i++) {
    if (tmp_v[i] > tmp_v[max_i]) max_i = i;
    if (tmp_v[i] == v[i] && max_i == i) ans.push_back(tmp_v[i]);
  }

  printf("%lu\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
```

另外附上思路1: 超时的代码
```cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, tmp;
  scanf("%d", &N);
  vector<int> v;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    v.push_back(tmp);
  }

  vector<int> ans;
  for (int p = 0; p < N; p++) {
    int i = p-1, j = p+1;
    while (i >= 0 && v[i] <= v[p]) i--;
    while (j < N && v[j] > v[p]) j++;
    if (i == -1 && j == N) {
      ans.push_back(v[p]);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%lu\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
```

### 1080 MOOC期终成绩（25 point(s)）

对于在中国大学MOOC（http://www.icourse163.org/ ）学习“数据结构”课程的学生，想要获得一张合格证书，必须首先获得不少于200分的在线编程作业分，然后总评获得不少于60分（满分100）。总评成绩的计算公式为 G=(G​mid−term×40%+G final×60%)，如果 Gmid−term>Gfinal；否则总评 G 就是 G​final。这里 Gmid−term和 Gfinal分别为学生的期中和期末成绩。

现在的问题是，每次考试都产生一张独立的成绩单。本题就请你编写程序，把不同的成绩单合为一张。

#### 输入格式：

输入在第一行给出3个整数，分别是 P（做了在线编程作业的学生数）、M（参加了期中考试的学生数）、N（参加了期末考试的学生数）。每个数都不超过10000。

接下来有三块输入。第一块包含 P 个在线编程成绩 Gp
​​ ；第二块包含 M 个期中考试成绩 G​mid−term
​​ ；第三块包含 N 个期末考试成绩 G​final
​​ 。每个成绩占一行，格式为：学生学号 分数。其中学生学号为不超过20个字符的英文字母和数字；分数是非负整数（编程总分最高为900分，期中和期末的最高分为100分）。

#### 输出格式：

打印出获得合格证书的学生名单。每个学生占一行，格式为：

学生学号 G​p G​mid−term G​final G

如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“−1”。输出顺序为按照总评分数（四舍五入精确到整数）递减。若有并列，则按学号递增。题目保证学号没有重复，且至少存在1个合格的学生。

#### 输入样例：

6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
#### 输出样例：

missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84

#### Solution:

读取每个学生信息放在一个Node中, Node放入以学生姓名为键值的Map。
符合合格的学生一个vector容器, 容器按要求进行排序.

坑点:
> * 将成绩初始化为-1, 用于计算时, 转换成0, 用于打印时, 转换成-1


```cpp
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
  string id;
  int p = -1;
  int mid = -1;
  int final = -1;
  int total = -1;
};
vector<Node> v;

bool cmp(Node n1, Node n2) {
  if (n1.total != n2.total) return n1.total > n2.total;
  return n1.id <= n2.id;
}

int main() {
  int P, M, N;
  cin >> P >> M >> N;
  map<string, Node> mp;
  string tmp_id; int tmp_p, tmp_mid, tmp_final;
  while (P--) {
    cin >> tmp_id >> tmp_p;
    mp[tmp_id].id = tmp_id;
    mp[tmp_id].p = tmp_p;
  }
  while (M--) {
    cin >> tmp_id >> tmp_mid;
    mp[tmp_id].id = tmp_id;
    mp[tmp_id].mid = tmp_mid;
  }
  while (N--) {
    cin >> tmp_id >> tmp_final;
    mp[tmp_id].id = tmp_id;
    mp[tmp_id].final = tmp_final;
  }

  for (auto it = mp.begin(); it != mp.end(); it++) {
    // cout << it->second.id << endl;
    tmp_p = (it->second.p == -1) ? 0 : it->second.p;
    tmp_mid = (it->second.mid == -1) ? 0 : it->second.mid;
    tmp_final = (it->second.final == -1) ? 0 : it->second.final;

    if (tmp_p >= 200) {
      int total = (tmp_mid > tmp_final) ?
          floor((tmp_mid * 0.4 + tmp_final * 0.6) + 0.5) : tmp_final;
      it->second.total = total;
      if (it->second.mid == -1 && it->second.final == -1) it->second.total = -1;
      if (total >= 60) {
        v.push_back(it->second);
      }
    }
  }

  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].id << " " << v[i].p << " " << v[i].mid
         << " " << v[i].final << " " << v[i].total << endl;
  }

  return 0;
}
```

### 1046 划拳（15 point(s)）

划拳是古老中国酒文化的一个有趣的组成部分。酒桌上两人划拳的方法为：每人口中喊出一个数字，同时用手比划出一个数字。如果谁比划出的数字正好等于两人喊出的数字之和，谁就赢了，输家罚一杯酒。两人同赢或两人同输则继续下一轮，直到唯一的赢家出现。

下面给出甲、乙两人的划拳记录，请你统计他们最后分别喝了多少杯酒。

#### 输入格式：
输入第一行先给出一个正整数 N（≤100），随后 N 行，每行给出一轮划拳的记录，格式为：

甲喊 甲划 乙喊 乙划
其中喊是喊出的数字，划是划出的数字，均为不超过 100 的正整数（两只手一起划）。

#### 输出格式：
在一行中先后输出甲、乙两人喝酒的杯数，其间以一个空格分隔。

#### 输入样例：
5
8 10 9 12
5 10 5 10
3 8 5 12
12 18 1 13
4 16 12 15

#### 输出样例：
1 2

#### Solution:

简单题目, 花费了一点时间。
两个坑点:
1, 四个变量的顺序搞错, a, jia, b, yi
2, 在用C写的时候, scanf("%d %d %d %d\n", &jia, &a, &yi, &b); 导致多读, 循环不结束.

```cpp
#include <iostream>
using namespace std;
int main() {
  int N; cin >> N;
  int cnt_a = 0, cnt_b = 0;
  while (N--) {
    int a, jia, b, yi;
    cin >> a >> jia >> b >> yi;
    if (jia == a+b && yi != a+b) {
      cnt_b++;
    } else if (jia != a+b && yi == a+b) {
      cnt_a++;
    }
  }
  cout << cnt_a << " " << cnt_b << endl;
  return 0;
}
```

### 1012 数字分类 (20)（20 point(s)）

给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；

A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；

A3 = 被5除后余2的数字的个数；

A4 = 被5除后余3的数字的平均数，精确到小数点后1位；

A5 = 被5除后余4的数字中最大数字。

#### 输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

#### 输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

#### 输入样例1：

13 1 2 3 4 5 6 7 8 9 10 20 16 18
#### 输出样例1：

30 11 2 9.7 9
#### 输入样例2：

8 1 2 4 5 6 7 9 16
#### 输出样例2：

N 11 2 N 9

#### Solution

对15天前的方式进行了改进.

用exist数组解决不存在N问题, 所有答案存储在一个int数组中, 除了double以外。
循环5次打印, 分成存在和不存在, 存在分成保留一位小数平均数和其他整数.

思路正确无坑点， 一次通过, 用hash表记得include cstring.

```cpp
#include <cstring>
#include <cstdio>

int exist[6];
int ans[6];
double ans_3;

int main() {
  int N; scanf("%d", &N);
  memset(exist, 0, sizeof(exist));
  memset(ans, 0, sizeof(ans));
  int cnt = 0, flag = 1;
  for (int i = 0; i < N; i++) {
    int tmp; scanf("%d", &tmp);
    if (tmp % 5 == 0 && tmp % 2 == 0) {
      ans[0] += tmp; exist[0] = 1;
    }
    if (tmp % 5 == 1) {
      ans[1] += tmp * flag; exist[1] = 1;
      flag *= -1;
    }
    if (tmp % 5 == 2) {
      ans[2]++; exist[2] = 1;
    }
    if (tmp % 5 == 3) {
      ans_3 += tmp; cnt++; exist[3] = 1;
    }
    if (tmp % 5 == 4 && tmp > ans[4]) {
      ans[4] = tmp; exist[4] = 1;
    }
  }

  for (int i = 0; i < 5; i++) {
    if (i) printf(" ");
    if (exist[i]) {
      if (i != 3) printf("%d", ans[i]);
      else printf("%.1f", ans_3 / cnt);
    } else {
      printf("N");
    }
  }
  printf("\n");

  return 0;
}
```


十五天前的版本
```cpp
#include <cstdio>
#include <cstring>
#include <iostream>
int const MAXN = 10000000;
int a[MAXN];
int main() {
  int n;
  if (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) { scanf("%d", &a[i]);}
    int a1 = 0, a2 = 0, a3 = 0, a5 = -1;
    double a4 = 0.0;
    int flag = 1, a2_n = 0, a4_n = 0;  // A2 6 6的情况也为0
    for (int i = 0; i < n; i++) {
      if ((a[i] % 5 == 0) && (a[i] % 2 == 0)) a1 += a[i];
      if (a[i] % 5 == 1) {
        a2 += (flag * a[i]);
        flag *= -1;
        a2_n++;
      }
      if (a[i] % 5 == 2) a3++;
      if (a[i] % 5 == 3) { a4 += a[i]; a4_n++;}
      if (a[i] % 5 == 4 && a[i] > a5) a5 = a[i];
    }

    if (a1 != 0) {
      printf("%d", a1);
    } else {
      printf("N");
    }

    if (a2_n != 0) {
      printf(" %d", a2);
    } else {
      printf(" N");
    }

    if (a3 != 0) {
      printf(" %d", a3);
    } else {
      printf(" N");
    }

    if (a4_n != 0) {
      a4 /= a4_n;
      printf(" %.1f", a4);
    } else {
      printf(" N");
    }

    if (a5 != -1) {
      printf(" %d", a5);
    } else {
      printf(" N");
    }

    printf("\n");
  }
  return 0;
}
```

### 1036 跟奥巴马一起编程(15)（15 point(s)）

美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。2014年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。现在你也跟他一起画吧！

#### 输入格式：

输入在一行中给出正方形边长N（3<=N<=20）和组成正方形边的某种字符C，间隔一个空格。

#### 输出格式：

输出由给定字符C画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，我们输出的行数实际上是列数的50%（四舍五入取整）。

#### 输入样例：
10 a

#### 输出样例：
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa

#### Solution:

可能有更简单的。。

附上, [灵魂画手 milo yip - 如何用 C 语言画小猪佩奇](https://zhuanlan.zhihu.com/p/37031514)

```cpp
#include <cstdio>
#include <cmath>

int main() {
  int N; char c;
  scanf("%d %c", &N, &c);
  int M = floor((double)N / 2 + 0.5);
  for (int i = 0; i < N; i++) printf("%c", c);
  printf("\n");
  for (int i = 0; i < M - 2; i++) {
    printf("%c", c);
    for (int j = 1; j < N-1; j++) printf(" ");
    printf("%c", c);
    printf("\n");
  }
  for (int i = 0; i < N; i++) printf("%c", c);
  printf("\n");
  return 0;
}
```

### 1041 考试座位号（15 point(s)）

每个 PAT 考生在参加考试时都会被分配两个座位号，一个是试机座位，一个是考试座位。正常情况下，考生在入场时先得到试机座位号码，入座进入试机状态后，系统会显示该考生的考试座位号码，考试时考生需要换到考试座位就座。但有些考生迟到了，试机已经结束，他们只能拿着领到的试机座位号码求助于你，从后台查出他们的考试座位号码。

#### 输入格式：

输入第一行给出一个正整数 N（≤1000），随后 N 行，每行给出一个考生的信息：准考证号 试机座位号 考试座位号。其中准考证号由 14 位数字组成，座位从 1 到 N 编号。输入保证每个人的准考证号都不同，并且任何时候都不会把两个人分配到同一个座位上。

考生信息之后，给出一个正整数 M（≤N），随后一行中给出 M 个待查询的试机座位号码，以空格分隔。

#### 输出格式：

对应每个需要查询的试机座位号码，在一行中输出对应考生的准考证号和考试座位号码，中间用 1 个空格分隔。

#### 输入样例：
4
10120150912233 2 4
10120150912119 4 1
10120150912126 1 3
10120150912002 3 2
2
3 4

#### 输出样例：

10120150912002 2
10120150912119 1

#### Solution:

将一个考生的三个数据信息存储在一个Node结构中, 以机考座位号建立哈希表, 查找时可通过该表O(1)时间内找到对应Node, 输入该Node信息.

bug:
`主要struct花括号后的;`


```cpp
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Node {
  string id;
  int ji;
  int kao;
};  // bug

Node a[2000];

int main() {
  int N; cin >> N;
  memset(a, 0, sizeof(a));

  for (int i = 0; i < N; i++) {
    Node node;
    cin >> node.id >> node.ji >> node.kao;
    a[node.ji] = node;
  }

  int M; cin >> M;
  while (M--) {
    int ji; cin >> ji;
    cout << a[ji].id << " " << a[ji].kao << endl;
  }

  return 0;
}
```


### 1037 在霍格沃茨找零钱（20 point(s)）

如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。

#### 输入格式：

输入在 1 行中分别给出 P 和 A，格式为 Galleon.Sickle.Knut，其间用 1 个空格分隔。这里 Galleon 是 [0, 10
​7] 区间内的整数，Sickle 是 [0, 17) 区间内的整数，Knut 是 [0, 29) 区间内的整数。

#### 输出格式：
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

#### 输入样例 1：

10.16.27 14.1.28

#### 输出样例 1：
3.2.1

#### 输入样例 2：
14.1.28 10.16.27

#### 输出样例 2：
-3.2.1

#### Solution:

将所有的币转换成Knut来计算, 最后用总的币除以17*29取整得到Galleon, 剩余部分除以29得到Sickle, 剩余部分就是Knut.

sscanf读取字符数组, 分割成不同的int, 求P, A; 用一个flag标正负, 在输入时计算.

bug1:
注意四则运算的顺序, 我自己在做的时候, 把` gg = delta / (17*29);`写了成`gg = delta / 17*29;`


```cpp
#include <cstdio>

char str_p[100];
char str_a[100];

int main() {
  scanf("%s %s", str_p, str_a);
  int g, s, k;
  sscanf(str_p, "%d.%d.%d", &g, &s, &k);
  int P = 17*29*g + 29*s + k;
  sscanf(str_a, "%d.%d.%d", &g, &s, &k);
  int A = 17*29*g + 29*s + k;

  int delta = A-P, flag;
  if (delta >= 0) {
    flag = 1;
  } else {
    flag = -1; delta *= -1;
  }

  int gg, ss, kk;
  gg = delta / (17*29); delta -= 17*29*gg;     // bug1
  ss = delta / 29;      delta -= 29*ss;
  kk = delta;
  printf("%d.%d.%d\n", flag*gg, ss, kk);

  return 0;
}
```

### 1057 数零壹（20 point(s)）

给定一串长度不超过10^​5的字符串，本题要求你将其中所有英文字母的序号（字母 a-z 对应序号 1-26，不分大小写）相加，得到整数 N，然后再分析一下 N 的二进制表示中有多少 0、多少 1。例如给定字符串 PAT (Basic)，其字母序号之和为：16+1+20+2+1+19+9+3=71，而 71 的二进制是 1000111，即有 3 个 0、4 个 1。

#### 输入格式：

输入在一行中给出长度不超过 10^5、以回车结束的字符串。

#### 输出格式：

在一行中先后输出 0 的个数和 1 的个数，其间以空格分隔。

#### 输入样例：

PAT (Basic)

#### 输出样例：
3 4

#### Solution:

字符串中只将英文的序号相加, 得到数N后不断mod 2, 自身除以2, 直到N为0为止, 在这个过程中记录各个位数中01个数.

总结下二进制转换的代码
```cpp
int n;
while (n) {
  v[cnt++] = n % 2;    // 二进制各个位数, 从右往左
  n /= 2
}
```

坑点:
> * 1, 做的时候太粗心, 忘记忽略非字母的情况
> * 2, 字符a是从1开始记, 因此需要将相减后的结果+1
> * 3, N的初始值没赋值成0, 导致所有case通不过, 低级错误


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; getline(cin, s);
  int N = 0;  // bug3
  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i])) {     // bug1
      N += tolower(s[i]) - 'a' + 1;    // bug2
    }
  }
  int zero = 0, one = 0;
  while (N) {
    cout << N % 2 << endl;
    if (N%2) one++;
    else zero++;
    N /= 2;
  }
  cout << zero << " " << one << endl;
  return 0;
}
```

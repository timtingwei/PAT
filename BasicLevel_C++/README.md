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

### 1022 D进制的A+B (20)（20 point(s)）

输入两个非负10进制整数A和B(<=2^30^-1)，输出A+B的D (1 < D <= 10)进制数。

#### 输入格式：

输入在一行中依次给出3个整数A、B和D。

#### 输出格式：

输出A+B的D进制数。

#### 输入样例：
123 456 8

#### 输出样例：
1103

#### Solution:

两数相加计算出的值不断取余数, 除以D, 算出的数进栈, 打印时利用栈的FILO特性 按照二进制数顺序打印。

<span style="color:red">坑点1:</span>
刚开始觉得两个整数相加可能会溢出, 但是实验之后
```cpp
int v = pow(2, 30);
printf("%d\n", 2*v);    // 数值正常不会溢出
```

int整数的范围在,` -2^31 ～ +(2^31 -1)` ,` -2 * 10^9 ~ 2 * 10^9`之内, 因此不会溢出

<span style="color:red">坑点2:</span>
当总和为0时, 无论什么进制都打印出0.


```cpp
#include <iostream>
#include <stack>
using namespace std;
int main() {
  int a, b, d; cin >> a >> b >> d;
  int total = a + b;
  if (total != 0) {
    stack<int> s;
    while (total) {
      s.push(total % d);
      total /= d;
    }
    while (!s.empty()) {
      printf("%d", s.top());
      s.pop();
    }
  } else { printf("0"); }
  printf("\n");

  return 0;
}
```


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

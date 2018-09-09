## Basic-PAT-C++

### 1020 -u

```cpp
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct food {
  double scale, each_scale;
  double cnt;
};

struct cmp {
  bool operator() (const food &f1, const food &f2) {
    return f1.each_scale < f2.each_scale;
  }
};

bool db_equal(const double d1, const double d2) {
  return -0.0005 < d1-d2 && d1-d2 < 0.00005;
}

int main() {
  int N;
  double need; scanf("%d %lf", &N, &need);
  vector<food> v(N);
  priority_queue<food, vector<food>, cmp> q;
  for (int i = 0; i < N; i++) {
    scanf("%lf", &v[i].cnt);
  }
  for (int i = 0; i < N; i++) {
    scanf("%lf", &v[i].scale);
    v[i].each_scale = v[i].scale / v[i].cnt;
    q.push(v[i]);
  }
  double profit = 0.0;
  while (!db_equal(need, 0.0) && !q.empty()) {
    if (q.top().cnt > need) {
      profit += q.top().each_scale * need;
      need = 0;
    } else {  // <= need
      profit += q.top().scale;
      need -= q.top().cnt;
      q.pop();
    }
    if (q.empty()) break;
  }
  printf("%.2lf", profit);
  return 0;
}
```


### 1090 危险品装箱(25) -u
[PAT, 算法, map]
集装箱运输货物时，我们必须特别小心，不能把不相容的货物装在一只箱子里。比如氧化剂绝对不能跟易燃液体同箱，否则很容易造成爆炸。

本题给定一张不相容物品的清单，需要你检查每一张集装箱货品清单，判断它们是否能装在同一只箱子里。

#### 输入格式：

输入第一行给出两个正整数：N (≤10^4) 是成对的不相容物品的对数；M (≤100) 是集装箱货品清单的单数。

随后数据分两大块给出。第一块有 N 行，每行给出一对不相容的物品。第二块有 M 行，每行给出一箱货物的清单，格式如下：
K G[1] G[2] ... G[K]
其中 K (≤1000) 是物品件数，G[i] 是物品的编号。简单起见，每件物品用一个 5 位数的编号代表。两个数字之间用空格分隔。

#### 输出格式：
对每箱货物清单，判断是否可以安全运输。如果没有不相容物品，则在一行中输出 Yes，否则输出 No。

#### 输入样例：
6 3
20001 20002
20003 20004
20005 20006
20003 20001
20005 20004
20004 20006
4 00001 20004 00002 20003
5 98823 20002 20003 20006 10010
3 12345 67890 23333

#### 输出样例：
No
Yes
Yes


#### Solution:

将每箱货物的存成hash表, 遍历每对违禁物品, 两件物品都存在这张表里就说明要爆炸, 退出遍历.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Node {
  string a, b;
};

int main() {
  int N, M; cin >> N >> M;
  vector<Node> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i].a >> v[i].b;
  }
  unordered_map<string, int> mp;
  int n; string temp;
  while (M--) {
    cin >> n; mp.clear();
    for (int i = 0; i < n; i++) {
      cin >> temp;
      mp[temp] = 1;
    }
    int ok = 1;
    for (int i = 0; i < N; i++) {
      if (mp.count(v[i].a) && mp.count(v[i].b)) {
        ok = 0; break;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
```


### 1086 就不告诉你(15) -u
[算法, PAT, 字符串, 进制转换]
做作业的时候，邻座的小盆友问你：“五乘以七等于多少？”你应该不失礼貌地围笑着告诉他：“五十三。”本题就要求你，对任何一对给定的正整数，倒着输出它们的乘积。

#### 输入格式：
输入在第一行给出两个不超过 1000 的正整数 A 和 B，其间以空格分隔。

#### 输出格式：
在一行中倒着输出 A 和 B 的乘积。

#### 输入样例：
5 7

#### 输出样例：
53

#### Solution1:
字符串反转字符串.

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int a, b; cin >> a >> b;
  string temp = to_string(a*b);
  reverse(temp.begin(), temp.end());
  cout << stoi(temp) << endl;
  return 0;
}
```


#### Solution2:

手动模拟反转计算. 比较容易出错, 不过作为练习蛮好的.

```cpp
#include <cstdio>
int main() {
  int a, b; scanf("%d %d", &a, &b);
  int n = a*b;
  int arr[10] = {0}, len = 0, t = 1;
  while (n) {
    arr[len++] = n % 10; t *= 10;
    n /= 10;
  }
  t /= 10;  // debug

  int ans = 0;
  for (int i = 0; i < len; i++) {
    ans += arr[i] * t;
    t /= 10;
  }
  printf("%d\n", ans);
  return 0;
}
```


### 1087 有多少不同的值(20) -u
[Hash散列, PAT, 算法]

当自然数 n 依次取 1、2、3、……、N 时，算式 ⌊n/2⌋+⌊n/3⌋+⌊n/5⌋ 有多少个不同的值？（注：⌊x⌋ 为取整函数，表示不超过 x 的最大自然数，即 x 的整数部分。）

#### 输入格式：
输入给出一个正整数 N（2≤N≤10^4）。

#### 输出格式：
在一行中输出题面中算式取到的不同值的个数。

#### 输入样例：
2017

#### 输出样例：
1480

#### Solution:

开表的时候要注意, 大小不是N的范围那么简单, 因为表中存的是值, 所以是运算后的范围, 可以严格证明, 但尽量开大点.
用max变量控制遍历的次数.

```cpp
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int N; scanf("%d", &N);
  int value[100050] = {0};
  int max = 0, cnt = 0;
  for (int i = 1; i <= N; i++) {
    int t = floor(i/2) + floor(i/3) + floor(i/5);
    value[t] = 1;
    max = t > max ? t : max;
  }
  
  for (int i = max; i >= 0; i--) {
    if (value[i]) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
```


### 1088 三人行(20) -u
[表达式, PAT, 算法]
子曰：“三人行，必有我师焉。择其善者而从之，其不善者而改之。”

本题给定甲、乙、丙三个人的能力值关系为：甲的能力值确定是 2 位正整数；把甲的能力值的 2 个数字调换位置就是乙的能力值；甲乙两人能力差是丙的能力值的 X 倍；乙的能力值是丙的 Y 倍。请你指出谁比你强应“从之”，谁比你弱应“改之”。

#### 输入格式：
输入在一行中给出三个数，依次为：M（你自己的能力值）、X 和 Y。三个数字均为不超过 1000 的正整数。

#### 输出格式：
在一行中首先输出甲的能力值，随后依次输出甲、乙、丙三人与你的关系：如果其比你强，输出 Cong；平等则输出 Ping；比你弱则输出 Gai。其间以 1 个空格分隔，行首尾不得有多余空格。

注意：如果解不唯一，则以甲的最大解为准进行判断；如果解不存在，则输出 No Solution。

#### 输入样例 1：
48 3 7

#### 输出样例 1：
48 Ping Cong Gai

#### 输入样例 2：
48 11 6

#### 输出样例 2：
No Solution

#### Solution:

考试的时候， 刚开始把在[10,99]这个范围给忘记了, 2个case没过。

<span style="color:red">这里的丙一定要声明成double, 不能用取余来做, 不然case4过不了。</span>因为丙本质上可以为小数.
丙是0.5, X = 12, Y = 4; 这是倍数是取得到的.


```cpp
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int db_equal(double d1, double d2) {
  return -0.0005 < d1-d2 && d1-d2 < 0.0005;
}

int main() {
  int m, x, y; cin >> m >> x >> y;
  string strs[4] = {"Cong", "Ping", "Gai"};
  int jia, yi, find = 0;
  double bing;
  for (int i = 99; i >= 10; i--) {
    jia = i;
    int second = jia % 10, first = jia/10%10;
    yi = second*10+first;
    int delta = (jia > yi) ? jia-yi : yi-jia;
    double bing = delta*1.0 / x;
    // if (!db_equal(bing, floor(bing+0.5))) continue;   // 0.5?
    if (db_equal(0, bing*y-yi)) {
      int a = jia >= m  ? jia > m ? 0:1:2,
          b = yi >= m   ? yi > m  ? 0:1:2,
          c = bing < m  ? 2 : bing > m ? 0:1;
          // c = tmp_b >= m ? tmp_ > m ? 0:1:2;
      cout << jia << " " << strs[a] << " " << strs[b] << " " << strs[c] << endl;
      find = 1;
      break;
    }
  }
  if (!find) {
    cout << "No Solution" << endl;
  }
  return 0;
}
```


### 1089 狼人杀-简单版(20)
[算法, PAT, Hash散列, 逻辑题]
以下文字摘自《灵机一动·好玩的数学》：“狼人杀”游戏分为狼人、好人两大阵营。在一局“狼人杀”游戏中，1 号玩家说：“2 号是狼人”，2 号玩家说：“3 号是好人”，3 号玩家说：“4 号是狼人”，4 号玩家说：“5 号是好人”，5 号玩家说：“4 号是好人”。已知这 5 名玩家中有 2 人扮演狼人角色，有 2 人说的不是实话，有狼人撒谎但并不是所有狼人都在撒谎。扮演狼人角色的是哪两号玩家？

本题是这个问题的升级版：已知 N 名玩家中有 2 人扮演狼人角色，有 2 人说的不是实话，有狼人撒谎但并不是所有狼人都在撒谎。要求你找出扮演狼人角色的是哪几号玩家？

#### 输入格式：

输入在第一行中给出一个正整数 N（5≤N≤100）。随后 N 行，第 i 行给出第 i 号玩家说的话（1≤i≤N），即一个玩家编号，用正号表示好人，负号表示狼人。

#### 输出格式：

如果有解，在一行中按递增顺序输出 2 个狼人的编号，其间以空格分隔，行首尾不得有多余空格。如果解不唯一，则输出最小序列解 —— 即对于两个序列 A=a[1],...,a[M] 和 B=b[1],...,b[M]，若存在 0≤k<M 使得 a[i]=b[i] （i≤k），且 a[k+1]<b[k+1]，则称序列 A 小于序列 B。若无解则输出 No Solution。

#### 输入样例 1：
5
-2
+3
-4
+5
+4

#### 输出样例 1：
1 4

#### 输入样例 2：
6
+6
+3
+1
-5
-2
+4

#### 输出样例 2（解不唯一）：
1 5

#### 输入样例 3：
5
-2
-3
-4
-5
-1

#### 输出样例 3：
No Solution

#### Solution:

考试是没ac掉的题, 惋惜。自己的逻辑还需要锻炼, 要刷更多的题, 做更多事情, 认识更多人, 看更大的世界.

```
2 人扮演狼人角色，有 2 人说的不是实话，有狼人撒谎但并不是所有狼人都在撒谎
```

其实姥姥已经把问题写的很实质简短了, 是我真的太笨没能理解透。

分析一下, 最关键的是这两个条件:
<span style="color:red">1, 只有两个狼人, 其他都是好人.</span>
<span style="color:red">2, 只有两个人说了假话, 一个是狼人, 一个是好人, 其他人都说真话.</span>

正确思路是:
<span style="color:red">枚举两个狼人, 狼人如果确定了, 只要看谁说错了就是在说谎, 看谁说错的过程就是一个查Hash表的过程, 因为每个人都有一种观点talk, 另外, 每一个人都身份根据枚举的狼人建成了Hash表, 是确定的。最后只要判断说假话只有两个人, 并且只有一狼。</span>


能想到枚举的方法, 但在考试的时候, 一直分析不出判断某次枚举成立的条件是什么。实际上回过头来看, 只要同时满足上述两个条件就好了。

我考试的时候枚举的是说谎的人, 这样枚举应该是条死路.
1, 首先, 说谎的人数是不固定的, 后面还需要根据展开的结果重新判断一次说谎人数是不是符合, 而狼人如果确定了, 只要看谁说错了就是在说谎.
2, 题目要求的就是狼人, 为什么逻辑还要嵌套一层呢?
3, 就需要先根据每个人说的, 得到所有人的身份, 然后确定是不是有两个狼人, 其中一个狼人是说谎的人.. 但问题是如果有些人的身份, 没直接提到怎么办呢? 我想这个应该是我错误的原因吧。

当然, 除此之外, 我前面的程序里还有很多冗杂的逻辑, 比如, copy一个vector????自己写了函数??? 比如, 自己实现的to_string和stoi不舍得丢, 分析每个人说话的时候, 还用到了string, s[0]看符号??substr提取数字???(经过, [学长](https://github.com/HankDaly)的提醒, 后来改成了读整数, 判断正负...调试的时候, 还出现了溢出的情况, 回过头来想真是可怕, 只能用兵荒马乱来形容...


我考试时候没能写出的代码:
```cpp
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct Talk {
  int st;
  int id;
};

int main() {
  int N; scanf("%d", &N);
  vector<Talk> talk_v(N+1);
  int st_arr[105];

  for (int i = 1; i <= N; i++) {
    int temp = 0; scanf("%d", &temp);
    int st = 0, id = temp;
    if (temp < 0) {
      st = 1; id = -1 * temp;
    }
    Talk talk; talk.st = st; talk.id = id;
    talk_v[i] = talk;
  }

  int find = 0;
  for (int i = 1; i <= N-1; i++) {
    for (int j = i+1; j <= N; j++) {
      memset(st_arr, 0, sizeof(st_arr));

      st_arr[i] = 1; st_arr[j] = 1;
      vector<int> lier_v;
      for (int k = 1; k <= N; k++) {
        int id_k = talk_v[k].id, st_k = talk_v[k].st;
        if (st_arr[id_k] != st_k) {
          lier_v.push_back(k);
        }
      }

      if (lier_v.size() == 2) {
        int cnt = 0;
        for (int k = 0; k < 2; k++) {
          if (lier_v[k] == i || lier_v[k] == j) cnt++;
        }
        if (cnt == 1) {
          find = 1;
          printf("%d %d\n", i, j);
          break;
        }
      }
    }
    if (find) break;
  }
  if (!find) printf("No Solution\n");
  return 0;
}
```



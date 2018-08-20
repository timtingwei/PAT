## Basic-PAT-C++
### 1079 延迟的回文数（20 point(s)）

非回文数也可以通过一系列操作变出回文数。首先将该数字逆转，再将逆转数与该数相加，如果和还不是一个回文数，就重复这个逆转再相加的操作，直到一个回文数出现。如果一个非回文数可以变出回文数，就称这个数为延迟的回文数。（定义翻译自 https://en.wikipedia.org/wiki/Palindromic_number ）

给定任意一个正整数，本题要求你找到其变出的那个回文数。

#### 输入格式：
输入在一行中给出一个不超过1000位的正整数。

#### 输出格式：
对给定的整数，一行一行输出其变出回文数的过程。每行格式如下

A + B = C
其中 A 是原始的数字，B 是 A 的逆转数，C 是它们的和。A 从输入的整数开始。重复操作直到 C 在 10 步以内变成回文数，这时在一行中输出 C is a palindromic number.；或者如果 10 步都没能得到回文数，最后就在一行中输出 Not found in 10 iterations.。

#### 输入样例 1：
97152

#### 输出样例 1：
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.

#### 输入样例 2：
196

#### 输出样例 2：
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.


#### Solution:

6666666666666666666667
6666666666666666666667 + 7666666666666666666666 = 213188061011727701
213188061011727701 + 107727110160881312 = 320915171172609013
320915171172609013 + 310906271171519023 = 631821442344128036
631821442344128036 + 630821443244128136 = 1262642885588256172
1262642885588256172 + 2716528855882462621 = 3979171741470718793
3979171741470718793 + 3978170741471719793 = 7957342482942438586
7957342482942438586 + 6858342492842437597 = -3631059097924675433
-3631059097924675433 + 3345764297909501363- = 7088702077019689060
7088702077019689060 + 0609869107702078807 = 7698571184721767867
7698571184721767867 + 7687671274811758967 = -3060501614176024782
Not found in 10 iterations.



```cpp
#include <iostream>
#include <string>
using namespace std;

string reverse(string s) {
  string tmp;
  int n = s.length();
  for (int i = n-1; i >= 0; i--) {
    tmp += s[i];
  }
  return tmp;
}

int is_p(string s) {
  int n = s.length();
  for (int i = 0; i <= n / 2; i++) {
    if (s[i] != s[n-1-i]) return 0;
  }
  return 1;
}

long long re_stoi(string s) {
  long long ans = 0;
  int n = s.length(); long long b = 1;
  for (int i = n-1; i >= 0; i--) {
    ans += (s[i] - '0') * b;
    b *= 10;
  }
  return ans;
}

int main() {
  string A; cin >> A;
  int cnt = 0;
  if (is_p(A)) {
    cout << A << " is a palindromic number.\n";
  } else {
    for (;;) {
      string s1, s2;
      s1 = A;
      s2 = reverse(A);
      A = to_string(re_stoi(s1) + re_stoi(s2));         // bug case7
      cout << s1 << " + " << s2 << " = " << A << endl;  // bug1
      if (is_p(A)) {
        cout << A << " is a palindromic number.\n";
        break;
      }
      // 10755470 + 07455701 = 18211171
      // cout << s1 << " + " << s2 << " = " << A << endl;  // bug1
      if (++cnt == 10) {
        cout << "Not found in 10 iterations.\n"; break;
      }
    }
  }

  return 0;
}
```

### 1085 PAT单位排行（25 point(s)）

每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个功能。

#### 输入格式：
输入第一行给出一个正整数 N（≤10^​5），即考生人数。随后 N 行，每行按下列格式给出一个考生的信息：
准考证号 得分 学校
其中准考证号是由 6 个字符组成的字符串，其首字母表示考试的级别：B代表乙级，A代表甲级，T代表顶级；得分是 [0, 100] 区间内的整数；学校是由不超过 6 个英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。

#### 输出格式：
首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：
排名 学校 加权总分 考生人数
其中排名是该单位的排名（从 1 开始）；学校是全部按小写字母输出的单位码；加权总分定义为乙级总分/1.5 + 甲级总分 + 顶级总分*1.5的整数部分；考生人数是该属于单位的考生的总人数。

学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。

#### 输入样例：
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu

#### 输出样例：
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2

#### Solution:

最后一个测试点一直通不过, 问题不是出在对score相加有误差, score我也定义成了double, 问题是出在: <span style="color:red">排序是根据加权总分取整后的值来的</span>, 但是我的做法只是将Node, 从mp中push_back进入vector, 这时的Node.score还是那个double.应该是说, 在排序的时候, score已经是double舍去整数部分后的int了。

实际上, 这个bug可以在调试排名前两位的score的时候查错, 但是我把问题的关注点放在了浮点数比较的精度上, 导致我用EP=-0.2去迎合答案, 实际上这是一种比较作死的方法.

##### 坑点:

1, 选择用1mp + 1vector 和 3mp+1vector的差别
排序用vector, 对学校进行关联用mp。另外关联好学校后, 再使用两个mp, 记录加权总分和考生人数.

原先的做法是, mp中存储Node, 当需要进行排序时, 直接用Node{a, b, c}构造一个node, push_back进vector
```cpp
v.push_back(Node{it->second.name, (int)it->second.score, it->second.num});
```
但这里出错的关键就是, 不能用int类型的去构造这个对象的score实例变量了, 因此还是选择将Node中的score声明成int类型, Node的意义在于排序。抛开排序以外, 用mp去关联。

将一个map<string, Node> mp, 拆开成两个较小的map容器:
```cpp
map<string, double> sum;
map<string, int> num;
```
这样做的好处是什么?
我觉得是Node中sum类型的转换代价小了, 只要在vector中存放node, 就可以把node中sum声明成int类型. 在这种情况下, 若还要在mp中存放node的话, 这里的sum是double类型, 因此选择用两个单独的map存放sum和num, 用一个map存放学校名字, 只是用于归并.


##### 新技巧:
1, map的find(key)函数, 返回键为key的映射的迭代器。 如果存在的情况好理解, 使用it->second调用; 如果不存在的情况是怎么样呢?

map提供了两种方式来检查是否包含key:
```cpp
mp.count(key);  // 包含返回1, 不包含返回0
mp.find(key);   // 返回迭代器, 如果迭代器是mp.end()说明不存在.

// 第一种方法count(key)
if (!mp.count(id)) {
  mp[school].name = school;    // 两次查找
}

// 第二种方法find(key)
auto it = mp.find(id);
if (it == mp.end()) {
  it->second.name = school;    // 一次查找
}

```

而我在做题的时候, 为了解决问题, 使用了笨方法
```cpp
if ((mp.find(id)->second.name).empty()) {   // why?
  mp[school].name = school;
}
```

2, 如何优雅的向一个vector中push_back入一个Node

我一直以来都用的方法。
```cpp
for (auto it = mp.begin(); it != mp.end(); it++) {
  Node node;
  node.name = it->second.name;
  node.score = (int)it->second.score;    // important!
  node.num = it->second.num;
  v.push_back(node);
}
```

更加优雅的方法：
```cpp
v.push_back(Node{it->first, (int)sum[it->first], num[it->first]});
```

这种方法有个前提, 要么就是写了构造函数, 要么就是变量没有被定义。
```cpp
struct Node {
  string name;
  int score;        // int score = 0;   这样不能用上述Node{a, b, c}方法构造了.
  int num;
};
```

3, map和unordered_map的区别
`unordered_map`内部用散列来代替红黑树实现map, 内部不排序。
来处理只映射而不按key排序的需求, 速度比map要快得多. 因此在这里替换一下

##### 代码:
```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
  string name;
  int score;
  int num;
};

unordered_map<string, Node> mp;
unordered_map<string, double> sum;
unordered_map<string, int> num;

vector<Node> v;   // bug01

bool cmp(Node n1, Node n2) {
  if (n1.score != n2.score) return n1.score >= n2.score;
  if (n1.num != n2.num) return n1.num < n2.num;
  return n1.name < n2.name;
}

int main() {
  int N; scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    string id, school; double score;
    cin >> id;
    scanf("%lf", &score);
    cin >> school;
    for (int i = 0; i < school.length(); i++) {
      school[i] = tolower(school[i]);
    }
    if (id[0] == 'B') {
      score = score / 1.5;
    } else if (id[0] == 'T') {
      score = score * 1.5;
    }
    if (!mp.count(school)) {
      mp[school].name = school;
    }
    sum[school] += score;   // bug05
    num[school]++;
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    v.push_back(Node{it->first, (int)sum[it->first], num[it->first]});
  }
  // case7在排序时候已经在比较score
  sort(v.begin(), v.end(), cmp);

  cout << v.size() << endl;                 // bug07
  int r = 1;
  cout << r << " " << v[0].name << " " << v[0].score << " " << v[0].num << endl;
  for (int i = 1; i < v.size(); i++) {
    if (v[i].score != v[i-1].score) {
      r = i + 1;
    }
    cout << r << " " << v[i].name << " " << v[i].score << " " << v[i].num << endl;
  }
  return 0;
}
```


### 1031 查验身份证（15 point(s)）

一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：

Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2
现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

#### 输入格式：
输入第一行给出正整数N（≤100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。

#### 输出格式：
按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。如果所有号码都正常，则输出All passed。

#### 输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X

#### 输出样例1：
12010X198901011234
110108196711301866
37070419881216001X

#### 输入样例2：
2
320124198808240056
110108196711301862

#### 输出样例2：
All passed

#### Solution:


```cpp
#include <iostream>
#include <string>
using namespace std;


char md[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int weight[20] = {7, 9, 10, 5, 8,  4, 2, 1, 6, 3,  7, 9, 10, 5, 8, 4, 2};
int main() {
  int N, cnt = 0;
  scanf("%d", &N);
  while (N--) {
    string s; cin >> s;
    int ok = 1;
    int sum = 0;

    for (int i = 0; i < 17; i++) {
      if (isdigit(s[i])) {
        sum += (s[i]-'0') * weight[i];
      } else {
        ok = 0; break;
      }
    }

    if (!ok) {
      cout << s << endl; cnt++;
    } else {
      int Z = sum % 11;
      if (md[Z] != s[17]) {
        cout << s << endl; cnt++;
      }
    }
  }
  if (cnt == 0) {
    cout << "All passed" << endl;
  }

  return 0;
}
```



### 1048 数字加密（20 point(s)）

本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

#### 输入格式：
输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

#### 输出格式：
在一行中输出加密后的结果。

#### 输入样例：
1234567 368782971

#### 输出样例：
3695Q8118

#### Solution:

这题是错的@陈越姥姥.


分析题中所写: 对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算;
也就是说如果B有5位, 1, 2, 3, 4, 5之后就不会比较了。也就是说只有五位。

但是case2， 5能ac的情况是, <span style="color:red">把B与A的每一个位数比较</span>, 所以要B补齐

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string A, B; cin >> A >> B;
  int M = A.length(), N = B.length();
  if (N < M) {
    B.insert(0, M-N, '0');
    N = M;
  } else if (N > M) {
    A.insert(0, N-M, '0');
    M = N;
  }
  string s, tmp_s;
  for (int i = 0; i < M; i++) {
    int x;
    int a = A[M-1-i] - '0', b = B[N-1-i] - '0';

    if ((i+1)%2) {
      x = (a+b) % 13;
      if (x == 10) {
        tmp_s = 'J';
      } else if (x == 11) {
        tmp_s = 'Q';
      } else if (x == 12) {
        tmp_s = 'K';
      } else {
        tmp_s = x + '0';
      }

    } else {
      x = b - a;
      if (x < 0) x += 10;
      tmp_s = x + '0';
    }
    s += tmp_s;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
  return 0;
}
```

    
### 1052 卖个萌（20 point(s)）

萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：
```
[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。
```

#### 输入格式：

输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号 []内。题目保证每个集合都至少有一个符号，并不超过 10 个符号；每个符号包含 1 到 4 个非空字符。

之后一行给出一个正整数 K，为用户请求的个数。随后 K 行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从 1 开始），数字间以空格分隔。

#### 输出格式：

对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出 Are you kidding me? @\/@。

#### 输入样例：
```
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
```

#### 输出样例：

╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@

#### Solution:


两个坑点:
1, 之前对substr理解有误, s.substr(pos, length); 第一个参数是下标, <span style="color:red">第二个参数是长度</span>, 之前一直以为是要获取元素的后一个元素.这个问题把我坑爹了半小时.
```cpp
string s = "abcd";
string tmp = s.substr(0, 2);
cout << tmp << endl;      // ab
tmp = s.substr(1, 2);
cout << tmp << endl;      // bc
```
2, 序号从1开始, 在判断范围的时, 从1~n, 我之前写成了0~n-1...


```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string> > emoji;
int order[6] = {0, 1, 2, 1, 0};

int main() {
  for (int k = 0; k < 3; k++) {
    string s;
    getline(cin, s);
    int n = s.length();
    vector<string> row;
    int i = 0, j = 0;
    while (i < n) {
      if (s[i] == '[') {
        string tmp_s;
        j = i+1;
        while (j < n && s[j] != ']') j++;
        tmp_s = s.substr(i+1, j-i-1);                 // bug02
        row.push_back(tmp_s);
        i = j;
      } else {
        i++;
      }
    }
    emoji.push_back(row);
  }

  int K; cin >> K;
  for (int k = 0; k < K; k++) {
    if (k) cout << endl;
    string ans_s; int ok = 1;
    for (int i = 0; i < 5; i++) {
      int tmp; cin >> tmp;
      int n = emoji[order[i]].size();
      // if (tmp < 0 || tmp > n-1) {                  // bug04
      if (tmp < 1 || tmp > n) {
        // cout << "Are you kidding me? @\\/@\n";     // bug01
        ok = 0;
        break;
      }
      if (i == 1) ans_s += "(";
      else if (i == 4) ans_s += ")";
      ans_s += emoji[order[i]][tmp-1];
    }
    if (ok) {
      cout << ans_s;
    } else {
      cout << "Are you kidding me? @\\/@";            // bug03
    }
  }
  return 0;
}
```


### 1054 求平均值（20 point(s)）

本题的基本要求非常简单：给定 N 个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位。当你计算平均值的时候，不能把那些非法的数据算在内。

#### 输入格式：
输入第一行给出正整数 N（≤100）。随后一行给出 N 个实数，数字间以一个空格分隔。

#### 输出格式：

对每个非法输入，在一行中输出 ERROR: X is not a legal number，其中 X 是输入。最后在一行中输出结果：The average of K numbers is Y，其中 K 是合法输入的个数，Y 是它们的平均值，精确到小数点后 2 位。如果平均值无法计算，则用 Undefined 替换 Y。如果 K 为 1，则输出 The average of 1 number is Y。

#### 输入样例 1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35

#### 输出样例 1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38

#### 输入样例 2：
2
aaa -9999

#### 输出样例 2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined

#### Solution:

最后一个case点无端错误.

这里复习一个技巧

```cpp
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

int main() {
  int N; scanf("%d", &N);
  char s[50], b[50];
  int cnt = 0; double sum = 0, tmp;
  while (N--) {;
    scanf("%s", s);
    sscanf(s, "%lf", &tmp);
    sprintf(b, "%.2lf", tmp);
    int flag = 0;
    for (int i = 0; i < strlen(s); i++) {
      if (s[i] != b[i]) { flag = 1; break;}
    }
    if (flag || tmp < -1000 || tmp > 1000) {
      printf("ERROR: %s is not a legal number\n", s);
    } else {
      sum += tmp; cnt++;
    }
  }

  if (!cnt) {
    printf("The average of 0 numbers is Undefined\n");
  } else if (cnt == 1) {
    printf("The average of 1 number is %.2lf\n", sum);
  } else {
    printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
  }
  return 0;
}
```

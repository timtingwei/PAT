## Basic-PAT-C++

### 1067 试密码（20 point(s)）
当你试图登录某个系统却忘了密码时，系统一般只会允许你尝试有限多次，当超出允许次数时，账号就会被锁死。本题就请你实现这个小功能。

#### 输入格式：
输入在第一行给出一个密码（长度不超过 20 的、不包含空格、Tab、回车的非空字符串）和一个正整数 N（≤ 10），分别是正确的密码和系统允许尝试的次数。随后每行给出一个以回车结束的非空字符串，是用户尝试输入的密码。输入保证至少有一次尝试。当读到一行只有单个 # 字符时，输入结束，并且这一行不是用户的输入。

#### 输出格式：
对用户的每个输入，如果是正确的密码且尝试次数不超过 N，则在一行中输出 Welcome in，并结束程序；如果是错误的，则在一行中按格式输出 Wrong password: 用户输入的错误密码；当错误尝试达到 N 次时，再输出一行 Account locked，并结束程序。

#### 输入样例 1：
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#

#### 输出样例 1：
Wrong password: correct%pw
Wrong password: Correct@PW
Wrong password: whatisthepassword!
Account locked

#### 输入样例 2：
cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#

#### 输出样例 2：
Wrong password: coolman@gplt
Wrong password: coollady@gplt
Welcome in

#### Solution:

三个注意点:

注意点1: 用getline时, 之前读过一行, 还会留下一个换行符没读, 因此只会打印出一个空行, 第二行的字符串不会被读取到。

```cpp
string ans; int N;
cin >> ans >> N;
getline(cin, s);
cout << s << endl;
```

```sh
./a.out
aabbc 5
dsdsd
```
解决方法是, 在这种情况下, 在getline()之前加一个getchar()

注意点2: 想清楚操作执行的顺序
> * 读取输入
> * 检查输入是不是#
> * 读取次数+1
> * 正确且不超过N, welcome结束
> * 不正确且不超过N, wrong, 如果这是最后一次机会, 不等下次locked结束

注意点3:如果密码错误且到达了错误次数, 是先输出wrong再输入locked

```cpp
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
  string ans; int N;
  cin >> ans >> N;
  getchar();
  int cnt = 0;
  string s;
  for (;;) {
    getline(cin, s);
    cnt++;
    if (s == "#") break;
    if (s == ans && cnt <= N) {
      cout << "Welcome in" << endl; break;
    } else if (s != ans && cnt <= N) {
      cout << "Wrong password: " << s << endl;
      if (cnt == N) {
        cout << "Account locked" << endl; break;
      }
    }
  }
  return 0;
}

```


### 1081 检查密码（15 point(s)）

本题要求你帮助某网站的用户注册模块写一个密码合法性检查的小功能。该网站要求用户设置的密码必须由不少于6个字符组成，并且只能有英文字母、数字和小数点 .，还必须既有字母也有数字。

####  输入格式：

输入第一行给出一个正整数 N（≤ 100），随后 N 行，每行给出一个用户设置的密码，为不超过 80 个字符的非空字符串，以回车结束。

#### 输出格式：

对每个用户的密码，在一行中输出系统反馈信息，分以下5种：

如果密码合法，输出Your password is wan mei.；
如果密码太短，不论合法与否，都输出Your password is tai duan le.；
如果密码长度合法，但存在不合法字符，则输出Your password is tai luan le.；
如果密码长度合法，但只有字母没有数字，则输出Your password needs shu zi.；
如果密码长度合法，但只有数字没有字母，则输出Your password needs zi mu.。

#### 输入样例：
5
123s
zheshi.wodepw
1234.5678
WanMei23333
pass*word.6

#### 输出样例：
Your password is tai duan le.
Your password needs shu zi.
Your password needs zi mu.
Your password is wan mei.
Your password is tai luan le.

#### Solution:

画树状分析

```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
  int N;
  cin >> N;
  string s;
  getchar();
  while (N--) {
    getline(cin, s);
    int alpha = 0, digit = 0, ch_flag = 1;
    for (int i = 0; i < s.length(); i++) {
      if (isdigit(s[i]) || isalpha(s[i]) || s[i] == '.') {
        if (isdigit(s[i])) digit++;
        else if (isalpha(s[i])) alpha++;
      } else {
        ch_flag = 0;
      }
    }
    if (s.length() < 6) {
      cout << "Your password is tai duan le." << endl;
    } else if (s.length() >= 6 && !ch_flag) {
      cout << "Your password is tai luan le." << endl;
    } else if (s.length() >= 6 && (alpha != 0) && (digit == 0)) {
      cout << "Your password needs shu zi." << endl;
    } else if (s.length() >= 6 && (alpha == 0) && (digit != 0)) {
      cout << "Your password needs zi mu." << endl;
    } else {
      cout << "Your password is wan mei." << endl;
    }
  }

  return 0;
}
```

### 1084 外观数列 （20 point(s)）

外观数列是指具有以下特点的整数序列：

d, d1, d111, d113, d11231, d112213111, ...

它从不等于 1 的数字 d 开始，序列的第 n+1 项是对第 n 项的描述。比如第 2 项表示第 1 项有 1 个 d，所以就是 d1；第 2 项是 1 个 d（对应 d1）和 1 个 1（对应 11），所以第 3 项就是 d111。又比如第 4 项是 d113，其描述就是 1 个 d，2 个 1，1 个 3，所以下一项就是 d11231。当然这个定义对 d = 1 也成立。

本题要求你推算任意给定数字 d 的外观数列的第 N 项。

#### 输入格式：

输入第一行给出 [0,9] 范围内的一个整数 d、以及一个正整数 N（≤ 40），用空格分隔。

#### 输出格式：

在一行中给出数字 d 的外观数列的第 N 项。

#### 输入样例：

1 8
#### 输出样例：

1123123111


#### Solution:
思路1:
map怎么插入一个元素, 某个元素数量+1， .count()检查某个元素是否存在, s[i] = 5;可以赋值
但是map按照字典序进行排列, 不是我的原意
思路2:
观察数据构造, 发现之前理解有问题..

观察后一个s的特点为
```sh
axbxcxdx...     // x是量, a是字符
```

<span style="color:red">也就是在扫描字符串时, 计算a的量cnt将它转换成字符添在a后面即可, perform独立成方法, 最后统一输出s</span>

```cpp
#include <iostream>
#include <map>
using namespace std;

string perform(string s) {
  string tmp;
  int i = 0;
  while (i < s.length()) {
    tmp += s[i];
    int cnt = 1, j = i + 1;
    while (s[i] == s[j] && j < s.length()) { cnt++; j++;}
    tmp += cnt + '0';
    i = j;
  }
  return tmp;
}

int main() {
  string s; int N;
  cin >> s >> N;
  for (int i = 0; i < N - 1; i++) { s = perform(s); }
  std::cout << s << std::endl;
  return 0;
}
```

### 1033 旧键盘打字(20)（20 point(s)）

旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

#### 输入格式：

输入在2行中分别给出坏掉的那些键、以及应该输入的文字。
其中对应英文字母的坏键以大写给出；
每段文字是不超过10^5^个字符的串。
可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。
题目保证第2行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

#### 输出格式：

在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

#### 输入样例：

7+IE.
7_This_is_a_test.
#### 输出样例：

_hs_s_a_tst

#### Solution:


我学习了哈希散列之后, 在网上又看到这样的解法:
```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
  string bad, should;
  getline(cin, bad);
  getline(cin, should);
  for (int i = 0; i < should.length(); i++) {
    if (bad.find(toupper(should[i])) != string::npos) continue;
    if (isupper(should[i]) && bad.find('+') != string::npos) continue;
    cout << should[i];
  }
  return 0;
}
```

分析可得
1, 把操作都放在一个string中进行, 没有额外的vector, 减少了很多代码。

2, string对象, 可以调用find()函数, 如果找到了这个字符, 就返回这个字符的索引, 如果没找到, 返回一个与string::npos相等的值 cout << string::npos << endl;   // 18446744073709551615

3, toupper和isupper的使用, 注意的是, toupper对非字母的字符也能起到作用, 因此可以将对整个字符串进行遍历

4, Hash散列, 通过查找HashTable中的key值, 判断key是否在列表中, 这里抽象出来, 就是判断某个字符ch, 或者是toupper(ch), 用find()函数判断是不是在这个字符串中, 在的给出相应的操作。

5, 这道题对不符合条件的进行忽略continue, 不符合的有两种:一种是转换成upper之后能在坏键字符串中找到的, 一种是, 另一种是大写, 但坏键中有"+"上档位键 

### 1038 统计同成绩学生(20)（20 point(s)）

本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。

#### 输入格式：

输入在第1行给出不超过10^5^的正整数N，即学生总人数。随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。

#### 输出格式：

在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

#### 输入样例：

10
60 75 90 55 75 99 82 90 75 50
3 75 90 88

#### 输出样例：
3 2 0

#### Solution:

注意点:
1, 使用memset, 需要include <cstring>头文件; 如果用vector构造全为0的数组的话, vector v(101);
2, 0-100分有101个数, 如果写100的话, case3通不过
3, 这题需要用scanf读, 用cin就case3超时, case的数据量有点大的
case3:

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int a[101];
  memset(a, 0, sizeof(a));
  int N, K, tmp;
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &tmp);
    a[tmp]++;
  }
  scanf("%d", &K);
  for (int i =0; i < K; i++) {
    if (i) cout << " ";
    scanf("%d", &tmp);
    printf("%d", a[tmp]);
  }
  return 0;
}
```


### 1039 到底买不买（20）（20 point(s)）

小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。

为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。

\ 图 1

#### 输入格式：

每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。

#### 输出格式：

如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。

#### 输入样例1：

ppRYYGrrYBR2258
YrR8RrY

#### 输出样例1：
Yes 8

#### 输入样例2：
ppRYYGrrYB225
YrR8RrY

#### 输出样例2：
No 2

#### Solution:

注意点:
case 1, 2WA: 怎么解决某个珠子需要两课以上问题, 也就是说要把取过的字符给删除?

<span style="color:red">另外, Hash散列的思想, 主要体现在, 一个address对应一个key, 现在要判断的是珠子这个key是否存在, 用find函数完成了判断, 但我认为还是只用了Hash散列的策略，这里没有去设计是否均匀, 解决冲突等问题, find函数的复杂度也应该不是O(1), 但这个策略还是抓住了问题的本质.</span>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int cnt = 0;
  for (int i = 0; i < t.length(); i++) {
    int pos = s.find(t[i]);
    if (pos != string::npos) {
      cnt++;
      s.erase(pos, 1);
    }
  }
  if (cnt >= t.length()) {
    cout << "Yes " << s.length() << endl;
  } else {
    cout << "No " << t.length() - cnt << endl;
  }

  return 0;
}
```

补充常用的两种字符串删除,

一般要对取字符串进行删除, 无非是删除子串和删除字符(删除子串的特殊情况),

1, 索引+长度删除, 删子串(也可以删长度为1的子串)
```cpp
string s, t;

// erase(int pos, int length);    // 用索引+子串长度删除
s = "1aabcd";
t = "aa";
int pos = s.find(t);
s.erase(pos, t.length());         // s.erase(pos, 2);

cout << s << endl;                // 1bcd
```

2, 迭代器删除, 删字符
```cpp

  // erase(iterator it)             // 用迭代器删除
  s = "1aabcd";
  t = "b";
  pos = s.find(t);
  s.erase(s.begin() + pos);
  cout << s << endl;                // 1aacd
```

### 1042 字符统计（20）（20 point(s)）

请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

#### 输入格式：

输入在一行中给出一个长度不超过 1000 的字符串。字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）。

#### 输出格式：

在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

#### 输入样例：

This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
#### 输出样例：

e 7

#### Solution:

将字符的ascii码作为address,  address = key, a[adrr] = cnt(key);
用max_p记录出现次数最多字符的ascii码, 打印时, 可以直接转换和索引.

坑点, case 2, 如果有并列, 输出字典序小的, 判断两个位置最大值是否相等, 且当前i对应字母更小;

另外我测试了ascii码的分布情况, 所以, 散列表大小开到150左右就ok了
```
'a' = 97, 'z' = 122, 'A' = 65, 'Z' = 90
'0' = 48, '9' = 57
```

```cpp
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int cnt[200];   // 假设ascii200位
int main() {
  memset(cnt, 0, sizeof(cnt));
  string s;
  getline(cin, s);
  int max_p = 0;
  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i])) {
      int ch = tolower(s[i]);
      cnt[ch]++;
      if (cnt[ch] > cnt[max_p]) max_p = ch;
      if (cnt[ch] == cnt[max_p] && (ch < max_p)) max_p = ch;
    }
  }
  printf("%c %d\n", max_p, cnt[max_p]);

  return 0;
}
```




### 1043 输出PATest（20 point(s)）

给定一个长度不超过 10^4的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

#### 输入格式：
输入在一行中给出一个长度不超过 10^4​的、仅由英文字母构成的非空字符串。

#### 输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

#### 输入样例：
redlesPayBestPATTopTeePHPereatitAPPT

#### 输出样例：
PATestPATestPTetPTePePee


#### Solution:

Hash散列将字符key转化成对应索引, 每出现一次cnt+1, 让散列表中的字符按照顺序循环打印, 每次打印都减少次数, 直到次数为空

```cpp
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char chars[6] = {'P', 'A', 'T', 'e', 's', 't'};

int main() {
  int cnt[6];
  memset(cnt, 0, sizeof(cnt));
  string s; cin >> s;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < 6; j++)
      if (s[i] == chars[j]) { cnt[j]++; break; }
    /*
    if (s[i] == 'P') cnt[0]++;
    else if (s[i] == 'A') cnt[1]++;
    else if (s[i] == 'T') cnt[2]++;
    else if (s[i] == 'e') cnt[3]++;
    else if (s[i] == 's') cnt[4]++;
    else if (s[i] == 't') cnt[5]++;
    */
  }
  
  int ok;
  do {
    ok = 0;
    for (int i = 0; i < 6; i++) {
      if (cnt[i]) {
        ok = 1;
        printf("%c", chars[i]);
        cnt[i]--;
      }
    }
  } while (ok);
  
  return 0;
}
```


### 1047 编程团体赛（20 point(s)）

编程团体赛的规则为：每个参赛队由若干队员组成；所有队员独立比赛；参赛队的成绩为所有队员的成绩和；成绩最高的队获胜。

现给定所有队员的比赛成绩，请你编写程序找出冠军队。

#### 输入格式：

输入第一行给出一个正整数 N（≤10^4），即所有参赛队员总数。随后 N 行，每行给出一位队员的成绩，格式为：队伍编号-队员编号 成绩，其中队伍编号为 1 到 1000 的正整数，队员编号为 1 到 10 的正整数，成绩为 0 到 100 的整数。

#### 输出格式：

在一行中输出冠军队的编号和总成绩，其间以一个空格分隔。注意：题目保证冠军队是唯一的。

#### 输入样例：
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61

#### 输出样例：
11 176

#### Solution:

team作为address地址, f(key) = key; 对字符串根据分隔符求子串

```cpp
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int scores[1000];

int main() {
  int N; string s;
  cin >> N;
  memset(scores, 0, sizeof(scores));
  getchar();
  int max = 0;
  while (N--) {
    getline(cin, s);
    string team = s.substr(0, s.find("-"));
    string score = s.substr(s.find(" ")+1, s.length());
    int i_team = stoi(team);
    scores[i_team] += stoi(score);
    if (scores[i_team] > scores[max]) max = i_team;
  }
  cout << max << " " << scores[max] << endl;
  return 0;
}
```


### 1083 是否存在相等的差（20 point(s)）
    
给定 N 张卡片，正面分别写上 1、2、……、N，然后全部翻面，洗牌，在背面分别写上 1、2、……、N。将每张牌的正反两面数字相减（大减小），得到 N 个非负差值，其中是否存在相等的差？

#### 输入格式：

输入第一行给出一个正整数 N（2 ≤ N ≤ 10 000），随后一行给出 1 到 N 的一个洗牌后的排列，第 i 个数表示正面写了 i 的那张卡片背面的数字。

#### 输出格式：

按照“差值 重复次数”的格式从大到小输出重复的差值及其重复的次数，每行输出一个结果。

#### 输入样例：

8
3 5 8 6 2 1 4 7

#### 输出样例：

5 2
3 3
2 2

#### Solution:

差值作为散列地址, f(key) = key, 在不同差值地址上计数, 对重复的差值进行排序

坑点:
> * 1, 牌从1开始计数, 1 2 3 4 5 ..
> * 2, 要对差值进行排序, 这里用了vector, 写cmp函数的方法, 不知道还有没有其他.


```cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 10000
typedef struct {
  int delta;
  int cnt;
} Node;

int cnt[MAXN];
vector<Node> ans;

int cmp(Node n1, Node n2) {
  return  n1.delta > n2.delta;
}

int main() {
  int N, v;
  cin >> N;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < N; i++) {
    cin >> v;
    int d = (i < v) ? v-(i+1) : (i+1)-v;
    cnt[d]++;
  }

  for (int i = 0; i < MAXN; i++) {
    if (cnt[i] > 1) {
      Node node;
      node.delta = i; node.cnt = cnt[i];
      ans.push_back(node);
    }
  }

  sort(ans.begin(), ans.end(), cmp);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].delta << " " << ans[i].cnt << endl;
  }
  return 0;
}
```


### 1055 集体照（25 point(s)）

拍集体照时队形很重要，这里对给定的 N 个人 K 排的队形设计排队规则如下：

每排人数为 N/K（向下取整），多出来的人全部站在最后一排；

后排所有人的个子都不比前排任何人矮；

每排中最高者站中间（中间位置为 m/2+1，其中 m 为该排人数，除法向下取整）；

每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；

若多人身高相同，则按名字的字典序升序排列。这里保证无重名。

现给定一组拍照人，请编写程序输出他们的队形。

#### 输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出两个正整数 N（≤10^4总人数）和 K（≤10，总排数）。随后 N 行，每行给出一个人的名字（不包含空格、长度不超过 8 个英文字母）和身高（[30, 300] 区间内的整数）。

#### 输出格式：
输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。

#### 输入样例：
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159

#### 输出样例：
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John

#### Solution:

```
m/2-2  m/2-1  m/2  m/2+1  m/2+2
```
从最高位置开始, 偏移量(offset)为0, -1, +1, -2, +2, 核心问题就是构造这个数列,
```cpp
int offset = ((j-1)/2+1)*flag;
flag *= 1;
```
不过这种做法, 我总觉得费时间, 应该有更好的做法.

坑点: 
1, 题目中说身高相同按照名字的字典序排序, 如果是这样的话, Tim Amy John, Tim应该是排在应该是三人中的最高者, 但我把它改成降序后就正确了, 不知道是我理解有误, 还是它题目出错了.
2, 最后一行有多出来的人数, 在计算时用余数的方法把它加上.

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node {
  char name[10];
  int h;
} a[10050];

Node ans[10050];

bool cmp(Node a, Node b) {
  if (a.h != b.h) return a.h < b.h;
  else return strcmp(a.name, b.name) > 0;  // why?
}


int main() {
  int N, K, m;
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%s %d", a[i].name, &a[i].h);
  }
  int rst = N % K;

  sort(a, a+N, cmp);

  for (int i = K-1; i >= 0; i--) {
    int m = N/K, fp = i * m;
    if (i == K-1) m += rst;

    int j = 1, flag = -1;
    ans[m/2] = a[fp+m-1];
    while (j < m) {
      int offset = ((j-1)/2+1) * flag;
      ans[m/2+offset] = a[fp+m-1-j];
      flag *= -1;
      j++;
    }

    for (j = 0; j < m; j++) {
      if (j) printf(" ");
      printf("%s", ans[j].name);
    }
    printf("\n");
  }

  return 0;
}

```


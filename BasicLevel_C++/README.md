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

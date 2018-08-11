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

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




### 1066 图像过滤（15 point(s)）

图像过滤是把图像中不重要的像素都染成背景色，使得重要部分被凸显出来。现给定一幅黑白图像，要求你将灰度值位于某指定区间内的所有像素颜色都用一种指定的颜色替换。

#### 输入格式：
输入在第一行给出一幅图像的分辨率，即两个正整数 M 和 N（0<M,N≤500），另外是待过滤的灰度值区间端点 A 和 B（0≤A<B≤255）、以及指定的替换灰度值。随后 M 行，每行给出 N 个像素点的灰度值，其间以空格分隔。所有灰度值都在 [0, 255] 区间内。

#### 输出格式：
输出按要求过滤后的图像。即输出 M 行，每行 N 个像素灰度值，每个灰度值占 3 位（例如黑色要显示为 000），其间以一个空格分隔。行首尾不得有多余空格。

#### 输入样例：
3 5 100 150 0
3 189 254 101 119
150 233 151 99 100
88 123 149 0 255

#### 输出样例：
003 189 254 000 000
000 233 151 099 000
088 000 000 000 255

#### Solution:

简单题耗了很长时间。

几点要注意的：
> 1, 简单题也要写最核心的伪代码, 让主要思路不乱。 比如这题将灰度区间内的替换, 而不是之外.
> 2, 对于边界条件, 不确定可以先留出来, submit一次之后再改(主体对, 再改细节), 比如double还是int
> 3, 要调整好心态.

```cpp
#include <cstdio>
int main() {
  int M, N;
  scanf("%d %d", &M, &N);
  int a, b, rp, tmp;
  scanf("%d %d %d", &a, &b, &rp);
  for (int i = 0; i < M; i++) {
    if (i) printf("\n");
    for (int j = 0; j < N; j++) {
      scanf("%d", &tmp);
      if (j) printf(" ");
      if (a <= tmp && tmp <= b) {
        printf("%03d", rp);
      } else {
        printf("%03d", tmp);
      }
    }
  }
  return 0;
}
```


### 1021 个位数统计(15)
tags:Hash散列

给定一个 k 位整数 N=d, 请编写程序统计每种不同的个位数字出现的次数。
例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

#### 输入格式：
每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。

#### 输出格式：
对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。要求按 D 的升序输出。

#### 输入样例：
100311

#### 输出样例：
0:2
1:3
3:1

#### Solution:

统计和查找用Hash表.
以字符数组的形式读入"整数", 扫描这个字符数组, 每个数字字符ch对应的Hash表位置是它的ch-'a'位置. 该位置变量+1

扫描完成后, 扫描Hash表, 如果某个地址上值不为0就打印出个数, 自然升序.

```cpp
#include <cstdio>
#include <cstring>

int cnt[11];
char s[1050];
int main() {
  scanf("%s", s);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < strlen(s); i++) {
    cnt[s[i]-'0']++;
  }
  int flag = 0;
  for (int i = 0; i < 10; i++) {
    if (cnt[i]) {
      if (!flag) {
        flag = 1;
      } else {
        printf("\n");
      }
      printf("%d:%d", i, cnt[i]);
    }
  }
  return 0;
}
```


### 1029 旧键盘(20)

旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

#### 输入格式：
输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。题目保证 2 个字符串均非空。

#### 输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。

#### 输入样例：
```
7_This_is_a_test
_hs_s_a_es
```

#### 输出样例：
7TI


#### Solution:

通过实际被输出的文字建立可行的Hash表, f(key) = toupper(key) - '0';

某个下标对应的值为1代表可行.

遍历输入的那段文字, 若不在Hash表中的, 则是坏键。

坑点:
1, 因为英文字母只输出大写, 所以建表时, 把所有的alpha变成大小来建立, 用大写索引, 用大写输出.
2, 不用在意ascii码, 只要随便取个字符, 记录相对距离就可以。
3, 因为要保证每个坏键只输出一次, 找到一个坏键之后, 在hash表中改成1, 下次这个碰到这个键, 就可以用if避开它了。

```cpp
#include <cstdio>
#include <cstring>
#include <iostream>
int ok[500];
char s[85];
char rst[85];

int main() {
  scanf("%s %s", s, rst);
  for (int i = 0; i < strlen(rst); i++) {
    ok[toupper(rst[i]) - '0'] = 1;
  }

  for (int i = 0; i < strlen(s); i++) {
    if (!ok[  toupper(s[i]) - '0']) {
      printf("%c", toupper(s[i]));
      ok[toupper(s[i]) - '0'] = 1;   // bug01
    }
  }
  return 0;
}
```
    
    
### 1062 最简分数（20 point(s)）

一个分数一般写成两个整数相除的形式：N/M，其中 M 不为0。最简分数是指分子和分母没有公约数的分数表示形式。

现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。

#### 输入格式：
输入在一行中按 N/M 的格式给出两个正分数，随后是一个正整数分母 K，其间以空格分隔。题目保证给出的所有整数都不超过 1000。

#### 输出格式：
在一行中按 N/M 的格式列出两个给定分数之间分母为 K 的所有最简分数，按从小到大的顺序，其间以 1 个空格分隔。行首尾不得有多余空格。题目保证至少有 1 个输出。

#### 输入样例：
7/18 13/20 12

#### 输出样例：
5/12 7/12

#### Solution:

```cpp
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
int limit[1000];
int mp[2500];

int main() {
  char s1[15], s2[15]; int K;
  scanf("%s %s %d", s1, s2, &K);
  getchar();     // print
  int limit_n = 0;

  for (int i = 2; i <= K; i++) {   // bug01, i != 0
    if (K % i == 0) {
      limit[limit_n++] = i;
    }
  }
  // 仍旧可以优化

  int N1, M1, N2, M2;
  sscanf(s1, "%d/%d", &N1, &M1);
  sscanf(s2, "%d/%d", &N2, &M2);
  memset(mp, 0, sizeof(mp));

  double da =  N1/((double)M1/K), db =  N2/( (double) M2/K);
  if (da > db) {double tmp = da; da = db; db = tmp;}
  int a = ceil(da), b = floor(db);

  if (K == 1) {                         // case1
    for (int i = a; i < b; i++) {
      if (-0.00005 < i - da && i - da < 0.000005) continue;
      if (i != a) printf(" ");
      printf("%d/%d", i, K);
    }
    return 0;
  }

  int scale = 1, over = 0;
  while (!over) {
    over = 1;
    for (int i = 0; i < limit_n; i++) {
      int tmp = limit[i] * scale;
      if (tmp <= b) {
        over = 0;
        if (a <= tmp) {
          mp[tmp] = 1;
        }
      }
    }
    scale++;
    if (over) break;
  }

  int first = 0;
  for (int i = a; i < db; i++) {
    if (-0.00005 < i - da && i - da < 0.000005) continue;   // case2
    if (!mp[i]) {
      if (first) printf(" ");
      printf("%d/%d", i, K);
      first = 1;
    }
  }
  printf("\n");
  return 0;
}
```

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

判断分子num与k是否有公约数, 如果有公约数, 就不是最简分数。

坑点:
1, 将除法展开来代替除法之后浮点数的比较
2, 先将num指针用while移动一段距离后开始计算
3, 如果第一个数比第二个数大, 需要交换

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a%b);
}

int main() {
  int N1, M1, N2, M2, K;
  scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);

  // case1
  if (N1*M2 > N2*M1) {
    swap(N1, N2);
    swap(M1, M2);
  }

  int num = 1;
  while (num * M1 <= N1 * K) num++;
  int flag = 0;
  while (num * M1 > N1 * K && M2 * num < N2 * K) {
    if (gcd(num, K) == 1) {
      printf("%s%d/%d", (flag ? " " : ""), num, K);
      flag = 1;
    }
    num++;
  }
  return 0;
}
```


自己的做法:
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

### q
1063 计算谱半径(20)

在数学中，矩阵的“谱半径”是指其特征值的模集合的上确界。换言之，对于给定的 n 个复数空间的特征值 它们的模为实部与虚部的平方和的开方，而“谱半径”就是最大模。
现在给定一些复数空间的特征值，请你计算并输出这些特征值的谱半径。

#### 输入格式：
输入第一行给出正整数 N（≤ 10 000）是输入的特征值的个数。随后 N 行，每行给出 1 个特征值的实部和虚部，其间以空格分隔。注意：题目保证实部和虚部均为绝对值不超过 1000 的整数。

#### 输出格式：
在一行中输出谱半径，四舍五入保留小数点后 2 位。

#### 输入样例：
5
0 1
2 0
-1 0
3 3
0 -3

#### 输出样例：
4.24

#### Solution:

注意, 开方是平方的逆过程.

对小数位后四舍五入的做法, 先将double扩大100倍(小数点后2位), 进位后, 缩小100倍.
其实就是进小数点后2位。

```cpp
#include <cmath>
#include <cstdio>

int main() {
  int N, a, b; scanf("%d", &N);
  double max = 0, tmp;

  while (N--) {
    scanf("%d %d", &a, &b);
    tmp = sqrt(a*a+b*b);
    if (tmp > max) max = tmp;
  }
  printf("%.2lf", floor(max * 100 + 0.5)/100);

  return 0;
}
```

#### 1064 朋友数(20)
tags: Hash散列

如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。例如 123 和 51 就是朋友数，因为 1+2+3 = 5+1 = 6，而 6 就是它们的朋友证号。给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。

#### 输入格式：
输入第一行给出正整数 N。随后一行给出 N 个正整数，数字间以空格分隔。题目保证所有数字小于 10
​4
​​ 。

#### 输出格式：
首先第一行输出给定数字中不同的朋友证号的个数；随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。

#### 输入样例：
8
123 899 51 998 27 33 36 12

#### 输出样例：
4
3 6 9 26

#### Solution:

将朋友证号作为key值, 建成hash表, 重新遍历一遍就可以输出。

注意点: 用一个max_p可以限定hash表遍历的范围.

```cpp
#include <cstdio>
#include <cstring>

int id[10050];
char digit[6];

int main() {
  int N; scanf("%d", &N);
  int cnt = 0, max_p = 0;
  while (N--) {
    scanf("%s", digit);
    int num = 0;
    for (int i = 0; i < strlen(digit); i++) {
      num += digit[i] - '0';
    }

    if (!id[num]) {
      id[num] = 1;
      cnt++;
      if (num > max_p) max_p = num;
    }
  }

  int flag = 0;
  printf("%d\n", cnt);
  for (int i = 0; i <= max_p; i++) {
    if (id[i]) {
      if (flag) printf(" ");
      printf("%d", i);
      flag = 1;
    }
  }
  return 0;
}
```
    

#### 1065 单身狗(25) 
“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

#### 输入格式：
输入第一行给出一个正整数 N（≤ 50 000），是已知夫妻/伴侣的对数；随后 N 行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个 ID 号，为 5 位数字（从 00000 到 99999），ID 间以空格分隔；之后给出一个正整数 M（≤ 10 000），为参加派对的总人数；随后一行给出这 M 位客人的 ID，以空格分隔。题目保证无人重婚或脚踩两条船。

#### 输出格式：
首先第一行输出落单客人的总人数；随后第二行按 ID 递增顺序列出落单的客人。ID 间用 1 个空格分隔，行的首尾不得有多余空格。

#### 输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333

#### 输出样例：
5
10000 23333 44444 55555 88888

#### Solution:
建立两张Hash表, 一张情侣id之间的映射, 另外一张是用于判断要查找的id是否已经有它的爱人出现过。


就是说， 查找时, 抛开查找的几个人不说, 判断它是不是有情侣, 然后再看它的情侣是不是出现在这次晚会中了。
先它将id映射到情侣的id, 如果存在它的情侣, 删除它的情侣(自己本身不需要添加); 如果不存在情侣, 或者是情侣没来, 就把自己添加到单身狗表中。

最后剩下的就是单身狗表。

坑点是:
char* 作为key值不行, 不清楚什么原因, 就用string吧。

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int N; cin >> N;
  map<string, string> pairs;
  for (int i = 0; i < N; i++) {
    string id_a, id_b; cin >> id_a >> id_b;       // why? char*不可以
    pairs[id_a] = id_b;
    pairs[id_b] = id_a;
  }

  int M; cin >> M;
  map<string, int> mp;
  for (int i = 0; i < M; i++) {
    string id_tmp; cin >> id_tmp;

    if (pairs.count(id_tmp)) {
      auto it = mp.find(pairs[id_tmp]);
      if (it != mp.end()) {
        mp.erase(it);
      } else {
        mp[id_tmp] = 1;
      }
    } else {
      mp[id_tmp] = 1;
    }
  }

  cout << mp.size() << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) cout << " ";
    cout << it->first;
  }
  return 0;
}
```

#### 1068 万绿丛中一点红(20)

对于计算机而言，颜色不过是像素点对应的一个 24 位的数值。现给定一幅分辨率为 M×N 的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，并且该点的颜色与其周围 8 个相邻像素的颜色差充分大。

#### 输入格式：

输入第一行给出三个正整数，分别是 M 和 N（≤ 1000），即图像的分辨率；以及 TOL，是所求像素点与相邻点的颜色差阈值，色差超过 TOL 的点才被考虑。随后 N 行，每行给出 M 个像素的颜色值，范围在 [0,2^24​​) 内。所有同行数字间用空格或 TAB 分开。

#### 输出格式：

在一行中按照 (x, y): color 的格式输出所求像素点的位置以及颜色值，其中位置 x 和 y 分别是该像素在图像矩阵中的列、行编号（从 1 开始编号）。如果这样的点不唯一，则输出 Not Unique；如果这样的点不存在，则输出 Not Exist。

#### 输入样例 1：

8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215

#### 输出样例 1：
(5, 3): 16711680

#### 输入样例 2：
4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0

#### 输出样例 2：
Not Unique

#### 输入样例 3：
3 3 5
1 2 3
3 4 5
5 6 7

#### 输出样例 3：
Not Exist

#### Solution:

这道题本身没什么难度, 特别的是, 由于题目表述含糊, 很多实际的判断条件要根据实际调试得到:

比如以下,
坑点:
> * 1, 充分大不意味着是最大, 只要是满足比TOL就行了。
> * 2, 需要每个相邻位置满足比TOL大, 不是一个, 也不是总和.
> * 3, 当只有一个颜色的时候, 只输出它, 不然case5通不过.
> * 4, 序号是从1开始的, 在最后print时候+1就好了.

我自己发现的一些问题, 
> * 1, Hash表来判断是否有颜色重复, 但是有2^24, 表很大。 memset的话超时, 因此不用memset, 让Node的构造函数自己去置cnt为0
> * 2, c++里面不要用move作为变量名去定义, 会冲突.
> * 3, struct后的;不要再忘记了。

```cpp
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
struct Node {
  int x;
  int y;
  int color;
  int cnt;
};   // bug01

const int MAXN = 16777300;     // pow(2, 24) + 50;  // bug02
const int MAXM = 1100;
Node dup_color[MAXN];
int a[MAXM][MAXM];

int grid[9][3] = {{-1, -1}, {-1, 0}, {-1, 1},        // bug03, 不能定义成move
                  {0 , -1},          {0, 1},
                  {1,  -1}, {1 , 0}, {1, 1}};

int main() {
  int M, N, TOL;
  scanf("%d %d %d", &M, &N, &TOL);
  // memset(dup_color, 0, sizeof(dup_color));  // memset导致空间不足case1,2,3..
  // memset(a, 0, sizeof(a));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int id; scanf("%d", &id);
      a[i][j] = id;
      if (dup_color[id].cnt == 0) {
        dup_color[id].color = id;
        dup_color[id].x = i; dup_color[id].y = j;
      }
      dup_color[id].cnt++;
    }
  }
  if (M == 1 && N == 1) {
    printf("(1, 1): %d\n", a[0][0]);
    return 0;
  }
  vector<Node> v; vector<Node> max_v;
  for (int i = 0; i < MAXN; i++) {
    if (dup_color[i].cnt == 1) {
      v.push_back(dup_color[i]);
    }
  }

  int max_d = 0;
  for (int iv = 0; iv < v.size(); iv++) {
    int i = v[iv].x, j = v[iv].y, color = v[iv].color;   // 难道是色彩均超过TOL?
    int delta = 0, ok = 1;
    for (int k = 0; k < 8; k++) {
      int x = i + grid[k][0], y = j + grid[k][1];
      if (0 <= x && x < M && 0 <= y && y < N) {
        int color_b = a[x][y];
        int dd = abs(color_b-color);
        if (dd > TOL) {                                  // 单个超过TOL
          delta += dd;                          // bug03:充分大,不是最大
        } else {
          ok = 0;
        }
      }
    }
    if (ok && delta != 0) {
      max_v.push_back(v[iv]);
    }
  }
  if (max_v.size() == 1) {
    printf("(%d, %d): %d\n", max_v[0].y+1, max_v[0].x+1, max_v[0].color);
  } else if (max_v.size() == 0) {
    printf("Not Exist\n");
  } else {
    printf("Not Unique\n");
  }
  return 0;
}
```

#### 1049 数列的片段和(20)

给定一个正数数列，我们可以从中截取任意的连续的几个数，称为片段。例如，给定数列 { 0.1, 0.2, 0.3, 0.4 }，我们有 (0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4) 这 10 个片段。

给定正整数数列，求出全部片段包含的所有的数之和。如本例中 10 个片段总和是 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0。

#### 输入格式：
输入第一行给出一个不超过10^5的正整数 N，表示数列中数的个数，第二行给出 N 个不超过 1.0 的正数，是数列中的数，其间以空格分隔。

#### 输出格式：
在一行中输出该序列所有片段包含的数之和，精确到小数点后 2 位。

#### 输入样例：
4
0.1 0.2 0.3 0.4

#### 输出样例：
5.00

#### Solution:
```
3 5 9 8 1

3    5    9    8    1     // n   个 1
35   59   98   81         // n-1 个 2
359  598  981             // n-2 个 3
3598 5981                 // ...
35981                     // 1   个n
```

可直接归纳得到每个位置数被算了多少次
```
3  5     9      8        1
5  4+4   3+3+3  2+2+2+2  1+1+1+1+1
```
i位置的数, 被计算了(n-i)*(i+1)次


得到代码:
```cpp
#include <cstdio>

int main() {
  int N; scanf("%d", &N);
  double sum = 0.0, tmp;
  for (int i = 0; i < N; i++) {
    scanf("%lf", &tmp);
    sum += tmp * (N-i)*(i+1);
  }
  printf("%.2lf", sum);
  return 0;
}
```
    


### 1051 复数乘法(15)

复数可以写成 (A+Bi) 的常规形式，其中 A 是实部，B 是虚部，i 是虚数单位，满足 i2=−1；也可以写成极坐标下的指数形式 (R×e(Pi))，其中 R 是复数模，P 是辐角，i 是虚数单位，其等价于三角形式 (R(cos(P)+isin(P))。

现给定两个复数的 R 和 P，要求输出两数乘积的常规形式。

#### 输入格式：
输入在一行中依次给出两个复数的R1, R2, P1, P2数字间以空格分隔。

#### 输出格式：

在一行中按照 A+Bi 的格式输出两数乘积的常规形式，实部和虚部均保留 2 位小数。注意：如果 B 是负数，则应该写成 A-|B|i 的形式。

#### 输入样例：
2.3 3.5 5.2 0.4

#### 输出样例：
-8.68-8.23i

#### Solution:

需要补充(复习)一下复数的运算法则:
```
(a+ib) + (c+id) = (a+c)+(b+d)i
(a+ib) - (c+id) = (a-c)+(b-d)i

复数的乘法:
(a+ib) * (c+id) = ac + adi + bci + bdi^2
                = ac + (ad+bc)i - bd
                = (ac-bd) + (ad+bc)i
```

这题里面给出的三角形式有问题, 给出的公式少了一个括号, 如果按照 `R*cos(P) + i*sin(p)`进行转换的话, 是有问题的.

因为正确的公式是 `R * (  cos(p) + i*sin(p) )`, 带入后可以得到最终的A+Bi

```
double A = r1 * r2 * cos(p1) * cos(p2) - r1 * r2 * sin(p1) * sin(p2);
double B = r1 * r2 * cos(p1) * sin(p2) + r1 * r2 * sin(p1) * cos(p2);
```


另外这题要注意的是, 要把`-0.00-0.00i ==转换成==> 0.00+0.00i`
如果A实际比0小, 但是很接近0, 不处理的话, 会出现-0.00的情况,
同理B是一样的, 但无论是什么情况, B都要带上i


```cpp
#include <cstdio>
#include <cmath>

int main() {
  double r1, p1, r2, p2;
  scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
  double A = r1 * r2 * cos(p1) * cos(p2) - r1 * r2 * sin(p1) * sin(p2);
  double B = r1 * r2 * cos(p1) * sin(p2) + r1 * r2 * sin(p1) * cos(p2);
  // A = -0.0005;
  // B = -0.0005;
  if (A + 0.005 >= 0 && A < 0) {
    printf("0.00");
  } else {
    printf("%.2lf", A);
  }

  if (B >= 0) {
    printf("+%.2lfi\n", B);
  } else if (B + 0.005 >= 0 && B < 0) {
    printf("+0.00i\n");    // 我并不知道有这种边界条件, 为什么0的时候还有i日
  } else {
    printf("%.2lfi\n", B);
  }

  return 0;
}
```


### 1040 有几个PAT(25)

字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。

现给定字符串，问一共可以形成多少个 PAT？
#### 输入格式：

输入只有一行，包含一个字符串，长度不超过10^5 ，只包含 P、A、T 三种字母。

#### 输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。

#### 输入样例：
APPAPT

#### 输出样例：
2


#### Solution:


先用最暴力的方法求解， 1,2AC, 后三个超时, 15分, 如何解决3sum问题?
```cpp
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; cin >> s;
  int n = s.length(), cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P') {
      for (int j = i+1; j < n; j++) {
        if (s[j] == 'A') {
          for (int k = j+1; k < n; k++) {
            if (s[k] == 'T') {
              cnt++;
            }
          }
        }
      }
    }
  }
  printf("%d\n", cnt ? cnt % 1000000007 : 0);
  return 0;
}
```


其实这道题目跟3sum问题还是有区别, 是属于观察特性, 总结规律的题目.

对于每一个A来说, 可以跟它组合个数是, `前面P的个数*后面T的个数.`

给出一种新的解法。
```cpp
// 计算每个A左边有几个P, 右边有几个T, 相乘
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; cin >> s;
  int sum = 0, n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      int left_P = 0, right_T = 0;
      int p = i-1, q = i+1;
      while (p >= 0) {
        if (s[p] == 'P') left_P++;
        p--;
      }
      while (q < n) {
        if (s[q] == 'T') right_T++;
        q++;
      }
      sum += left_P * right_T;
    }
  }
  printf("%d\n", sum);
  return 0;
}
// case3, 4, wrong
```

但这个复杂度, 仍然后很高, 因为找过的p又重新找了。

我在外公家用他的麻将牌模拟了一遍, 找出一种新解法。
既然是需要左边的P, 右边的T, 如果从左往右扫描的话, 先用一次扫描记录字符串所有T的个数`right_t`, 只要在下次扫描过程中, 用`left_p`记录从左边到A所有P的个数, 碰到T之后, `right_t`减1, 碰到A就左右相乘

坑点, 每次相加就需要取余数, 这里有点理不清楚, 但是先这样理解着吧。

```cpp
// 优化递推的做法,
// Time: O(n), Space:O(1)

#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; getline(cin, s);
  int sum = 0, cnt_p = 0, cnt_t = 0;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'T') cnt_t++;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P') {
      cnt_p++;
    } else if (s[i] == 'T') {
      cnt_t--;
    } else if (s[i] == 'A') {
      sum = (sum + cnt_p * cnt_t) % 1000000007;
    }
  }
  cout << sum << endl;
  return 0;
}
```



### 1069 微博转发抽奖(20)
1069. 微博转发抽奖(20)
小明 PAT 考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔 N 个人就发出一个红包。请你编写程序帮助他确定中奖名单。

#### 输入格式：
输入第一行给出三个正整数 M（≤ 1000）、N 和 S，分别是转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号（编号从 1 开始）。随后 M 行，顺序给出转发微博的网友的昵称（不超过 20 个字符、不包含空格回车的非空字符串）。

注意：可能有人转发多次，但不能中奖多次。所以如果处于当前中奖位置的网友已经中过奖，则跳过他顺次取下一位。

#### 输出格式：
按照输入的顺序输出中奖名单，每个昵称占一行。如果没有人中奖，则输出 Keep going...。

#### 输入样例 1：
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain

#### 输出样例 1：
PickMe
Imgonnawin!
TryAgainAgain

#### 输入样例 2：
2 3 5
Imgonnawin!
PickMe

#### 输出样例 2：
Keep going...


#### Solution:

注意需要先进行一次统一读入, 不能跳着读。
重复用map来判断, 用一个keep变量01来判断是否有中奖的同学.

```cpp
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, int> mp;
vector<string> v;
int main() {
  int M, N, S; cin >> M >> N >> S;
  int keep = 1;
  getchar();
  // debug, 读入问题
  for (int i = 0; i < M; i++) {
    string tmp_s; getline(cin, tmp_s);
    v.push_back(tmp_s);
  }
  for (int i = 0; i < M; i++) {
    if (i == S-1) {
      keep = 0;
      cout << v[i] << endl;
      mp[v[i]] = 1;
      int j = i + N;
      while (j <= M-1) {
        auto it = mp.find(v[j]);
        if (it != mp.end()) {
          j = j+1;
        } else {
          cout << v[j] << endl;
          mp[v[j]] = 1;
          j = j+N;
        }
      }
      break;
    }
  }
  if (keep) {
    cout << "Keep going..." << endl;
  }
  return 0;
}
```


### 1070 结绳(25)
tags, [PAT, 算法, 贪心, 规律]

给定一段一段的绳子，你需要把它们串成一条绳。每次串连的时候，是把两段绳子对折，再如下图所示套接在一起。这样得到的绳子又被当成是另一段绳子，可以再次对折去跟另一段绳子串连。每次串连后，原来两段绳子的长度就会减半。

rope.jpg

给定 N 段绳子的长度，你需要找出它们能串成的绳子的最大长度。

#### 输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出正整数 N (2≤N≤10^4)；第 2 行给出 N 个正整数，即原始绳段的长度，数字间以空格分隔。所有整数都不超过10^4。

#### 输出格式：
在一行中输出能够串成的绳子的最大长度。结果向下取整，即取为不超过最大长度的最近整数。

#### 输入样例：
8
10 15 12 3 4 13 1 15

#### 输出样例：
14

#### Solution:
主要要弄明白一个问题, 绳子怎么拼能够获得最大长度。

</span style="color:red">使得长度越长的绳子, 被折叠的次数越少; 尽可能让长度短的绳子折叠的更多(既然一定需要折叠的话).<span>

由于不会在数学上进行证明, 就先写完算法, 然后跟案例数据去匹配验证。

```cpp
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10050;
int a[MAXN];

int main() {
  int N, tmp; scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    a[i] = tmp;
  }
  sort(a, a+N);
  double sum = a[0];
  for (int i = 1; i < N; i++) {
    sum = (sum + a[i]) / 2;
  }
  printf("%d\n", (int)floor(sum));
  // printf("sum = %lf", sum);
  return 0;
}
```

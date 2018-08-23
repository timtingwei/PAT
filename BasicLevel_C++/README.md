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

### 1063 计算谱半径(20)

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

### 1064 朋友数(20)
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
    

### 1065 单身狗(25) 
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

### 1068. 万绿丛中一点红(20)

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

```cpp
debug:

Error1:
4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0
(3, 2): 3

// 充分大并不意味着最大..


3 3 5
1 2 3
3 4 5
5 6 7
Not Unique
*/


// case5
/*
1 1 2
2
*/


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

void test_printf_show(vector<Node> v) {
  for (int i = 0; i < v.size(); i++) {
    printf("x = %d, y = %d, color = %d\n", v[i].x, v[i].y, v[i].color);
  }
  printf("\n");
}

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
// test_printf_show(v);
  int max_d = 0;
  for (int iv = 0; iv < v.size(); iv++) {
    int i = v[iv].x, j = v[iv].y, color = v[iv].color;   // 难道是色彩均超过TOL?
    int delta = 0, ok = 1;
    for (int k = 0; k < 8; k++) {
      int x = i + grid[k][0], y = j + grid[k][1];
      if (0 <= x && x < M && 0 <= y && y < N) {
        int color_b = a[x][y];
// printf("delta = %d\n", abs(color_b-color));
        int dd = abs(color_b-color);
        if (dd > TOL) {                                  // 单个超过TOL
          delta += dd;                          // bug03:充分大,不是最大
        } else {
          ok = 0;
        }
      }
    }
// printf("\n");
    if (ok && delta != 0) {        // to?
// printf("delta total = %d\n", delta);
      max_v.push_back(v[iv]);
    }
    // if (delta > max_d) {
    //   max_d = delta; max_v.clear(); max_v.push_back(v[iv]);
    // } else if (delta == max_d) {
    //   max_v.push_back(v[iv]);
  }
// test_printf_show(max_v);
  if (max_v.size() == 1) {
    // printf("(%d, %d): %d\n", max_v[0].x+1, max_v[0].y+1, max_v[0].color);
    printf("(%d, %d): %d\n", max_v[0].y+1, max_v[0].x+1, max_v[0].color);
  } else if (max_v.size() == 0) {
    printf("Not Exist\n");
  } else {
    printf("Not Unique\n");
  }
  return 0;
}
```

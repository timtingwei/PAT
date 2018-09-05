## PAT-甲级

### 1048 Find Coins(25) -u

Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10^5coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤10^5, the total number of coins) and M (≤10
​3, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, print in one line the two face values V1 and V2(separated by a space) such that V1+V2=M and V1 ≤V2. If such a solution is not unique, output the one with the smallest V1
. If there is no solution, output No Solution instead.

#### Sample Input 1:
8 15
1 2 8 7 2 4 11 15

#### Sample Output 1:
4 11

#### Sample Input 2:
7 14
1 8 7 2 4 11 15

#### Sample Output 2:
No Solution


#### Solution:

排序后两个指针, 一个从头, 一个从尾, 向中间扫描, 两数相加是否能得到M

```cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, M, temp = 0; scanf("%d %d", &N, &M);
  vector<int> v;
  for (int i = 0; i < N; i++) {
    scanf("%d", &temp);
    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  int i = 0, j = N-1;
  while (i < j) {                  // case2
    if (v[i] + v[j] < M) i++;
    else if (v[i] + v[j] > M) j--;
    else if (v[i] + v[j] == M){
      printf("%d %d", v[i], v[j]);
      return 0;
    }
  }
  printf("No Solution\n");
  return 0;
}
```

### 1065 A+B and C (64bit)(20) -u

Given three integers A, B and C in [−2^63,2^63], you are supposed to tell whether A+B>C.

#### Input Specification:
The first line of the input gives the positive number of test cases, T (≤10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

#### Output Specification:
For each test case, output in one line Case #X: true if A+B>C, or Case #X: false otherwise, where X is the case number (starting from 1).

#### Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0

#### Sample Output:
Case #1: false
Case #2: true
Case #3: false

#### Solution:

case2 wrong error, 手误.

实现大整数的加减, 符号另外算。

```cpp
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Bign {
  int d[1005];
  int len;
  Bign() {
    memset(d, 0, sizeof(d));
    len = 0;
  }
};

Bign change(string s) {
  Bign a;
  a.len = s.length();
  for (int i = 0; i < a.len; i++) {
    a.d[i] = s[a.len-1-i] - '0';
  }
  return a;
}

Bign add(Bign a, Bign b) {
  Bign ans;
  int carry = 0;
  // for (int i = 0; i < a.len || i < a.len; i++) {
  for (int i = 0; i < a.len || i < b.len; i++) {      // case2, debug:01
    int temp = a.d[i] + b.d[i] + carry;
    ans.d[ans.len++] = temp % 10;
    carry = temp / 10;
  }
  if (carry) {
    ans.d[ans.len++] = carry;
  }
  return ans;
}

Bign sub(Bign a, Bign b) {
  Bign ans;

  for (int i = 0; i < a.len || i < b.len; i++) {
    if (a.d[i] < b.d[i]) {
      a.d[i+1]--;
      a.d[i] += 10;
    }
    ans.d[ans.len++] = a.d[i] - b.d[i];
  }
  while (ans.len - 1 >= 1 && ans.d[ans.len-1] == 0) {
    ans.len--;
  }
  return ans;
}

int compare(Bign a, Bign b) {
  if (a.len < b.len) return -1;
  else if (a.len > b.len) return 1;
  else {
    for (int i = 0; i < a.len; i++) {
      if (a.d[i] < b.d[i]) {
        return -1;
      } else if (a.d[i] > b.d[i]) {
        return 1;
      }
    }
    return 0;
  }
}

int main() {
  int T; cin >> T;
  for (int i = 0 ; i < T; i++) {
    // ..
    string a, b, c; cin >> a >> b >> c;
    int flag_a = 1, flag_b = 1, flag_c = 1, flag_add = 1;
    if (a[0] == '-') {
      flag_a = -1;
      a = a.substr(1, b.length()-1);
    }  // else flag_a = 1;
    if (b[0] == '-') {
      flag_b = -1;
      b = b.substr(1, b.length()-1);
    }
    if (c[0] == '-') {
      flag_c = -1;
      c = c.substr(1, c.length()-1);
    }
    Bign ba = change(a), bb = change(b), bc = change(c), rst_add;
    if (flag_a * flag_b == 1) {
      flag_add = flag_a;
      rst_add = add(ba, bb);
    } else {   // diff flag, compare
      int cmp_ab = compare(ba, bb);
      if (cmp_ab > 0) {
        flag_add = flag_a;
        rst_add = sub(ba, bb);
      } else if (cmp_ab < 0) {
        flag_add = flag_b;
        rst_add = sub(bb, ba);
      } else {  // -5 + 5 = 0
        flag_add = 1;
        rst_add = sub(ba, bb);
      }
    }
    string ans = "";
    if (flag_add < 0 && flag_c > 0) {
      ans = "false";
    } else if (flag_add > 0 && flag_c < 0) {
      ans = "true";
    } else if (flag_add < 0 && flag_c < 0) {
      ans = compare(rst_add, bc) < 0 ? "true" : "false";
    } else if (flag_add > 0 && flag_c > 0) {
      ans = compare(rst_add, bc) > 0 ? "true" : "false";
    }
    cout << "Case #" << i+1 << ": " << ans << endl;
  }
  return 0;
}
```

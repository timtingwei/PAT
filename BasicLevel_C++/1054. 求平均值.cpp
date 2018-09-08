// Copyright [2018] <mituh>
// 1054. 求平均值.cpp 01:32 -> 2:24(case 3) -> 没完成
/*
1054 求平均值（20 point(s)）

本题的基本要求非常简单：给定 N 个实数，计算它们的平均值。
但复杂的是有些输入数据可能是非法的。
一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位。   > double?
当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：

输入第一行给出正整数 N（≤100）。随后一行给出 N 个实数，数字间以一个空格分隔。

输出格式：

对每个非法输入，在一行中输出 ERROR: X is not a legal number，其中 X 是输入。
最后在一行中输出结果：The average of K numbers is Y，其中 K 是合法输入的个数，Y 是它们的平均值，精确到小数点后 2 位。
如果平均值无法计算，则用 Undefined 替换 Y。                        > K=0
如果 K 为 1，则输出 The average of 1 number is Y。

输入样例 1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35

输出样例 1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38

输入样例 2：
2
aaa -9999

输出样例 2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined

思路: 每次输入一个非法就报错, ERROR: X is not a legal number,
一个计数器K表示合法个数, 之后 k = 0, k >= 1, 两种, k > 1 +s
double aveg;

重点是我需要用string来自己定义一个"合法"double?
出现字母;  -> error;
出现两个及以上小数点; -> error;
if (出现一个小数点的情况) {
  判断小数点后是否超过两位 -> error
}
否则化成double d;
d+1000.0 < 0.005 || d-1000.0 > 0.005 ->error


case 3: wrong error
2
aaa -12-

// 除了小数点, +-号外, 其他都是纯数字
if (s[j]是数字) {
} else {
  if (是+or- && j == 0) {
  } else { return 0;}
  if (小数点 && 出现一次) {
  } else 
}

int is_ok(string s, double *d) {
  int p1 = -1, p2 = -1;    // p1+-号, p2., 出现一次
  while (j < s.length()) {
    if (isalpha(s[j])) || ( (s[j] == '+' || s[j] == '-') && (p1 == -1) )  || (s[j] == '.' && p2++ == -1) {               // 可以的情况
      continue;
    } return 0;
  }
  // 存在小数点, 
  if (p2 != -1) {
    for (j = 0; s[j] == '.'; j++) {p2 = j+1}    // 重新找一遍小数点所在的索引
    if ((s.length()-p2-1 > 2 || s.length()-p2-1 == 0))
      return 0;              // 小数点超过两位情况, 或者小数点后无数字仍算error 
  }
  // 转化成double类型
  string::size_type sz;
  *d = stod(s, &sz);
  // 判断double的范围
  if ((*d)+1000.0 < 0.005 || (*d)-1000.0 > 0.005) {
    cout << "[-1000, 1000]" << endl;
    return 0;
  }
  return 1;
}

4
-.3. 2.1.2 -2.2 3-3 .2.3

ERROR: -.3. is not a legal number
ERROR: 2.1.2 is not a legal number
ERROR: 3-3 is not a legal number
The average of 1 number is -2.20


5
-3. 2.1.2 -2.2 3-3 23.
ERROR: 2.1.2 is not a legal number
ERROR: 3-3 is not a legal number
The average of 3 numbers is 5.93

不能以.开头
将k改成double?
仍旧不行...
 */

/*
#include <iostream>
#include <cctype>
#include <cstdio>
#include <string>
using namespace std;

int is_ok(string s, double *d) {
  int p1 = -1, p2 = -1;    // p1+-号, p2., 出现一次
  int j = 0;
  while (j < s.length()) {
    if ((isdigit(s[j])) ||
        ( ((s[j] == '+' || s[j] == '-')) && (j == 0) && (p1++ == -1) )
        || (s[j] == '.' && p2++ == -1 && j != 0)) {   // 可以的情况
      j++;
    } else {
// cout << "big error" << endl;
      return 0;
    }
  }
  // 存在小数点,
  if (p2 != -1) {
    for (j = 0; s[j] != '.'; j++) {p2 = j+1;}    // 重新找一遍小数点所在的索引
// cout << "p2 = " << p2 << endl;
    if (s.length()-p2-1 > 2)  // s.length()-p2-1 == 0
      return 0;              // 小数点超过两位情况, 或者小数点后无数字仍算error
  }
// cout << s << endl;
  // 转化成double类型
  string::size_type sz;
  *d = stod(s, &sz);
// cout << "*d = " << *d << endl;
  // 判断double的范围
  if ((*d)+1000.0 < 0.005 || (*d)-1000.0 > 0.005) {
// cout << "[-1000, 1000]" << endl;
    return 0;
  }
  return 1;
}

int main() {
  int n; double aveg = 0.0, k = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string t; double d;
    cin >> t;
    if (is_ok(t, &d)) {
      aveg += d;
      k++;
    } else {
      cout << "ERROR: " << t << " is not a legal number" << endl;
    }
  }
  if (k - 0 > 0.005) {
    cout << "The average of " << k << " number";
    if (k-1 > 0.005) cout << "s";
    printf(" is %.2f\n", aveg / k);
  } else {
    printf("The average of 0 numbers is Undefined\n");
  }


  return 0;
}
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
  int N; cin >> N;
  int cnt = 0; double sum = 0;
  while (N--) {
    string s; cin >> s;
    int ok = 1, point_cnt = 0, pt_pos = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '-' || s[i] == '+') {
        if (i != 0) { ok = 0; break;}
      }

      if (s[i] == '.') {
        pt_pos = i;
        point_cnt++;
        if (point_cnt > 1) { ok = 0; break;}
      }

      if (isalpha(s[i])) {ok = 0; break;}
    }
    if (ok && (!point_cnt)) {
      double d = stod(s);
      if (d+1000 < 0.005 || d-1000 > 0.005) ok = 0;
    }

    if (ok && point_cnt) {
      int len = s.length() - pt_pos - 1;
      if (len > 2) ok = 0;
    }

    if (!ok) {
      cout << "ERROR: " << s <<" is not a legal number" << endl;
    } else {
      sum += stod(s);
      cnt++;
    }
  }
  if (!cnt) {
    cout << "The average of 0 numbers is Undefined" << endl;
  } else if (cnt == 1) {
    printf("The average of 1 number is %.2lf\n", sum);
  } else {
    printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
  }
  return 0;
}
*/


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


// 重新写了一遍
#include <cstdio>
#include <cstring>   // strlen

int db_equal(double d1, double d2) {
  return -0.0005 < d1-d2 && d1-d2 < 0.0005;
}

int main() {
  char a[100], b[100];
  int N, cnt = 0; scanf("%d", &N);
  double sum = 0;
  while (N--) {
    scanf("%s", a);
    double temp = 0.0;
    sscanf(a, "%lf", &temp);   // %
    sprintf(b, "%.2lf", temp);
// printf("a = %s, b = %s\n", a, b);
    int flag = 1;
    for (int i = 0; i < strlen(a); i++) {
      if (a[i] != b[i]) flag = 0;
    }
    // 规避的写法
    if (!flag || temp < -1000 || temp > 1000) {
      printf("ERROR: %s is not a legal number\n", a);
    } else {
      sum += temp;
      cnt++;
    }
    /*
    // 浮点数误差的写法
    if (flag && (-1000 < temp || db_equal(temp, -1000)) && (temp < 1000 || db_equal(temp, 1000))) {
      sum += temp;
      cnt++;
    } else {
      printf("ERROR: %s is not a legal number\n", a);
    }
    */
  }
  if (cnt == 0) {
    printf("The average of 0 numbers is Undefined\n");
  } else if (cnt == 1) {
    printf("The average of 1 number is %.2lf\n", sum);
  } else {
    printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
  }

  return 0;
}

// Copyright [2018] <mituh>
// 1017. A除以B（20).cpp    // 3:25  (30) 4:00 -> 35min
/*
  思路:
  1, 用数组储存大整数, 模拟大整数除以1位数
  2, 用C++字符串读取, 模拟手动除法, 首位整数 / B, 如果得到不是0就输出, 余数*10+下一位,
  

本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。


123456789050987654321 7

输出样例：
17636684150141093474 3
*/

/*
#include <cstdio>
#include <cstring>
using namespace std;

char bs[1050];
int ans[1050];
int cnt = 0;

int main() {
  int b, q = 0, r = 0;
  scanf("%s %d", bs, &b);
  int len = strlen(bs);
  for (int i = 0; i < len; i++) {
    int x = r * 10 + bs[i] - '0';
    q = x / b;
    r = x % b;
    if (i == 0 && q == 0) continue;
    ans[cnt++] = q;
  }
  if (cnt == 0 && ans[0] == 0) printf("0");
  for (int i = 0; i < cnt; i++) { printf("%d", ans[i]); }
  printf(" %d\n", r);
  return 0;
}

*/

#include <iostream>
#include <string>
using namespace std;


int main() {
  string a; int b;
  cin >> a >> b;
  int len = a.length();
  int f = (a[0] - '0') / b;
  if ((f != 0 && len > 1)|| len == 1)
    cout << f;
  int temp = (a[0] - '0') % b;
  for (int i = 1; i < len; i++) {
    f = (temp * 10 + a[i] - '0') / b;
    cout << f;
    temp = (temp * 10 + a[i] - '0') % b;
  }
  cout << " " << temp << "\n";
  return 0;
}

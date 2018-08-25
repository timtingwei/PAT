// Copyright [2018] <mituh>
// 1074. 宇宙无敌加法器(20).cpp    05:27->06:17, debug3个case
/*
1074 宇宙无敌加法器(20)

地球人习惯使用十进制数，并且默认一个数字的每一位都是十进制的。而在 PAT 星人开挂的世界里，每个数字的每一位都是不同进制的，这种神奇的数字称为“PAT数”。每个 PAT 星人都必须熟记各位数字的进制表，例如“……0527”就表示最低位是 7 进制数、第 2 位是 2 进制数、第 3 位是 5 进制数、第 4 位是 10 进制数，等等。每一位的进制 d 或者是 0（表示十进制）、或者是 [2，9] 区间内的整数。理论上这个进制表应该包含无穷多位数字，但从实际应用出发，PAT 星人通常只需要记住前 20 位就够用了，以后各位默认为 10 进制。

在这样的数字系统中，即使是简单的加法运算也变得不简单。例如对应进制表“0527”，该如何计算“6203 + 415”呢？我们得首先计算最低位：3 + 5 = 8；因为最低位是 7 进制的，所以我们得到 1 和 1 个进位。第 2 位是：0 + 1 + 1（进位）= 2；因为此位是 2 进制的，所以我们得到 0 和 1 个进位。第 3 位是：2 + 4 + 1（进位）= 7；因为此位是 5 进制的，所以我们得到 2 和 1 个进位。第 4 位是：6 + 1（进位）= 7；因为此位是 10 进制的，所以我们就得到 7。最后我们得到：6203 + 415 = 7201。

输入格式：
输入首先在第一行给出一个 N 位的进制表（0 < N ≤ 20），以回车结束。 随后两行，每行给出一个不超过 N 位的非负的 PAT 数。

输出格式：
在一行中输出两个 PAT 数之和。

输入样例：
30527
06203
415

输出样例：
7201
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

  string T, S1, S2; cin >> T >> S1 >> S2;
  int n = T.length();
  S1.insert(0, n - S1.length(), '0');
  S2.insert(0, n - S2.length(), '0');
  stack<int> stk; int more = 0;

  for (int i = n-1; i >= 0; i--) {
    int b = T[i] == '0' ? 10 : T[i] - '0';
    int d  = S1[i]-'0' + S2[i]-'0' + more;
    int digit = (d) ? (d) % b : 0;
    more = d / b;
    stk.push(digit);
  }
  if (more) stk.push(more);           // case1, 3
  int flag = 0, flag_z = 1;
  while (!stk.empty()) {
    if (!flag) {
      if (stk.top() == 0) {
        stk.pop();
      } else {
        flag = 1;
        flag_z = 0;                   // case5, zero
      }
    } else {
      printf("%d", stk.top());
      stk.pop();
    }
  }
  if (flag_z) printf("0");
  printf("\n");
  return 0;
}

// 1, 3wrong
/*
2
5
7
0
*/

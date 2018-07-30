// Copyright [2018] <mituh>
// 1018. 锤子剪刀布 (20).cpp    // 4:03  (30)
/*
  现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
  思路: 只记录甲的胜负, 计算出乙胜负平; 六种排列组合; 三个计数器放在数组中, 用 ?:判断哪个位置计数最高

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：

10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：

5 3 2
2 3 5
B B
*/
#include <iostream>
#include <cstdio>
using namespace std;

const char str[4] = {'B', 'C', 'J'};

int main () {
  int T;
  int win = 0, fail = 0;   // 只记录甲的胜负
  int winjia[3] = {0}, winyi[3] = {0};
  cin >> T;
  int ct = T;
  while (T--) {
    char a, b;
    cin >> a >> b;
    // 六种排列组合
    if (a == 'B' && b == 'C') {
      win++; winjia[0]++;
    } else if (a == 'B' && b == 'J') {
      fail++; winyi[2]++;
    } else if (a == 'C' && b == 'B') {
      fail++; winyi[0]++;
    } else if (a == 'C' && b == 'J') {
      win++; winjia[1]++;
    } else if (a == 'J' && b == 'B') {
      win++; winjia[2]++;
    } else if (a == 'J' && b == 'C') {
      fail++; winyi[1]++;
    }
  }
  printf("%d %d %d\n", win, ct-win-fail, fail);
  printf("%d %d %d\n", fail, ct-win-fail, win);
  int jiamax = (winjia[0] >= winjia[1]) ? 0 : 1;
  jiamax = (winjia[jiamax] >= winjia[2]) ? jiamax : 2;
  int yimax = (winyi[0] >= winyi[1]) ? 0 : 1;
  yimax = (winyi[yimax] >= winyi[2]) ? yimax : 2;
  printf("%c", str[jiamax]);
  printf(" %c\n", str[yimax]);

  return 0;
}

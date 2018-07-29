// Copyright [2018] <mituh>
// 1018. 锤子剪刀布 (20).cpp    // 4:03  (30)  4:57 -> 54min 出篓子了..
/*
  现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
  思路: 用数组储存胜, 平, 负次数, struct定义两个人各自的成绩, 谁胜了修改变量, 对最大次数手势判断

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
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct score {
  int w = 0, f = 0, e = 0;    // 胜负平
  int C = 0, J = 0, B = 0;    // 胜的时候出的手势
};

vector<int> x;
// const char motion[4] = "CJB";
const char motion[4] = "BCJ";
char getMax(int a, int b, int c) {
  // a,b,c谁最大, 返回0,1,2; 并列返回字典序列
  x.clear();
  int m;
  m = max(a, b); m = max(m, c);
// printf("%d %d %d m=%d\n", a, b, c, m);
  if (m == a) x.push_back(0);
  if (m == b) x.push_back(1);
  if (m == c) x.push_back(2);
  sort(x.begin(), x.end());
// printf("x0=%d\n", x[0]);
  return motion[x[0]];
}


char a[2], b[2];

int main () {
  int T;
  score jia, yi;
  if (scanf("%d", &T) == 1 && T) {
    while (T--) {
      // char a, b;
      scanf("%s %s", a, b);
// printf("%s %s\n", a, b);
// /*
      if (a[0] == 'J') {
        if (b[0] == 'J') { jia.e++; yi.e++; }    // 平局
        else if (b[0] == 'C') { jia.f++; yi.w++; yi.C++; }  // 乙胜
        else if (b[0] == 'B') { jia.w++; yi.f++; jia.J++; }  // jia胜
      } else if (a[0] == 'C') {
        if (b[0] == 'C') { jia.e++; yi.e++; }    // 平局
        else if (b[0] == 'J') { jia.w++; yi.f++; jia.C++; }  // jia胜
        else if (b[0] == 'B') { yi.w++; jia.f++; yi.B++; }  // yi胜
      } else if (a[0] == 'B') {
        if (b[0] == 'B') { jia.e++; yi.e++; }    // 平局
        else if (b[0] == 'J') { jia.f++; yi.w++; yi.J++; }  // yi胜
        else if (b[0] == 'C') { yi.f++; jia.w++; jia.B++; }  // jia胜
      }
// */
    }
    printf("%d %d %d\n", jia.w, jia.e, jia.f);
    printf("%d %d %d\n", yi.w, yi.e, yi.f);
    printf("%c", getMax(jia.B, jia.C, jia.J));
    printf(" %c\n", getMax(yi.B, yi.C, yi.J));
  }



  return 0;
}


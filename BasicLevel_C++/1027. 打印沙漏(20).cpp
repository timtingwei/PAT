// copyright [2018] <mituh>
/* 1027. 打印沙漏(20).cpp       11:20 -> 12:22 ....1h
1027 打印沙漏(20)（20 point(s)）

本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式：

输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

输出格式：

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例：

19 *
输出样例：

*****
 ***
  *
 ***
*****
2
*/


// 计算前45项奇数之和

#include <stdio.h>

int main() {
  int n; char ch;
  scanf("%d %c", &n, &ch);
  int i, j = 1, sum = 1, p;
  for (i = 0; i < 31; i++) {
    j += 2;
    sum += j*2;
    if (sum > n) {p = n - (sum-(j*2)); break;}
  }
  int line = i--;
  // 上打印line行, 下打印line-1行
  for (int i = line; i >= 0; i--) {
    for (int j = 0; j < line-i; j++) printf(" ");
    for (int j = 0; j < 1+i*2; j++) printf("%c", ch);
    printf("\n");
  }
  for (int i = 1; i <= line; i++) {
    for (int j = 0; j < line-i; j++)  printf(" ");
    for (int j = 0; j < 1+i*2; j++) printf("%c", ch);
    printf("\n");
  }
  printf("%d\n", p);

  return 0;
}

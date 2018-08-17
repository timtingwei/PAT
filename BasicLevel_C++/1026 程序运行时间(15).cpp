// copyright [2018] <mituh>
/* 1026 程序运行时间(15).cpp  1033, 11:00 fail
1026 程序运行时间(15)（15 point(s)）

要获得一个C语言程序的运行时间，常用的方法是调用头文件time.h，其中提供了clock()函数，可以捕捉从程序开始运行到clock()被调用时所耗费的时间。这个时间单位是clock tick，即“时钟打点”。
同时还有一个常数CLK_TCK，给出了机器时钟每秒所走的时钟打点数。
于是为了获得一个函数f的运行时间，我们只要

在调用f之前先调用clock()，获得一个时钟打点数C1；
在f执行完成后再调用clock()，获得另一个时钟打点数C2；
两次获得的时钟打点数之差(C2-C1)就是f运行所消耗的时钟打点数，
再除以常数CLK_TCK，就得到了以秒为单位的运行时间。

这里不妨简单假设常数CLK_TCK为100。现给定被测函数前后两次获得的时钟打点数，请你给出被测函数运行的时间。

输入格式：

输入在一行中顺序给出2个整数C1和C2。注意两次获得的时钟打点数肯定不相同，即C1 < C2，并且取值在[0, 10^7^]。

输出格式：

在一行中输出被测函数运行的时间。运行时间必须按照“hh:mm:ss”（即2位的“时:分:秒”）格式输出；不足1秒的时间四舍五入到秒。

输入样例：

123 4577973
输出样例：

12:42:59

思路: 根据打点数之差, CLK得到秒, 将秒转化为hh:mm:ss, 三次除以60(错误)
case 1通不过

清晰的思路: 计算得到总共多少秒, hh:总秒数/3600取整, mm:剩余秒数/60取整, ss:剩余秒数四舍五入
*/

#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double c1, c2;
  scanf("%lf %lf", &c1, &c2);
  double delta = (c2 - c1) / 100;

  int hh, mm, ss;
  hh = delta / 3600;
  delta -= hh * 3600;
  mm = delta / 60;
  delta -= mm * 60;
  ss = floor(delta + 0.5);
  printf("%02d:%02d:%02d\n", hh, mm, ss);
  return 0;
}

/*
int tm[3];
const int CT = 100;

int main() {
  double c1, c2;
  scanf("%lf %lf", &c1, &c2);
  double s = (c2 - c1) / CT;
  cout << s << endl;
  int hh, mm, ss;
  hh = s/3600;
  mm = (s/3600-hh)*3600/60;
  ss = floor(((s/3600-hh)*3600/60 - mm) * 60 + 0.5);
  printf("%02d:%02d:%02d\n", hh, mm, ss);
  return 0;
}
*/

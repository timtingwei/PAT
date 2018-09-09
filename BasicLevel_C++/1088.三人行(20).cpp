// Copyright [2018] <mituh>
// 1088.三人行(20).cpp
/*
1088 三人行(20)

子曰：“三人行，必有我师焉。择其善者而从之，其不善者而改之。”

本题给定甲、乙、丙三个人的能力值关系为：甲的能力值确定是 2 位正整数；把甲的能力值的 2 个数字调换位置就是乙的能力值；甲乙两人能力差是丙的能力值的 X 倍；乙的能力值是丙的 Y 倍。请你指出谁比你强应“从之”，谁比你弱应“改之”。

输入格式：
输入在一行中给出三个数，依次为：M（你自己的能力值）、X 和 Y。三个数字均为不超过 1000 的正整数。

输出格式：
在一行中首先输出甲的能力值，随后依次输出甲、乙、丙三人与你的关系：如果其比你强，输出 Cong；平等则输出 Ping；比你弱则输出 Gai。其间以 1 个空格分隔，行首尾不得有多余空格。

注意：如果解不唯一，则以甲的最大解为准进行判断；如果解不存在，则输出 No Solution。

输入样例 1：
48 3 7

输出样例 1：
48 Ping Cong Gai

输入样例 2：
48 11 6

输出样例 2：
No Solution
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int db_equal(double d1, double d2) {
  return -0.0005 < d1-d2 && d1-d2 < 0.0005;
}

int main() {
  int m, x, y; cin >> m >> x >> y;
  string strs[4] = {"Cong", "Ping", "Gai"};
  int jia, yi, find = 0;
  double bing;
  for (int i = 99; i >= 10; i--) {
    jia = i;
    int second = jia % 10, first = jia/10%10;
    yi = second*10+first;
    int delta = (jia > yi) ? jia-yi : yi-jia;
    double bing = delta*1.0 / x;
    // if (!db_equal(bing, floor(bing+0.5))) continue;   // 0.5?
    if (db_equal(0, bing*y-yi)) {
      int a = jia >= m  ? jia > m ? 0:1:2,
          b = yi >= m   ? yi > m  ? 0:1:2,
          c = bing < m  ? 2 : bing > m ? 0:1;
          // c = tmp_b >= m ? tmp_ > m ? 0:1:2;
      cout << jia << " " << strs[a] << " " << strs[b] << " " << strs[c] << endl;
      find = 1;
      break;
    }
  }
  if (!find) {
    cout << "No Solution" << endl;
  }
  return 0;
}

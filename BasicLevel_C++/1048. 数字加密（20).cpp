// Copyright [2018] <mituh>
// 1048. 数字加密（20).cpp      07:02 -> 07:21 -> 07:31(2,5) -> 07:53
/*
1048 数字加密（20 point(s)）

本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

输入格式：

输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。

输入样例：

1234567 368782971
输出样例：

3695Q8118
*/

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string A, B; cin >> A >> B;
  int M = A.length(), N = B.length();
  string s, tmp_s;
  for (int i = 0; i < M && i < N; i++) {
    int x;
    int a = A[M-1-i] - '0', b = B[N-1-i] - '0';
    
    if ((i+1)%2) {
      x = (a+b) % 13;
      if (x == 10) tmp_s = 'J';
      else if (x == 11) tmp_s = 'Q';
      else if (x == 12) tmp_s = 'K';
      else {
        tmp_s = x+'0';
      }
      
    } else {
      x = b - a;
      if (x < 0) x += 10;
      tmp_s = to_string(x);
      // tmp_s = x + '0';
    }
    s += tmp_s;
  }

  reverse(s.begin(), s.end());
  if (N > M) {
    tmp_s = B.substr(0, N-M);
    s.insert(0, tmp_s);
  }
  cout << s << endl;
  return 0;
}

// case 2, 5 wrong answer
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string A, B; cin >> A >> B;
  int M = A.length(), N = B.length();
  if (N < M) {
    B.insert(0, M-N, '0');
    N = M;
  } else if (N > M) {
    A.insert(0, N-M, '0');
    M = N;
  }
  string s, tmp_s;
  for (int i = 0; i < M; i++) {
    int x;
    int a = A[M-1-i] - '0', b = B[N-1-i] - '0';

    if ((i+1)%2) {
      x = (a+b) % 13;
      if (x == 10) {
        tmp_s = 'J';
      } else if (x == 11) {
        tmp_s = 'Q';
      } else if (x == 12) {
        tmp_s = 'K';
      } else {
        tmp_s = x + '0';
      }

    } else {
      x = b - a;
      if (x < 0) x += 10;
      tmp_s = x + '0';
    }
    s += tmp_s;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
  return 0;
}

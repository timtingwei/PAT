// Copyright [2018] <mituh>
// 1024-palindromic-number-25.cpp    02:55, 03:20, 03:38 = 43min
/*
1024 Palindromic Number(25)

A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and K, where N (≤10^10) is the initial numer and K (≤100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:
For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3

Sample Output 1:
484
2

Sample Input 2:
69 3

Sample Output 2:
1353
3
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct Bign {
  int d[1005];
  int len;
  Bign() {
    memset(d, 0, sizeof(d));
    len = 0;
  }
};

Bign add(Bign a, Bign b) {
  Bign ans;
  int carry = 0;
  for (int i = 0; i < a.len || i < b.len; i++) {
    int tmp = a.d[i] + b.d[i] + carry;
    ans.d[ans.len++] = tmp % 10;
    carry = tmp / 10;
  }
  if (carry) {
    ans.d[ans.len++] = carry;
  }
  return ans;
}

Bign stringToBign(string s) {
  Bign ans;
  ans.len = s.length();
  for (int i = 0; i < ans.len; i++) {
    ans.d[i] = s[ans.len-1-i]-'0';    // bug01
  }
  return ans;
}

string bignToString(Bign a) {
  string s = "";
  for (int i = a.len-1; i >= 0; i--) {
    s += to_string(a.d[i]);
  }
  return s;
}

bool is_p(string s) {
  int n = s.length();
  int i = 0, j = n-1;
  while (i <= j) {
    if (s[i] != s[j]) return false;
    i++; j--;
  }
  return true;
}

int main() {
  string s; int step_max;
  cin >> s >> step_max;
  int step = 0;
  while (!is_p(s) && step < step_max) {
    string temp_s = s;
    reverse(temp_s.begin(), temp_s.end());
    Bign a = stringToBign(s), b = stringToBign(temp_s);
    s = bignToString(add(a, b));
    step++;
  }
  cout << s << "\n" << step << endl;
  return 0;
}


/*
just for test
int main() {
  string s1 = "12", s2 = "2222";
  Bign a = stringToBign(s1), b = stringToBign(s2);
  cout << bignToString(a) << endl;
  cout << bignToString(b) << endl;
  cout << bignToString(add(a, b)) << endl;
  return 0;
}
*/

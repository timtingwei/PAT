## PAT-甲级

### 1015 Reversible Primes(20) -uw

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<10^5) and D (1<D≤10), you are supposed to tell if N is a reversible prime with radix D.

#### Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

#### Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

#### Sample Input:
73 10
23 2
23 10
-2

#### Sample Output:
Yes
Yes
No

#### Solution:

难点不在于判断素数, 而是理解不了进制转换。
先按d进制逆转, 将逆转后的数转成10进制, 判断素数.

d进制逆转属于中间过程, 用一个数组存放.

```cpp
#include <cstdio>
#include <cmath>
using namespace std;


// is_prime改进
bool is_prime(int a) {
  if (a <= 1) return false;
  int sqr =  int(sqrt(a * 1.0));
  for (int i = 2; i <= sqr; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, d, flag = 0;
  while (scanf("%d %d", &n, &d) != EOF) {
    if (n < 0) break;
    int ok = 0;
    if (is_prime(n)) {
      // reverse a num
      int len = 0, arr[6];
      while (n) {
        arr[len++] = n % d;
        n /= d;
      }
      for (int i = 0; i < len; i++) {
        n = n * d + arr[i];
      }
      // judge
      if (is_prime(n)) {
        ok = 1;
      }
    }

    if (flag) printf("\n");
    ok ? printf("Yes") : printf("No");
    flag = 1;
  }
  return 0;
}
```

// 因为不是很理解D的作用, 这样做只能过case2, 3, 14错

/*
// 原先的求素数
int is_prime(int a) {
  if (a < 2) return 0;
  if (a == 2) return 1;
  int sq = sqrt(a);
  for (int i = 2; i <= sq; i++) {
    if (a % i == 0) return 0;
  }
  return 1;
}
*/

    
### 1024 Palindromic Number(25) -uw

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

#### Solution:

```cpp
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
```


### 1035 Password(20) -uw

To prepare for PAT, the judge sometimes has to generate random passwords for the users. The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one) from l (L in lowercase), or 0 (zero) from O (o in uppercase). One solution is to replace 1 (one) by @, 0 (zero) by %, l by L, and O by o. Now it is your job to write a program to check the accounts generated by the judge, and to help the juge modify the confusing passwords.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N (≤1000), followed by N lines of accounts. Each account consists of a user name and a password, both are strings of no more than 10 characters with no space.

Output Specification:
For each test case, first print the number M of accounts that have been modified, then print in the following M lines the modified accounts info, that is, the user names and the corresponding modified passwords. The accounts must be printed in the same order as they are read in. If no account is modified, print in one line There are N accounts and no account is modified where N is the total number of accounts. However, if N is one, you must print There is 1 account and no account is modified instead.

Sample Input 1:
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa

Sample Output 1:
2
Team000002 RLsp%dfa
Team000001 R@spodfa

Sample Input 2:
1
team110 abcdefg332

Sample Output 2:
There is 1 account and no account is modified

Sample Input 3:
2
team110 abcdefg222
team220 abcdefg333

Sample Output 3:
There are 2 accounts and no account is modified


```cpp
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
  char name[11];
  char password[11];
};

int main() {
  int N; scanf("%d", &N);
  unordered_map<char, char> mp;
  mp['1'] = '@'; mp['0'] = '%'; mp['l'] = 'L'; mp['O'] = 'o';
  vector<Node> v;
  for (int i = 0; i < N; i++) {
    Node node;
    scanf("%s %s", node.name, node.password);
    int modified = 0;
    for (int j = 0; j < strlen(node.password); j++) {
      auto it = mp.find(node.password[j]);
      if (it != mp.end()) {
        node.password[j] = it->second;
        modified = 1;
      }
    }
    if (modified) {
      v.push_back(node);
    }
  }

  if (v.size() != 0) {
    printf("%lu\n", v.size());
    for (int i = 0; i < v.size(); i++) {
      printf("%s %s\n", v[i].name, v[i].password);
    }
  } else {
    if (N == 1) {
      printf("There is 1 account and no account is modified\n");
    } else {
      printf("There are %d accounts and no account is modified\n", N);
    }
  }

  return 0;
}
```

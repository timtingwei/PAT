## PAT-甲级

### 1005 Spell It Right(20) -u

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

#### Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (≤10
​100
​​ ).

#### Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

#### Sample Input:
12345

#### Sample Output:
one five


#### Solution:
```cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

char num[200];
int main() {
  string dict[10] = {"zero", "one", "two", "three", "four",
                   "five", "six", "seven", "eight", "nine"};
  scanf("%s", num);
  int sum = 0;
  for (int i = 0; i < strlen(num); i++) {
    sum += num[i]-'0';
  }
  string s = to_string(sum); int flag = 0;
  for (char ch : s) {
    if (flag) cout << " ";
    cout << dict[ch - '0'];
    flag = 1;
  }
  return 0;
}
```

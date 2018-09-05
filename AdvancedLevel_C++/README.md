## PAT-甲级

### 1048 Find Coins(25) -u

Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10^5coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤10^5, the total number of coins) and M (≤10
​3, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, print in one line the two face values V1 and V2(separated by a space) such that V1+V2=M and V1 ≤V2. If such a solution is not unique, output the one with the smallest V1
. If there is no solution, output No Solution instead.

#### Sample Input 1:
8 15
1 2 8 7 2 4 11 15

#### Sample Output 1:
4 11

#### Sample Input 2:
7 14
1 8 7 2 4 11 15

#### Sample Output 2:
No Solution


#### Solution:

排序后两个指针, 一个从头, 一个从尾, 向中间扫描, 两数相加是否能得到M

```cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, M, temp = 0; scanf("%d %d", &N, &M);
  vector<int> v;
  for (int i = 0; i < N; i++) {
    scanf("%d", &temp);
    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  int i = 0, j = N-1;
  while (i < j) {                  // case2
    if (v[i] + v[j] < M) i++;
    else if (v[i] + v[j] > M) j--;
    else if (v[i] + v[j] == M){
      printf("%d %d", v[i], v[j]);
      return 0;
    }
  }
  printf("No Solution\n");
  return 0;
}
```

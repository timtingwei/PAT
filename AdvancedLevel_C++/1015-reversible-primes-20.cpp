// Copyright [2018] <mituh>
// 1015-reversible-primes-20.cpp    // 12:42 -> 1:11 -> 13:36(case1,4)
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int is_prime(int a) {
  if (a < 2) return 0;
  if (a == 2) return 1;
  int sq = sqrt(a);
  for (int i = 2; i <= sq; i++) {
    if (a % i == 0) return 0;
  }
  return 1;
}


int main() {
  int N, D, flag = 0;
  for (;;) {
    scanf("%d", &N);
    if (N < 0) break;
    scanf("%d", &D);
    int ok = 0;
    if (is_prime(N)) {
      // reverse a num
      queue<int> nums;
      while (N) {
        nums.push(N % D);
        N /= D;
      }
      int R = 0;
      while (!nums.empty()) {
        R = R*10 + nums.front();
        nums.pop();
      }

      // judge
      if (is_prime(R)) {
        ok = 1;
      }
    }
    if (flag) printf("\n");
    ok ? printf("Yes") : printf("No");
    flag = 1;
  }
  return 0;
}

// 因为不是很理解D的作用, 这样做只能过case2, 3, 14错

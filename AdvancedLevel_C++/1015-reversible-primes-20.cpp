// Copyright [2018] <mituh>
// 1015-reversible-primes-20.cpp    12:42 -> 1:11
/*
1015 Reversible Primes(20)

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<10^5) and D (1<D≤10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

Sample Input:
73 10
23 2
23 10
-2

Sample Output:
Yes
Yes
No
*/

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

// copyright [2018] <mituh>
// 1007. 素数对猜想.cpp
/*
  思路: 求出N < 10e5, 所有素数, 后一个-前一个=2, 则计数+1 
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
int prime_a[100000];

int is_prime(int n) {
  int s = floor(sqrt(n) + 0.5);
  int ok = 1;
  for (int i = 2; i <= s; i++) {  // 判断素数开根号后, 要循环到进位后的数 25->5
    if (n % i == 0) {ok = 0; return 0;}
  }
  if (ok) return 1;
  
  return 0;
}

int main() {
  int n, cnt = 0, ans = 0;
  if (scanf("%d", &n) == 1) {
    prime_a[cnt++] = 2;
    for (int i = 3; i <= n; i++) {
      if (is_prime(i)) {
        prime_a[cnt] = i;
        if (prime_a[cnt] - prime_a[cnt-1] == 2) ans++;
        cnt++;
// printf("%d\n", i);}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}


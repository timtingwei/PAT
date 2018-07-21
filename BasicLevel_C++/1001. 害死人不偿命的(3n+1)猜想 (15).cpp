// copyright [2018] <mituh>

#include <stdio.h>

int main() {
  int n, cnt = 0;
  if (scanf("%d", &n) != EOF) {
    while (n != 1) {
      n = (n % 2) ? (3*n + 1)/2 : n/2;
      cnt++;
    }
    printf("%d\n", cnt);
  }

  return 0;
}

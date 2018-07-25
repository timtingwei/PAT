// Copyright [2018] <mituh>
// 1009. 说反话 (20).cpp    // 10min
/*
Hello World Here I Come

Come I Here World Hello
*/
#include <stdio.h>
#define MAXN 50
char s[MAXN][MAXN];
int main() {
  int n = 0;
  while (scanf("%s", s[n]) == 1) {
    n++;
  }
  for (int i = n-1; i >= 0; i--) {
    if (i != n-1) printf(" ");
    printf("%s", s[i]);
  }
  printf("\n");

  return 0;
}

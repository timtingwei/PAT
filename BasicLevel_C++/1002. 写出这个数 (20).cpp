// copyright [2018] <mituh>

#include <stdio.h>
#include <string.h>

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int c, sum = 0;
  while ((c = getchar()) != '\n')  // why?? 这里如果是EOF, answer
    sum += (c - '0');
  char py[10][5] = {"ling", "yi", "er", "san", "si",
                    "wu", "liu", "qi", "ba", "jiu"};
  int a[5] = {}, cnt = 0;
  while (sum > 0) {
    a[cnt++] = sum % 10;
    sum /= 10;
  }

  for (int i = cnt - 1; i > 0; i--) { printf("%s ", py[a[i]]);}
  printf("%s\n", py[a[0]]);

  return 0;
}

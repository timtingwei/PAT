// Copyright [2018] <mituh>
// 1064. 朋友数（20).cpp       10:10->10:26
#include <cstdio>
#include <cstring>

int id[10050];
char digit[6];

int main() {
  int N; scanf("%d", &N);
  int cnt = 0, max_p = 0;
  while (N--) {
    scanf("%s", digit);
    int num = 0;
    for (int i = 0; i < strlen(digit); i++) {
      num += digit[i] - '0';
    }

    if (!id[num]) {
      id[num] = 1;
      cnt++;
      if (num > max_p) max_p = num;
    }
  }

  int flag = 0;
  printf("%d\n", cnt);
  for (int i = 0; i <= max_p; i++) {
    if (id[i]) {
      if (flag) printf(" ");
      printf("%d", i);
      flag = 1;
    }
  }
  return 0;
}

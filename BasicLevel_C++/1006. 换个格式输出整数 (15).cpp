// copyright [2018] <mituh>
// 1006. 换个格式输出整数 (15).cpp
/*
  思路: 取余得到3位数各个位数大小a, b, c, 输出a个B+b个S+12..c
 */
#include <stdio.h>
#include <string.h>
int cnt_n[3];  // 三个位数
int main() {
  int n, cnt = 2;
  if (scanf("%d", &n) == 1) {
    memset(cnt_n, 0, sizeof(cnt_n));
    while (n) {
      cnt_n[cnt--] = n%10;
      n /= 10;
    }
    for (int i = 0; i < cnt_n[0]; i++) {printf("B");}
    for (int i = 0; i < cnt_n[1]; i++) {printf("S");}
    for (int i = 1; i <= cnt_n[2]; i++) {printf("%d", i);}
    printf("\n");
  }

  return 0;
}

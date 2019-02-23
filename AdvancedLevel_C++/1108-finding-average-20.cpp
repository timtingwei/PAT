/* Copyright [2019] <mituh> */
/* 1108-finding-average-20.cpp */
/* 字符串 */
/*
Sample Input 1:
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35

Sample Output 1:
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38

Sample Input 2:
2
aaa -9999

Sample Output 2:
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/
#include <cstdio>
#include <cstring>

char a[100], b[100];
int main() {
  int i, j, N, cnt, flag;
  double sum, temp;
  scanf("%d", &N);
  cnt = 0; sum = 0.0;
  for (i = 0; i < N; i++) {
    scanf("%s", a);
    sscanf(a, "%lf", &temp);
    sprintf(b, "%.2f", temp);
    flag = 0;
    for (j = 0; j < strlen(a); j++) {
      if (a[j] != b[j]) flag = 1;
    }
    if (flag || temp < -1000 || temp > 1000) {
      printf("ERROR: %s is not a legal number\n", a);
      continue;
    } else {
      cnt++;
      sum += temp;
    }
  }
  if (cnt == 0) {
    printf("The average of 0 numbers is Undefined\n");
  } else if (cnt == 1) {
    printf("The average of 1 number is %.2lf\n", sum);
  } else {
    printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
  }
  return 0;
}


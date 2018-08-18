// Copyright [2018] <mituh>
// sscanf_sprintf.c
#include <stdio.h>
int foo_1() {
  int n;
  char str[5] = "123";
  sscanf(str, "%d", &n);
  printf("%d\n", n);
  return 0;
}

int foo_2() {
  int n = 1199;
  char str[100];
  sprintf(str, "%d", n);
  printf("%s\n", str);
  return 0;
}

int foo_3() {
  int y, m, d;
  char str[100]; scanf("%s", str);
  sscanf(str, "%d/%d/%d", &y, &m, &d);
  printf("%d %d %d\n", y, m, d);
  return 0;
}

int foo_4() {
  int n;
  double db;
  char str[100] = "2048:223.14,hello", str2[100];
  sscanf(str, "%d:%lf,%s", &n, &db, str2);
  printf("n = %d, db = %.1f, str2 = %s\n", n, db, str2);
  return 0;
}

int foo_5() {
  char name[20] = "mituh";
  double score = 82.99;
  char ans[100];
  sprintf(ans, "%s : %.2f", name, (int)score+0.5);
  printf("%s\n", ans);          // mituh : 82.50
  return 0;
}


int main() {
  // foo_1;
  // foo_2();
  // foo_3();
  // foo_4();
  foo_5();
  return 0;
}

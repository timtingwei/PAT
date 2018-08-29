// Copyright [2018] <mituh>
// bign.cpp
// 实现大整数运算

#include <cstring>
#include <cstdio>

struct Bign {
  int d[1000];
  int len;
  Bign() {
    memset(d, 0, sizeof(d));
    len = 0;
  }
};

// 整数转化成bign
Bign change(char str[]) {
  Bign a;
  a.len = strlen(str);
  for (int i = 0; i < a.len; i++) {
    a.d[i] = str[a.len-1-i] - '0';
  }
  return a;
}

// 比较两个bign
int compare(Bign a, Bign b) {
  if (a.len < b.len) {
    return -1;
  } else if (a.len > b.len) {
    return 1;
  } else {
    for (int i = a.len - 1; i >= 0; i--) {
      if (a.d[i] < b.d[i]) return -1;
      else if (a.d[i] > b.d[i]) return 1;
    }
    return 0;
  }
}

int main() {
  char str1[1000], str2[1000];
  scanf("%s %s", str1, str2);
  Bign aint = change(str1), bint = change(str2);

  printf("rst = %d\n", compare(aint, bint));

  return 0;
}


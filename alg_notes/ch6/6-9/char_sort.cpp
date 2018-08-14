// Copyright [2018] <mituh>
// char_sort.cpp

// sort(首个元素地址, 尾元素的下个哨兵地址, 比较函数)
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(char a, char b) {
  return a > b;
}

int main() {
  char c[] = {'T', 'W', 'A', 'K'};
  sort(c, c+4);
  for (int i = 0; i < 4; i++) {
    printf("%c", c[i]);         // AKTW
  }
  printf("\n");

  sort(c, c+4, cmp);
  for (int i = 0; i < 4; i++) {
    printf("%c", c[i]);         // WTKA
  }
  printf("\n");


  return 0;
}

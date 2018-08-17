// Copyright [2018] <mituh>
// genertate-rand.cpp
// 生成随机数

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

void generate_float(int lo, int hi) {
  srand((unsigned)time(NULL));
  for (int i = 0; i < 10; i++) {
    printf("%d ", (int)(round(1.0*rand()/RAND_MAX*(hi-lo) + lo)));
  }
  printf("\n");
}

int main() {
  srand((unsigned)time(NULL));
  for (int i = 0; i < 10; i++) {
    printf("%d  ", rand());
  }
  printf("\n");
  printf("RAND_MAX = %d\n", RAND_MAX);

  for (int i = 0; i < 10; i++) {
    printf("%d ", rand() % 2);
  }
  printf("\n");

  for (int i = 0; i < 50; i++) {
    printf("%d ", rand() % 91 + 10);
  }
  printf("\n");

  generate_float(50000, 100000);
  
  return 0;
}

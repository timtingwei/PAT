/* Copyright [2019] <mituh> */
/* 1131-subway-map-30.cpp */
/* 图的dfs */
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);
  vector<int> v2;
  v2 = v1;
  v2.push_back(3);
  v2.push_back(4);
  int i;
  for (i = 0; i < v2.size(); i++) {
    printf("%d ", v1[i]);
  }
  printf("\n");
  return 0;
}


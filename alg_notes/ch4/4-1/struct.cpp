// Copyright [2018] <mituh>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student {
  char name[20];
  char id[10];
  int score;
  int r;
} stu[100010];


// 1, 分数不同, 分数高的排在前面
// 2, 分数相同, 名字字典序小的排在前面
bool cmp(Student s1, Student s2) {
  if (s1.score != s2.score) {
    return s1.score > s2.score;
  } else {
    return strcmp(s1.name, s2.name) < 0;
    // return s1.name[0] < s2.name[0];
  }
}



int main() {
  stu[0].name = "tim"; stu[0].id = "123"; stu[0].score = 77;
  stu[1].name = "aaa"; stu[1].id = "321"; stu[1].score = 83;
  stu[2].name = "tims"; stu[2].id = "000"; stu[2].score = 77;
  sort(stu, stu+3, cmp);

  for (int i = 0; i < 3; i++) {
    printf("%s %s %d\n", stu[0].name, stu[0].id, stu[0].score);
  }

  // 计算排名可以用于储存
  /*
  int r = 1;
  int stu[0].r = 1;
  for (int i = 1; i < 3; i++) {
    if (stu[i].score != stu[i-1].score) {
      stu[i].r = i+1;
    } else {
      stu[i].r = stu[i-1].r;
    }
  }
  */

  // 计算排名可用于直接输出
  int r = 1;
  for (int i = 0; i < 3; i++) {
    if (i > 0 && std[i].score != stu[i-1].score)
      r = i+1;
    // printf...
  }

  return 0;
}

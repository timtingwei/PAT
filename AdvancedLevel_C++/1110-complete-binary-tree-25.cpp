/* Copyright [2019] <mituh> */
/* 1110-complete-binary-tree-25.cpp */
/* 完全二叉树 */
/*
Sample Input 1:
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -

Sample Output 1:
YES 8

Sample Input 2:
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -

Sample Output 2:
NO 1

自己写的测试数据
Sample Input 3:
10
7 8
- -
9 -
- -
0 1
2 3
4 5
- -
- -
- -

Sample Output 3:
NO 6

*/

#include <cstdio>
#include <cstring>

#define MaxSize 21
int T[MaxSize];
int check[MaxSize];

int stoi(char s[], int len) {
  if (len == 1) {
    return s[0] - '0';
  } else {
    return ((s[0]-'0') * 10 + s[1]-'0');
  }
}

int IsExist(char s[], int len) {
  int flag;
  if (len == 1) {
    if (s[0] == '-') {
      flag = 0;
    } else {
      flag = 1;
    }
  } else {
    flag = 1;
  }
  return flag;
}

int convert(char s[]) {
  int len;
  len = strlen(s);
  if (IsExist(s, len)) {
    return stoi(s, len);
  } else {
    return -1;
  }
}

void BuildTree(int temp[][2], int Root, int i) {
  int Left, Right;
  T[i] = Root;
  Left = temp[Root][0]; Right = temp[Root][1];
  if (Left != -1) {
    BuildTree(temp, Left, 2*i);
  }
  if (Right != -1) {
    BuildTree(temp, Right, 2*i+1);
  }
}

char s1[3], s2[3];
#define Null -1
void ReadData(int N) {
  int i, c1, c2, Root;
  int temp[MaxSize][2];
  for (i = 0; i < N; i++) { check[i] = 0; }
  c1 = c2 = Null;
  for (i = 0; i < N; i++, c1 = c2 = Null) {
    scanf("%s %s", s1, s2);
    c1 = convert(s1); c2 = convert(s2);
    if (c1 == Null) {   /* 读到- */
      temp[i][0] = -1;
    } else {
      temp[i][0] = c1;
      check[c1] = 1;
    }
    if (c2 == Null) {   /* 读到- */
      temp[i][1] = -1;
    } else {
      temp[i][1] = c2;   /* 写仔细点! */
      check[c2] = 1;
    }
  }
  for (i = 0; i < N; i++) {
    if (!check[i]) {
      Root = i; break;
    }
  }
  /* InitT(); */
  for (i = 0; i < MaxSize; i++) { T[i] = -1;}
  BuildTree(temp, Root, 1);
}

int IsContinues() {
  int i;
  for (i = 1; i < MaxSize-1; i++) {
    if (T[i] == -1 && T[i+1] != -1) {   /* 空结点后出现非空结点 顺序不要写错!*/
      return 0;
    }
  }
  return 1;
}

int main() {
  int N;
  scanf("%d", &N);
  ReadData(N);
  if (IsContinues()) {
    printf("YES %d\n", T[N]);
  } else {
    printf("NO %d\n", T[0]);
  }
  return 0;
}

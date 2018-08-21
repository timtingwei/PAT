// Copyright [2018] <mituh>
// 1028-list-sorting-25.cpp
/*
1028 List Sorting (25)（25 point(s)）

Excel can sort records according to any column. Now you are supposed to imitate this function.

Input

Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

Output

For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

Sample Input 1

3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1

000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2

4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2

000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3

4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3

000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/

/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
  string id;
  string name;
  int score;
};

bool cmp1(Node n1, Node n2) {
  return n1.id < n2.id;
}

bool cmp2(Node n1, Node n2) {
  if (n1.name != n2.name) return n1.name <= n2.name;
  return n1.id < n2.id;
}

bool cmp3(Node n1, Node n2) {
  if (n1.score != n2.score) return n1.score <= n2.score;
  return n1.id < n2.id;
}

int main() {
  int N, C; scanf("%d %d", &N, &C);
  string id, name; int score;
  vector<Node> v;
  while (N--) {
    cin >> id >> name >> score;
    v.push_back(Node{id, name, score});
  }
  switch (C) {
    case 1: sort(v.begin(), v.end(), cmp1); break;
    case 2: sort(v.begin(), v.end(), cmp2); break;
    case 3: sort(v.begin(), v.end(), cmp3); break;
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].id << " " << v[i].name << " " << v[i].score << endl;
  }
  return 0;
}

// case6 超时
*/

// string替换成字符数组, vector<Node>替换成Node数组. 用strcmp比较

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
  char id[10];
  char name[10];
  int score;
};

bool cmp1(Node n1, Node n2) {
  return strcmp(n1.id, n2.id) < 0;
}

bool cmp2(Node n1, Node n2) {
  if (strcmp(n1.name, n2.name) != 0) return strcmp(n1.name, n2.name) <= 0;
  return strcmp(n1.id, n2.id) < 0;
}

bool cmp3(Node n1, Node n2) {
  if (n1.score != n2.score) return n1.score <= n2.score;
  return strcmp(n1.id, n2.id) < 0;
}

Node nodes[100050];

int main() {
  int N, C; scanf("%d %d", &N, &C);
  int n = 0;
  while (N--) {
    scanf("%s %s %d", nodes[n].id, nodes[n].name, &nodes[n].score);
    n++;
  }
  switch (C) {
    case 1: sort(nodes, nodes + n, cmp1); break;
    case 2: sort(nodes, nodes + n, cmp2); break;
    case 3: sort(nodes, nodes + n, cmp3); break;
  }
  for (int i = 0; i < n; i++) {
    printf("%s %s %d\n", nodes[i].id, nodes[i].name, nodes[i].score);
  }
  return 0;
}


/*
#include <string.h>
#include <stdio.h>

int main() {
  char a[10] = "12";
  char b[10] = "ab";
  char c[10] = "123";
  char name1[10] = "tim";
  char name2[10] = "amy";
  printf("%d\n", strcmp("4", "3"));   // 1
  printf("%d\n", strcmp(a, c));   // 1
  printf("%d\n", strcmp(name1, name2));   // 1
  // strcmp(str1, str2) < 0    ->  str1 < str2;
  // strcmp(str1, str2) <= 0    ->  str1 <= str2;
  return 0;
}
*/

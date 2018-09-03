// Copyright [2018] <mituh>
// 1006-sign-in-and-sign-out-25.cpp   03:29 -> 3:47 = 18min
/*
1006 Sign In and Sign Out(25)

At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:
Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.

Output Specification:
For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

Sample Output:
SC3021234 CS301133
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
  char id[20];
  char in_time[15];
  char out_time[15];
};

bool cmp1(Node n1, Node n2) {
  return strcmp(n1.in_time, n2.in_time) < 0;
}

bool cmp2(Node n1, Node n2) {
  return strcmp(n1.out_time, n2.out_time) > 0;
}

vector<Node> v;

int main() {
  int M; scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    Node n;
    scanf("%s %s %s", n.id, n.in_time, n.out_time);
    v.push_back(n);
  }
  sort(v.begin(), v.end(), cmp1);
  printf("%s ", v[0].id);
  sort(v.begin(), v.end(), cmp2);
  printf("%s", v[0].id);
  return 0;
}

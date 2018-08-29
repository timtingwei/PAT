// Copyright [2018] <mituh>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Question {
  int score;
  int opt_num;
  int ans_num;
  char ans[6];
};

vector<Question > v;
int error[105][6];

int main() {
  int N, M; scanf("%d %d", &N, &M);
  memset(error, 0, sizeof(error));
  for (int i = 0; i < M; i++) {
    Quetion q;
    scanf("%d %d %d %d", &q.score, &q.opt_num, &q.ans_num);
    for (int ans_i = 0; ans_i < q.ans_num; ans_i++) {
      scanf("%c", &q.ans[ans_i]);
    }
    v.push_back(q);
  }

  int max = 0;
  for (int i = 0; i < N; i++) {
    string s; getline(cin, s);
    int qi = 0;
    while (j < s.length()) {
      if (j == '(') {
        int n = s[j+1];
        for (int in = 1; in <= n; in++) {
          int ok = 0;
          for (int  iv = 0; iv < v[qi].ans_num; iv++) {
            if (v[qi].ans[iv] == s[j+in*2]) ok = 1;
          }
          if (!ok) {
            error[qi][s[j+in*2-'a']]++;
            if (error[qi][s[j+in*2-'a']] > max) {
              max = error[qi][s[j+in*2-'a']];
            }
          } else {
            // add score;
          }
        }

        for (int ans_i = 0; ans_i < v[qi].ans_num; ans_i++) {
          int ok = 0;
          for (in = 1; in <= n; in++) {
            if (v[qi].ans[ans_i] == s[j+in*2]) ok = 1;
            if (!ok) {
              error[qi][v[qi].ans[ans_i]-'a']++;
              if (error[qi][v[qi].ans[ans_i]-'a'] > max) {
                max = error[qi][v[qi].ans[ans_i]-'a'];
              }
            } else {
              // add score
            }
          }
        }
        j = j+(n+1)*2;
        qi++;
      }
      j++;
    }
  }
}

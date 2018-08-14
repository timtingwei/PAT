// Copyright [2018] <mituh>
// 1043. 输出PATest(20).cpp  06:12 -> 6:30
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char chars[6] = {'P', 'A', 'T', 'e', 's', 't'};

int main() {
  int cnt[6];
  memset(cnt, 0, sizeof(cnt));
  string s; cin >> s;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < 6; j++)
      if (s[i] == chars[j]) { cnt[j]++; break; }
  }

  int ok;
  do {
    ok = 0;
    for (int i = 0; i < 6; i++) {
      if (cnt[i]) {
        ok = 1;
        printf("%c", chars[i]);
        cnt[i]--;
      }
    }
  } while (ok);

  return 0;
}

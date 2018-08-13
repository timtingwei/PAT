// Copyright [2018] <mituh>
// 06:12 -> 6:30

// 1043. 输出PATest(20).cpp
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
    if (s[i] == 'P') cnt[0]++;
    else if (s[i] == 'A') cnt[1]++;
    else if (s[i] == 'T') cnt[2]++;
    else if (s[i] == 'e') cnt[3]++;
    else if (s[i] == 's') cnt[4]++;
    else if (s[i] == 't') cnt[5]++;
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

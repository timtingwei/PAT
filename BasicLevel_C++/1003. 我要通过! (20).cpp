// copyright [2018] <mituh>
// 1003. 我要通过! (20).cpp
#include <stdio.h>
#include <string.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char s[105] = {};
    if (scanf("%s", s) != EOF) {
      int n = strlen(s);
      int bad = 0;
      int pp = -1, pt = -1;
      int PAT[3] = {};     // cnt:P, A, T
      for (int i = 0; i < n; i++) {
        if (s[i] == 'P' || s[i] == 'A' || s[i] == 'T') {
          if (s[i] == 'P') {
            if (!PAT[0]) {  // 第一次找到P
              PAT[0] = 1;
              pp = i;
            } else {bad = 1; break;}   // 重复出现P, bad
          } else if (s[i] == 'A') {
            PAT[1]++;
          }
          if (s[i] == 'T') {
            if (!PAT[2]) {  // 第一次找到T
              PAT[2] = 1;
              pt = i;
            } else {bad = 1; break;}   // 重复出现T, bad
          }
        } else {  // 出现额外的字符, bad
          bad = 1; break;
        }
      }
      for (int i = 0; i < 3; i++) {
        if (!PAT[i]) {bad = 1; break;}    // PAT中有没出现的字符, bad
      }
      if (bad) {
        printf("NO\n");
      } else {
        int a = pp, b = pt-pp-1, c = n-1-pt;
        if (a * b == c) {
          printf("YES\n");
        } else {
          printf("NO\n");
        }
      }
    }
  }

  return 0;
}

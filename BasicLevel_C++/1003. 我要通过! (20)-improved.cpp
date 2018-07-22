// copyright [2018] <mituh>
// 1003. 我要通过! (20)-improved.cpp
/*
  参考:https://github.com/liuchuo/PAT
  思路:用map容器对输入进行字符串进行统计, 同时满足多个特征->YES, 否则->NO, 不再将特征分散在过程中
 */
#include <stdio.h>
#include <string.h>
#include <map>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char s[105] = {};
    if (scanf("%s", s) != EOF) {
      int p = -1, t = -1;
      std::map<char, int> m;
      for (int i = 0; i < strlen(s); i++) {
        m[s[i]]++;
        if (s[i] == 'P') p = i;
        if (s[i] == 'T') t = i;
      }
      if (m['P'] == 1 && m['A'] != 0 && m['T'] == 1 &&
          m.size() == 3 && p < t &&  p*(t-p-1) == strlen(s)-1-t) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }

  return 0;
}

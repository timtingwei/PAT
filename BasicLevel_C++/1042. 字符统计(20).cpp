// Copyright [2018] <mituh>
// 1042. 字符统计(20).cpp  5:50 -> 06:08
/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int cnt[200];   // 假设ascii200wei
int main() {
  memset(cnt, 0, sizeof(cnt));
  string s;
  getline(cin, s);
  int max_p = 0;
  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i])) {
      int ch = tolower(s[i]);
      cnt[ch]++;
      if (cnt[ch] > cnt[max_p]) max_p = ch;
    }
  }
  printf("%c %d\n", max_p, cnt[max_p]);

  return 0;
}
*/

// This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........

// case 2, 如果有并列, 输出字典序列小的


#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int cnt[200];   // 假设ascii200位
int main() {
  memset(cnt, 0, sizeof(cnt));
  string s;
  getline(cin, s);
  int max_p = 0;
  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i])) {
      int ch = tolower(s[i]);
      cnt[ch]++;
      if (cnt[ch] > cnt[max_p]) max_p = ch;
      if (cnt[ch] == cnt[max_p] && (ch < max_p)) max_p = ch;
    }
  }
  printf("%c %d\n", max_p, cnt[max_p]);

  return 0;
}


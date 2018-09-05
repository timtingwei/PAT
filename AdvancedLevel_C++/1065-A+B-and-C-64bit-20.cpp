// Copyright [2018] <mituh>
// 1065-A+B-and-C-64bit-20.cpp   16:21->16:48(hand)->16:59->17:10 || 20:10(mac)


#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Bign {
  int d[1005];
  int len;
  Bign() {
    memset(d, 0, sizeof(d));
    len = 0;
  }
};

Bign change(string s) {
  Bign a;
  a.len = s.length();
  for (int i = 0; i < a.len; i++) {
    a.d[i] = s[a.len-1-i] - '0';
  }
  return a;
}

Bign add(Bign a, Bign b) {
  Bign ans;
  int carry = 0;
  for (int i = 0; i < a.len || i < a.len; i++) {
    int temp = a.d[i] + b.d[i] + carry;
    ans.d[ans.len++] = temp % 10;
    carry = temp / 10;
  }
  if (carry) {
    ans.d[ans.len++] = carry;
  }
  return ans;
}

Bign sub(Bign a, Bign b) {
  Bign ans;

  for (int i = 0; i < a.len || i < b.len; i++) {
    if (a.d[i] < b.d[i]) {
      a.d[i+1]--;
      a.d[i] += 10;
    }
    ans.d[ans.len++] = a.d[i] - b.d[i];
  }
  while (ans.len - 1 >= 1 && ans.d[ans.len-1] == 0) {
    ans.len--;
  }
  return ans;
}

int compare(Bign a, Bign b) {
  if (a.len < b.len) return -1;
  else if (a.len > b.len) return 1;
  else {
    for (int i = 0; i < a.len; i++) {
      if (a.d[i] < b.d[i]) {
        return -1;
      } else if (a.d[i] > b.d[i]) {
        return 1;
      }
    }
    return 0;
  }
}
int main() {
  int T; cin >> T;
  for (int i = 0 ; i < T; i++) {
    // ..
    string a, b, c; cin >> a >> b >> c;
    int flag_a = 1, flag_b = 1, flag_c = 1, flag_add = 1;
    if (a[0] == '-') {
      flag_a = -1;
      a = a.substr(1, b.length()-1);
    }  // else flag_a = 1;
    if (b[0] == '-') {
      flag_b = -1;
      b = b.substr(1, b.length()-1);
    }
    if (c[0] == '-') {
      flag_c = -1;
      c = c.substr(1, c.length()-1);
    }
    Bign ba = change(a), bb = change(b), bc = change(c), rst_add;
    if (flag_a * flag_b == 1) {
      flag_add = flag_a;
      rst_add = add(ba, bb);
    } else {   // diff flag, compare
      int cmp_ab = compare(ba, bb);
      if (cmp_ab > 0) {
        flag_add = flag_a;
        rst_add = sub(ba, bb);
      } else if (cmp_ab < 0) {
        flag_add = flag_b;
        rst_add = sub(bb, ba);
      } else {  // -5 + 5 = 0
        flag_add = 1;
        rst_add = sub(ba, bb);
      }
    }
    string ans = "";
    if (flag_add < 0 && flag_c > 0) {
      ans = "false";
    } else if (flag_add > 0 && flag_c < 0) {
      ans = "true";
    } else if (flag_add < 0 && flag_c < 0) {
      ans = compare(rst_add, bc) < 0 ? "true" : "false";
    } else if (flag_add > 0 && flag_c > 0) {
      ans = compare(rst_add, bc) > 0 ? "true" : "false";
    }
    cout << "Case #" << i+1 << ": " << ans << endl;
  }
  return 0;
}

// case2 wrong error

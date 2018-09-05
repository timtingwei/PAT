// Copyright [2018] <mituh>
// 16:21->16:48(hand)->16:59
#include <iostream>
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

Bign add(Bign a, Bign b) {
  Bign ans;
  int carry = 0;
  for (int i = 0; i < a.len || i < b.len; i++) {
    int temp = a.d[i] + b.d[i] + carry;
    ans.d[ans.len++] = carry % 10;
    carry = temp / 10;
  }
  if (carry) {
    ans.d[ans.len++] = carry;
  }
  return ans;
}

int compare(Bign a, Bign b) {
  int a_high = a.d[a.len-1], b_high = b.d[b.len-1];
  if (a_high * b_high == 0) {
    return 0;
  } else if (a_high * b_high < 0) {
    if (a_high > 0 && b_high < 0) {
      return 1;
    } else if (a_high < 0 && b_high > 0) {
      return -1;
    }
  } else {
    int flag = 1;
    if (a_high < 0) flag = -1;
    if (a.len > b.len) return 1*flag;
    else if (a.len < b.len) return -1*flag;
    else {
      for (int i = a.len - 1; i >= 0; i--) {
        if (a[i] > b[i]) return 1*flag;
        else if (a[i] < b[i]) return -1*flag;
      }
      return 0;   // why?
    }
  }
}





int main () {
  int T; scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    string a, b, c;
    Bign  ba = strToBign(a), bb = strToBign(b), bc = strToBign(c);
    int rst = compare(add(ba, bb), bc);
    string p = (rst == 1) ? "true" : "false";
    cout << "Case #" << i+1 << ": " << p << endl;
  }
  
  return 0;
}

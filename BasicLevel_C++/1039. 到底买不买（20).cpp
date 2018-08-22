// Copyright [2018] <mituh>
// 1039. 到底买不买（20).cpp 05:39 -> 6:02 = 23min
/*
1039 到底买不买（20）（20 point(s)）

小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。

为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。

\ 图 1

输入格式：

每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。

输出格式：

如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。

输入样例1：

ppRYYGrrYBR2258
YrR8RrY
输出样例1：

Yes 8
输入样例2：

ppRYYGrrYB225
YrR8RrY
输出样例2：

No 2
*/


/*
#include <iostream>
#include <string>
using namespace std;


int main() {
  string s, t;
  cin >> s >> t;
  int cnt = 0;
  for (int i = 0; i < t.length(); i++) {
    if (s.find(t[i]) != string::npos) cnt++;
  }
  if (cnt >= t.length()) {
    cout << "Yes " << s.length() - t.length() << endl;
  } else {
    cout << "No " << t.length() - cnt << endl;
  }
  
  return 0;
}
*/

/*
// 字符串删除的解法
// case 1, 2 WA
// 怎么解决某个珠子需要两颗的问题?
// 能否对字符串删除操作

#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int cnt = 0;
  for (int i = 0; i < t.length(); i++) {
    int pos = s.find(t[i]);
    if (pos != string::npos) {
      cnt++;
      s.erase(pos, 1);
    }
  }
  if (cnt >= t.length()) {
    cout << "Yes " << s.length() << endl;
  } else {
    cout << "No " << t.length() - cnt << endl;
  }

  return 0;
}
*/

// Hash表的解法, 复杂度为O(n), 查找为O(1)
// 7:49 -> 8:00 = 11min
#include <cstdio>
#include <cstring>
int give[200];
char A[1050];
char B[1050];

int main() {
  scanf("%s %s", A, B);
  memset(give, 0, sizeof(give));
  for (int i = 0; i < strlen(A); i++) {
    give[(int)A[i]]++;
  }
  int cnt = 0;
  for (int i = 0; i < strlen(B); i++) {
    if (!give[(int)B[i]]) {
      cnt++;
    } else {
      give[(int)B[i]]--;
    }
  }
  if (cnt == 0) {
    printf("Yes %lu\n", strlen(A) - strlen(B));
  } else {
    printf("No %d\n", cnt);
  }
  return 0;
}

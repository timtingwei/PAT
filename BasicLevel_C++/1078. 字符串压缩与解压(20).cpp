// Copyright [2018] <mituh>
// 1078. 字符串压缩与解压(20).cpp              07:02 -> 07:44
/*
1078 字符串压缩与解压（20 point(s)）

文本压缩有很多种方法，这里我们只考虑最简单的一种：把由相同字符组成的一个连续的片段用这个字符和片段中含有这个字符的个数来表示。例如 ccccc 就用 5c 来表示。如果字符没有重复，就原样输出。例如 aba 压缩后仍然是 aba。

解压方法就是反过来，把形如 5c 这样的表示恢复为 ccccc。

本题需要你根据压缩或解压的要求，对给定字符串进行处理。这里我们简单地假设原始字符串是完全由英文字母和空格组成的非空字符串。

输入格式：

输入第一行给出一个字符，如果是 C 就表示下面的字符串需要被压缩；如果是 D 就表示下面的字符串需要被解压。第二行给出需要被压缩或解压的不超过 1000 个字符的字符串，以回车结尾。题目保证字符重复个数在整型范围内，且输出文件不超过 1MB。

输出格式：

根据要求压缩或解压字符串，并在一行中输出结果。

输入样例 1：

C
TTTTThhiiiis isssss a   tesssst CAaaa as
输出样例 1：

5T2h4is i5s a3 te4st CA3a as
输入样例 2：

D
5T2h4is i5s a3 te4st CA3a as10Z
输出样例 2：

TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ
*/

/*
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
  char op; scanf("%c", &op);
  string s;
  getchar();
  if (op == 'C') {
    getline(cin, s); s += '0';
    int N = s.length()-1;
    int i = 0, cnt = 1;
    while (i < N) {
      if (s[i] == s[i+1]) {
        cnt++;
      } else  {
        if (cnt == 1) {
          printf("%c", s[i]);
        } else {
          printf("%d%c", cnt, s[i]); cnt = 1;
        }
      }
      i++;
    }
  } else if (op == 'D') {
    getline(cin, s);
    int N = s.length();
    int i = 0;
    while (i < N) {
      if (isdigit(s[i])) {
        int j = i+1;
        while (j < N && isdigit(s[j])) j++;
        int n = stoi(s.substr(i, j));
        for (int k = 0; k < n; k++) {
          printf("%c", s[j]);
        }
        i = j;
      } else {
        printf("%c", s[i]); i++;
      }
    }
  }
  printf("\n");
  return 0;
}

// case 1, 5
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
  char op; scanf("%c", &op);
  string s;
  getchar();
  if (op == 'C') {
    getline(cin, s); s += '0';
    int N = s.length()-1;
    int i = 0, cnt = 1;
    while (i < N) {
      if (s[i] == s[i+1]) {
        cnt++;
      } else  {
        if (cnt == 1) {
          printf("%c", s[i]);
        } else {
          printf("%d%c", cnt, s[i]); cnt = 1;
        }
      }
      i++;
    }
  } else if (op == 'D') {
    getline(cin, s);
    int N = s.length();
    int i = 0;
    while (i < N) {
      if (isdigit(s[i])) {
        int j = i+1;
        while (j < N && isdigit(s[j])) j++;
        int n = stoi(s.substr(i, j));
        for (int k = 0; k < n; k++) {
          printf("%c", s[j]);
        }
        i = j+1;                   // case1, 5
      } else {
        printf("%c", s[i]); i++;
      }
    }
  }
  printf("\n");
  return 0;
}


/*
// 用栈实现的版本
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

int main() {
  char op; cin >> op;
  stack<char> s; char ch;
  getchar();
  if (op == 'C') {
    // char ch;
    while (scanf("%c", &ch) != EOF && ch != '\n' && ch != '\r') {
      if (s.empty() || s.top() == ch) {
        s.push(ch);
      } else {
        int cnt = 0; char old_ch = s.top();
        while (!s.empty()) {
          s.pop(); cnt++;
        }
        if (cnt == 1) {
          putchar(old_ch);
        } else {
          printf("%d%c", cnt, old_ch);
        }
        s.push(ch);
      }
    }
  } else if (op == 'D') {
    while (scanf("%c", &ch) != EOF && ch != '\n' && ch != '\r') {
      if (isdigit(ch)) {
        s.push(ch);
      } else {
        if (!s.empty()) {
          int n = 0, b = 1;
          while (!s.empty()) {
            n += b * (s.top() - '0');
            s.pop();
            b *= 10;
          }
          while (n--) putchar(ch);
        } else {
          putchar(ch);
        }
      }
    }
  }
  printf("\n");
  return 0;
}
*/

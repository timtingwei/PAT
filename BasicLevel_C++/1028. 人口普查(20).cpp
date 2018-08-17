// Copyright [2018] <mituh>
// 1028. 人口普查(20).cpp      06:53 -> 7:19 -> 7:37 -> 7:54
/*
1028 人口普查(20)（20 point(s)）

某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：

输入在第一行给出正整数N，取值在(0, 10^5^]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：

在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：

5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：

3 Tom John
*/

/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


struct Node {
  string name;
  string birth;
};


void convert(string s, int date[]) {
  // memset(date, 0, sizeof(date));
  int n = s.length();
  int i = 0, cnt = 0;
  while (i < n) {
    int j = i+1;
    while (j < n) {
      if (s[j] == '/') {
        date[cnt++] = stoi(s.substr(i, j+1));
        i = j+1;
        break;
      }
      j++;
    }
  }
}

int less(string birth1, string birth2) {
  int date1[3], date2[3];
  convert(birth1, date1); convert(birth2, date2);
  if (date1[0] == date2[0]) {
    if (date1[1] == date2[1]) {
      if (date1[2] == date2[2]) {
        return 0;
      } else if (date1[2] < date2[2]) {
        return 1;
      } else {
        return 0;
      }
    } else if (date1[1] < date2[1]) {
      return 1;
    } else {
      return 0;
    }
  } else if (date1[1] < date2[1])  {
    return 1;
  } else {
    return 0;   // birth1 > birth2
  }
}
*/

/*
int main() {
  int N; cin >> N;
  int cnt = 0;
  Node min, max;
  string name, birth;
  cin >> name >> birth;
  min.name = name; min.birth = birth;
  max = min;
  for (int i = 1; i < N; i++) {
    cin >> name >> birth;
    if (less(birth, "1814/09/06") || less ("2014/09/06", birth)) continue;
    cnt++;
    if (less(max.birth, birth)) { max.name = name; max.birth = birth; }
    if (less(birth, min.birth)) { min.name = name; min.birth = birth; }
  }
  cout << cnt << " " << min.name << " " << max.name << endl;

  return 0;
}
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;


struct Node {
  string name;
  string birth;
};


int main() {
  int N; cin >> N;
  int cnt = 0;
  Node min, max;
  for (int i = 0; i < N; i++) {
    string name, birth; cin >> name >> birth;
    if ((birth < "1814/09/06") || ("2014/09/06" < birth)) continue;
    if (!cnt) {
      min.name = name; min.birth = birth;
    }
    if (max.birth < birth) { max.name = name; max.birth = birth; }
    if (birth < min.birth) { min.name = name; min.birth = birth; }
    cnt++;
  }
  if (cnt) {
    cout << cnt << " " << min.name << " " << max.name << endl;
  } else {
    cout << "0" << endl;
  }

  return 0;
}


// case3, 格式错误: 修改最后无有效输入的情况


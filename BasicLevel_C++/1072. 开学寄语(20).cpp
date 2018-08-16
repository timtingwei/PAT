// Copyright [2018] <mituh>
// 1072. 开学寄语(20).cpp     9:36 -> 9:58 -> 10:02
/*1072 开学寄语（20 point(s)）

下图是上海某校的新学期开学寄语：天将降大任于斯人也，必先删其微博，卸其 QQ，封其电脑，夺其手机，收其 ipad，断其 wifi，使其百无聊赖，然后，净面、理发、整衣，然后思过、读书、锻炼、明智、开悟、精进。而后必成大器也！

jiyu.JPG

本题要求你写个程序帮助这所学校的老师检查所有学生的物品，以助其成大器。

输入格式：
输入第一行给出两个正整数 N（≤ 1000）和 M（≤ 6），分别是学生人数和需要被查缴的物品种类数。第二行给出 M 个需要被查缴的物品编号，其中编号为 4 位数字。随后 N 行，每行给出一位学生的姓名缩写（由 1-4 个大写英文字母组成）、个人物品数量 K（0 ≤ K ≤ 10）、以及 K 个物品的编号。

输出格式：
顺次检查每个学生携带的物品，如果有需要被查缴的物品存在，则按以下格式输出该生的信息和其需要被查缴的物品的信息（注意行末不得有多余空格）：

姓名缩写: 物品编号1 物品编号2 ……
最后一行输出存在问题的学生的总人数和被查缴物品的总数。

输入样例：
4 2
2333 6666
CYLL 3 1234 2345 3456
U 4 9966 6666 8888 6666
GG 2 2333 7777
JJ 3 0012 6666 2333

输出样例：
U: 6666 6666
GG: 2333
JJ: 6666 2333
3 5

// case2:
4 3
2333 6666 0000
CYLL 4 1234 2345 3456 0000
U 4 9966 6666 8888 6666
GG 3 2333 7777 0000
JJ 3 0012 6666 2333
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int id[10000];

int main() {
  int N, M; string tmp;
  int stu_n = 0, obj_n = 0;
  cin >> N >> M;
  memset(id, 0, sizeof(id));
  for (int i = 0; i < M; i++) {
    cin >> tmp;
    id[stoi(tmp)] = 1;
  }
  for (int i = 0; i < N; i++) {
    int ok = 0, k = 0;
    string name; int cnt;
    cin >> name >> cnt;
    for (int j = 0; j < cnt; j++) {
      cin >> tmp;
      if (id[stoi(tmp)]) {
        if (!ok) { cout << name << ":"; ok = 1;}
        cout << " " << tmp;
        k++;
      }
    }

    if (ok) {stu_n++; obj_n += k; cout << endl;}
  }
  cout << stu_n << " " << obj_n << endl;
  return 0;
}


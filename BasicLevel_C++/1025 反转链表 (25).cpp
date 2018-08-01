// Copyright [2018] <mituh>
// 1025 反转链表 (25).cpp  1:09 -> 有思路, 但无法实现, 先实现一下静态链表
/*
1025 反转链表 (25)（25 point(s)）

给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。
例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；
如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。

输入格式：

每个输入包含1个测试用例。
每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 10^5)、以及正整数K(<=N)，
即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。

输出格式：

对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入样例：

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 100050
typedef struct Node {
  int data;
  int cur;
} Node, LinkList[MAXSIZE];


void read(LinkList *L, int *K, int *N, int *k) {
  string sp; int p, j;   // p作为读入链表的工作指针, j计数
  cin >> sp >> *K >> *N;
  *k = stoi(sp);         // k是头结点索引,
  for (j = 0; j < *K; j++) {
    cin >> p >> (*L)[p].data >> (*L)[p].cur;
  }
}

int main() {
  LinkList L;  int K, N, k;
  read(&L, &K, &N, &k);
  int ck = k, flag = 0;     // ck用于保存反转后头结点索引, flag标记第一次反转
  for (;;) {
    int r, p; Node q;
    r = k; p = L[r].cur;    // i为此次反转开始时的表头, p是下一个结点
    int m, n, j, x;         // m用于遍历个数, n用于交换次数, j用于计数
    m = N-2, n = N-1;
    j = 0;
    while (p != -1 && j < m) {
      p = L[p].cur; r = L[r].cur;    // 移动p, r
      j++;
      cout << "inwhile p=" << p << "\n";
    }
    if (p == -1) break;     // 这个表的长度达不到反转长度
    --n; --m;               // 次数减少
    q.data = L[p].data;     // 保存此次反转尾部结点, debug: add node
    q.cur  = L[p].cur;
    cout << "node: data=" << q.data << " cur=" << q.cur << "\n";
    if (!flag) {ck = p; flag = 1;}
    cout << "p=" << p << "\n";
    L[p].cur = r;
    p = r;                  // 当前结点指向上一个结点, 交换的核心, p同时前移
    r = k;                  // r回到当前表头位置
    for (x = 0; x < n; x++) {
      j = 0;
      while (j < m) {r = L[r].cur; j++;}  // 移动r, p已经原地不动
      L[p].cur = r;
      p = r;
      r = k;
      --m;                           // 下一次移动r次数减少
    }
    k = L[p].cur = q.cur;         // 表头指向表尾指向的结点
  }
  // 从ck开始遍历整个链表
  int p, j;
  p = ck; j = 0;
  while ((p != -1) && j < K) {
    cout << L[p].data << " ";
    p = L[p].cur;
    j++;
  }
  cout << "\n";
  return 0;
}

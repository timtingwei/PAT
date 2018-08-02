// Copyright [2018] <mituh>
// 1025. 反转链表 (25).cpp  1:09 -> 最后完成了, 但没过case6, 日后再说
/*
1025 反转链表 (25)（25 point(s)）
给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。
例如：给定L为1→2→3→4→5→6，
K为3，则输出应该为3→2→1→6→5→4；
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

思路:
外层循环, 循环次数根据K和N可计算得到, K/N
内层循环, 遍历K个结点, 次数为K, node, prev, next三个结点

// bug1: 此时的node不是下一段反转之后的头结点
// bug2: 00100 6 5时, 最后一个结点没链上
// debug2: 跟循环只做K次有关, 最后一次外循环的时候, 还要把内循环外出来的下一个Node给链上
// a, 标记内外层最后一次循环?
// b. lasthead是最后一个结点, 将最后一次node给传到循环外 选b

submit之后的错误:
// case6: 网上都说是因为输入不合法, 有存在不在链表上的结点？
产生疑惑:
如果两个索引相同, 指向结点不同, 该选择哪一个?
如果索引不同, 指向结点相同, 该选择哪一个留下来?
如果确实都不相同, 那我该用什么方法读取? getchar() cin()?

因此, 我的case6仍然没有通过...

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
12684 2 99883
33218 3 00000
99999 5 68237
12309 2 33218

*/

#include <iostream>
#include <cstdio>
using namespace std;

#define MAXSIZE 100050
typedef struct Node {
  int data;
  int next;
} Node, LinkList[MAXSIZE];

int main() {
  LinkList L;
  int K, N;
  // 链表的读取
  int head, p;   // p作为链表IO的工作指针
  cin >> p >> K >> N;
  head = p;         // head是头结点索引,
  for (int j = 0; j < K; j++) {
    cin >> p >> L[p].data >> L[p].next;
  }
  int flag = 1, pTotReverseHead = -1;  // 空指针
  int lastHead = -1, lastNextNode = -1;
  for (int i = 0; i < K/N; i++) {
    int pReverseHead = -1;
    int pNode = head;
    int pPrev = -1;                  // 指向空结点
    // int j;                        // 为了标记内外循环的最后一次?
    for (int j = 0; j < N; j++) {
      int pNext = L[pNode].next;     // 保存下一结点的索引
      if (j == N-1) {
        if (flag) { pTotReverseHead = pNode; flag = 0;}  // 总头结点
        pReverseHead = pNode;        // 当前段的头结点
      }
      L[pNode].next = pPrev;
      pPrev = pNode;           // 断掉的链接, 通过prev结点保存
      pNode = pNext;
    }
    // debug1: 此时的node不是下一段反转之后的头结点
    // L[head].next = pNode;   // 原来的头结点成为尾部结点, 指向下一段的头结点
    if (lastHead != -1) {
      L[lastHead].next = pReverseHead;  // 上一个段原先的头结点与这段反转后链
    }
    lastHead = head;
    head = pNode;              // head是下一段反转的头结点
    lastNextNode = pNode;      // 标记出未反转的头结点, 有可能为-1
  }
  L[lastHead].next = lastNextNode;    // debug2
  // 根据pReverseHead来打印新的链表, p为工作指针
  p = pTotReverseHead;
  while (p != -1) {
    printf("%05d %d ", p, L[p].data);
    (L[p].next != -1) ? printf("%05d\n", L[p].next) : printf("-1\n");
    p = L[p].next;
  }
  return 0;
}

// Copyright [2018] <mituh>
// 1075. 链表元素分类(25).cpp      09:16,09:40, 09:55(case 4,5), 22:21
/*
1075 链表元素分类(25)

给定一个单链表，请编写程序将链表元素进行分类排列，使得所有负值元素都排在非负值元素的前面，而 [0, K] 区间内的元素都排在大于 K 的元素前面。但每一类内部元素的顺序是不能改变的。例如：给定链表为 18→7→-4→0→5→-6→10→11→-2，K 为 10，则输出应该为 -4→-6→-2→7→0→5→10→18→11。

输入格式：

每个输入包含一个测试用例。每个测试用例第 1 行给出：第 1 个结点的地址；结点总个数，即正整数N (≤10
​5)；以及正整数K (≤10^3)。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：
Address Data Next
其中 Address 是结点地址；Data 是该结点保存的数据，为 [−10^5,10^5] 区间内的整数；Next 是下一结点的地址。题目保证给出的链表不为空。

输出格式：
对每个测试用例，按链表从头到尾的顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218

输出样例：
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
  int node_p;
  int rank;
  char addr[6];
  int data;
  char next[6];
};

bool cmp(Node n1, Node n2) {
  if (n1.rank != n2.rank) return n1.rank < n2.rank;
  return n1.node_p < n2.node_p;
}

int main() {
  char head[6]; int N, K;
  scanf("%s %d %d", head, &N, &K);
  unordered_map<string, Node> mp;
  for (int i = 0; i < N; i++) {
    Node node;
    scanf("%s %d %s", node.addr, &node.data, node.next);
    node.rank = node.data < 0 ? 0 : node.data <= K ? 1 : 2;
    mp[node.addr] = node;
  }

  vector<Node> v;
  char pNode[6];
  strcpy(pNode, head);
  int cnt = 0;
  while (strcmp(pNode, "-1") != 0) {
    auto it = mp.find(pNode);
    it->second.node_p = cnt++;
    v.push_back(it->second);
    strcpy(pNode, it->second.next);
  }

  sort(v.begin(), v.end(), cmp);
  int flag = 0;
  for (int i = 0; i < v.size(); i++) {    // case4, 不能用N, why?
    if (i != v.size()-1) {
      strcpy(v[i].next, v[i+1].addr);
    } else {
      strcpy(v[i].next, "-1");
    }
    if (flag) printf("\n");
    printf("%s %d %s", v[i].addr, v[i].data, v[i].next);
    flag = 1;
  }
  return 0;
}

// case5:
// 将所有string替换成char* str
// 赋值用strcpy(str1, str2); 比较用strcmp(str1, str2);



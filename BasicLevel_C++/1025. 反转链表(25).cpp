// Copyright [2018] <mituh>
// 1025. 反转链表(25).cpp     08:42->09:20(case6)->09:41
/*
1025 反转链表(25)

给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素不反转。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10^5)、以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：
Address Data Next
其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

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

#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


struct Node {
  char addr[6];
  int data;
  char next[6];
};

int main() {
  char head[6]; int N, K;
  scanf("%s %d %d", head, &N, &K);
  // unordered_map<char*, Node> mp;             // error, why?
  unordered_map<string, Node> mp;
  for (int i = 0; i < N; i++) {
    Node node;
    scanf("%s %d %s", node.addr, &node.data, node.next);
    mp[node.addr] = node;
  }

  vector<Node> v;
  char pNode[6]; strcpy(pNode, head);
  while (strcmp(pNode, "-1") != 0) {
    v.push_back(mp[pNode]);
    strcpy(pNode, mp[pNode].next);              // debug01
  }
  for (int i = 0; i < v.size()/K; i++) {        // case6
    reverse(v.begin()+i*K, v.begin()+i*K+K);    // 非哨兵元素
  }
  int flag = 0;
  for (int i = 0; i < v.size(); i++) {
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

/*
int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6};
  int N = v.size(), K = 3;
  for (int i = 0; i < N/K; i++) {
    reverse(v.begin()+i*K, v.begin()+i*K+K);    // 非哨兵元素
  }

  int flag = 0;
  for (int i = 0; i < v.size(); i++) {
    if (flag) printf(" ");
    printf("%d", v[i]);
    flag = 1;
  }
  printf("\n");
  return 0;
}

*/

/*
case6:
00100 4 2
00100 1 12309
12309 2 23333
77777 7 22222
23333 3 -1
*/

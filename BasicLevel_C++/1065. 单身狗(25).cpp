// Copyright [2018] <mituh>
// 1065. 单身狗(25).cpp   10:27->11:19, 用char*出现致命错误
/*
1065 单身狗（25 point(s)）
“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

输入格式：
输入第一行给出一个正整数 N（≤ 50 000），是已知夫妻/伴侣的对数；随后 N 行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个 ID 号，为 5 位数字（从 00000 到 99999），ID 间以空格分隔；之后给出一个正整数 M（≤ 10 000），为参加派对的总人数；随后一行给出这 M 位客人的 ID，以空格分隔。题目保证无人重婚或脚踩两条船。

输出格式：
首先第一行输出落单客人的总人数；随后第二行按 ID 递增顺序列出落单的客人。ID 间用 1 个空格分隔，行的首尾不得有多余空格。

输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333

输出样例：
5
10000 23333 44444 55555 88888
*/


#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int N; cin >> N;
  map<string, string> pairs;
  for (int i = 0; i < N; i++) {
    string id_a, id_b; cin >> id_a >> id_b;       // why? char*不可以
    pairs[id_a] = id_b;
    pairs[id_b] = id_a;
  }

  int M; cin >> M;
  map<string, int> mp;
  for (int i = 0; i < M; i++) {
    string id_tmp; cin >> id_tmp;

    if (pairs.count(id_tmp)) {
      auto it = mp.find(pairs[id_tmp]);
      if (it != mp.end()) {
        mp.erase(it);
      } else {
        mp[id_tmp] = 1;
      }
    } else {
      mp[id_tmp] = 1;
    }
  }

  cout << mp.size() << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) cout << " ";
    cout << it->first;
  }
  return 0;
}





/*

#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

// map<char*, char*> pairs;

int main() {
  int N; scanf("%d", &N);
  char id_a[6], id_b[6], id_tmp[6];
  map<char*, char*> pairs;
  while (N--) {
    scanf("%s %s", id_a, id_b);
    pairs[id_a] = id_b;
    pairs[id_b] = id_a;
    printf("==%s %s\n", pairs[id_a], pairs[id_b]);   // 错误
  }

  printf("size = %lu\n", pairs.size());
  for (auto it = pairs.begin(); it != pairs.end(); it++) {
    printf("%s ", it->first);
  }
  printf("\n");


  int M; scanf("%d", &M);
  map<char*, int> mp;
  for (int i = 0; i < M; i++) {
    scanf("%s", id_tmp);
    // auto it = mp.find(pairs[id_tmp]);
    if (pairs.count(id_tmp)) {
      printf("count\n");
      auto it = mp.find(pairs[id_tmp]);
      if (it != mp.end()) {
        mp.erase(it);
      } else {
        mp[id_tmp] = 1;
      }
    }

  }
  
  printf("%lu\n", mp.size());
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) printf(" ");
    printf("%s", it->first);
  }

  
  return 0;
}
*/


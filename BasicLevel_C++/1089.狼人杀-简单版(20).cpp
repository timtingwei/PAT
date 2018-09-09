// Copyright [2018] <mituh>
// 1089.狼人杀-简单版(20).cpp
/*
1089 狼人杀-简单版(20)
以下文字摘自《灵机一动·好玩的数学》：“狼人杀”游戏分为狼人、好人两大阵营。在一局“狼人杀”游戏中，1 号玩家说：“2 号是狼人”，2 号玩家说：“3 号是好人”，3 号玩家说：“4 号是狼人”，4 号玩家说：“5 号是好人”，5 号玩家说：“4 号是好人”。已知这 5 名玩家中有 2 人扮演狼人角色，有 2 人说的不是实话，有狼人撒谎但并不是所有狼人都在撒谎。扮演狼人角色的是哪两号玩家？

本题是这个问题的升级版：已知 N 名玩家中有 2 人扮演狼人角色，有 2 人说的不是实话，有狼人撒谎但并不是所有狼人都在撒谎。要求你找出扮演狼人角色的是哪几号玩家？

输入格式：

输入在第一行中给出一个正整数 N（5≤N≤100）。随后 N 行，第 i 行给出第 i 号玩家说的话（1≤i≤N），即一个玩家编号，用正号表示好人，负号表示狼人。

输出格式：

如果有解，在一行中按递增顺序输出 2 个狼人的编号，其间以空格分隔，行首尾不得有多余空格。如果解不唯一，则输出最小序列解 —— 即对于两个序列 A=a[1],...,a[M] 和 B=b[1],...,b[M]，若存在 0≤k<M 使得 a[i]=b[i] （i≤k），且 a[k+1]<b[k+1]，则称序列 A 小于序列 B。若无解则输出 No Solution。

输入样例 1：
5
-2
+3
-4
+5
+4

输出样例 1：
1 4

输入样例 2：
6
+6
+3
+1
-5
-2
+4

输出样例 2（解不唯一）：
1 5

输入样例 3：
5
-2
-3
-4
-5
-1

输出样例 3：
No Solution
*/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct Talk {
  int st;
  int id;
};

int main() {
  int N; scanf("%d", &N);
  vector<Talk> talk_v(N+1);
  int st_arr[105];

  for (int i = 1; i <= N; i++) {
    int temp = 0; scanf("%d", &temp);
    int st = 0, id = temp;
    if (temp < 0) {
      st = 1; id = -1 * temp;
    }
    Talk talk; talk.st = st; talk.id = id;
    talk_v[i] = talk;
  }

  int find = 0;
  for (int i = 1; i <= N-1; i++) {
    for (int j = i+1; j <= N; j++) {
      memset(st_arr, 0, sizeof(st_arr));

      st_arr[i] = 1; st_arr[j] = 1;
      vector<int> lier_v;
      for (int k = 1; k <= N; k++) {
        int id_k = talk_v[k].id, st_k = talk_v[k].st;
        if (st_arr[id_k] != st_k) {
          lier_v.push_back(k);
        }
      }

      if (lier_v.size() == 2) {
        int cnt = 0;
        for (int k = 0; k < 2; k++) {
          if (lier_v[k] == i || lier_v[k] == j) cnt++;
        }
        if (cnt == 1) {
          find = 1;
          printf("%d %d\n", i, j);
          break;
        }
      }
    }
    if (find) break;
  }
  if (!find) printf("No Solution\n");
  return 0;
}




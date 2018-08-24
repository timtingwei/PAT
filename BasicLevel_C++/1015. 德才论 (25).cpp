// Copyright [2018] <mituh>
// 1015. 德才论 (25).cpp    // 20 52 05 32(submit) 48 32(TLE) 36 -> 2h
/*
  思路: 排序, 写3个cmp? 1个cmp中先比较总分, 后比较得分, 再比较准考证号
  第一次在vector<int>中放id, 在map<int, vector<int>>中索引vector<int> 放另外德分和才分, 完全是多余的逻辑, 测试点2 3 4都超时. 而且我的超时不是因为cout/cin的使用
  修改, 把map去掉, id相关的数据放在Node结构体中, 修改cmp和遍历时的代码, 直接在vector中排序, AC

输入格式：

输入第1行给出3个正整数，分别为：N（<=10^5^），即考生总数；
L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；
H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

输出格式：

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
  char id[10];
  int dei, cai, score, rank;
};
const int MAXN = 100050;
Node nodes[MAXN];

bool cmp(Node n1, Node n2) {
  if (n1.rank != n2.rank) return n1.rank < n2.rank;
  if (n1.score != n2.score) return n1.score > n2.score;
  if (n1.dei != n2.dei) return n1.dei > n2.dei;
  return strcmp(n1.id, n2.id) < 0;
}

int main() {
  int N, L, H;
  scanf("%d %d %d", &N, &L, &H);
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    char id[10]; int dei, cai;
    scanf("%s %d %d", id, &dei, &cai);
    if (dei >= L && cai >= L) {
      int rank;
      if (cai >= H && dei >= H) rank = 1;
      else if (dei >= H && cai < H) rank = 2;
      else if (dei < H && cai < H && dei >= cai) rank = 3;
      else rank = 4;
      sscanf(id, "%s", nodes[cnt].id);   // why?
      // nodes[cnt].id = id;
      nodes[cnt].dei = dei;  nodes[cnt].cai = cai;
      nodes[cnt].score = dei + cai;
      nodes[cnt].rank = rank; cnt++;
    }
  }
  sort(nodes, nodes+cnt, cmp);
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) {
    if (i) printf("\n");
    printf("%s %d %d", nodes[i].id, nodes[i].dei,
           nodes[i].cai);
  }
  return 0;
}

/*
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// map<int, vector<int> > score;   // map结构不在用, 已经存在vector中

// node作为储存id, dei, cai的结构
typedef struct Node {
  int id;
  int dei;
  int cai;
  int add;
} node;

// 用cmp作为sort()第三个参数, 替换掉struct, 重载()运算符版本
bool cmp(const node n1, const node n2) {
  if (n1.add == n2.add) {  // 总分并列
    if (n1.dei == n2.dei) {  // 得分并列
      return n1.id < n2.id;   // 前一个准考准比后一个小, 准考证升序
    } else {   // 德分不并列, 总分并列
      return n1.dei > n2.dei;   // 德分降序
    }
  } else {  // 总分不并列
    return n1.add > n2.add;   // 总分降序
  }
}

int main() {
  int N, L, H;
  if (scanf("%d %d %d", &N, &L, &H) == 3 && N) {
    // 分类
    vector<node> vec1, vec2, vec3, vec4;
    for (int i = 0; i < N; i++) {
      node tmp;
      if (scanf("%d %d %d", &tmp.id, &tmp.dei, &tmp.cai) != EOF) {
        tmp.add = tmp.dei + tmp.cai;
        if (tmp.dei >= L && tmp.cai >= L) {  // 德才均不低于L
          if (tmp.dei >= H && tmp.cai >= H) {
            vec1.push_back(tmp);
          } else if (tmp.dei >= H && tmp.cai < H) {  // 德到, 才不到H
            vec2.push_back(tmp);
          } else if (tmp.dei < H && tmp.cai < H && tmp.dei >= tmp.cai) {
            // 德才均低于H, 德不低于才
            vec3.push_back(tmp);
          } else {
            vec4.push_back(tmp);
          }
        }
      }
    }
    // 排序
    sort(vec1.begin(), vec1.end(), cmp);
    sort(vec2.begin(), vec2.end(), cmp);
    sort(vec3.begin(), vec3.end(), cmp);
    sort(vec4.begin(), vec4.end(), cmp);
    printf("%lu\n", vec1.size()+vec2.size()+vec3.size()+vec4.size());
    // printf("vec1\n");
    for (int i = 0; i < vec1.size(); i++) {
      printf("%d %d %d\n", vec1[i].id, vec1[i].dei, vec1[i].cai);
    }
    // printf("vec2\n");
    for (int i = 0; i < vec2.size(); i++) {
      printf("%d %d %d\n", vec2[i].id, vec2[i].dei, vec2[i].cai);
    }
    // printf("vec3\n");
    for (int i = 0; i < vec3.size(); i++) {
      printf("%d %d %d\n", vec3[i].id, vec3[i].dei, vec3[i].cai);
    }
    // printf("vec4\n");
    for (int i = 0; i < vec4.size(); i++) {
      printf("%d %d %d\n", vec4[i].id, vec4[i].dei, vec4[i].cai);
    }
  }

  return 0;
}

*/

/*
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：

12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90

// after submit
14 93 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 93
10000013 90 94
10000014 66 60

*/

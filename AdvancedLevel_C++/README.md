## PAT-甲级

### 1025 PAT Ranking (25)（25 point(s)）

Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

#### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

#### Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

#### Sample Input:

2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:

9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4


#### Solution:

排序规则: 分数不同时, 分数高的在前; 分数相同时, 按照准考证号字典序排序

几个注意点:
1, 把一个考生的信息放进一个node, 跟我以前自己做时, 思路更清晰了。
2, 确定排名时, 分数不同不是简单的+1, 而是i+1, 即 1 2 2 4 5 5 5 8 ..
3, 字符串已经重载了所有的比较运算符, 可以直接用<比较
4, 在存储和输出排名时, 输出时, 边计算边打印

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Testee {
  string id;
  int score;
  int final_rank;
  int local_number;
  int local_rank;
};

vector<Testee> v;

bool cmp_score(Testee t1, Testee t2) {
  if (t1.score != t2.score) {
    return t1.score > t2.score;
  } else {
    return t1.id < t2.id;
  }
}

int main() {
  int N;
  cin >> N;
  for (int in = 0; in < N; in++) {
    int K; cin >> K;
    vector<Testee> tmp_v;
    for (int i = 0; i < K; i++) {
      Testee node;
      string id_t; int score_t;
      cin >> id_t >> score_t;
      node.id = id_t; node.score = score_t; node.local_number = in+1;
      tmp_v.push_back(node);
    }
    sort(tmp_v.begin(), tmp_v.end(), cmp_score);
    int r = 1;
    for (int i = 0; i < K; i++) {
      if (i > 0 && tmp_v[i].score != tmp_v[i-1].score) {
        r = i+1;
      }
      tmp_v[i].local_rank = r;
      v.push_back(tmp_v[i]);
    }
  }
  sort(v.begin(), v.end(), cmp_score);

  cout << v.size() << endl;
  int r = 1;
  for (int i = 0; i < v.size(); i++) {
    if (i > 0 && v[i].score != v[i-1].score) {
      r = i+1;
    }
    cout << v[i].id << " " << r << " "
         << v[i].local_number << " " << v[i].local_rank << endl;
  }

  return 0;
}

```


作死, 去掉vector, string, iostream的代码, 用下标管理数组, 标准IO用cstdio
不过是一次很好的尝试...用num计数, 排序属于原地排序, 不占用额外的内存..
但也让我知道..真的刷题时, 别用数组作西..

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Testee {
  char id[15];
  int score;
  int final_rank;
  int local_number;
  int local_rank;
} stu[100050];

bool cmp(Testee t1, Testee t2) {
  if (t1.score != t2.score) {
    return t1.score > t2.score;
  } else {
    return strcmp(t1.id, t2.id) < 0;
  }
}

int main() {
  int N, K, num = 0;
  scanf("%d", &N);
  for (int in = 0; in < N; in++) {
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
      scanf("%s %d", stu[num].id, &stu[num].score);
      stu[num].local_number = in+1;
      num++;
    }
    sort(stu+num-K, stu+num, cmp);
    int r = 1;
    stu[num-K].local_rank = 1;
    for (int i = num-K+1; i < num; i++) {
      if (stu[i].score == stu[i-1].score) {
        stu[i].local_rank = stu[i-1].local_rank;
      } else {
        stu[i].local_rank = i + 1 - (num-K);
      }
    }
  }
  sort(stu, stu+num, cmp);

  printf("%d\n", num);
  int r = 1;
  for (int i = 0; i < num; i++) {
    if (i > 0 && stu[i].score != stu[i-1].score) {
      r = i+1;
    }
    printf("%s %d %d %d\n", stu[i].id, r,
           stu[i].local_number, stu[i].local_rank);
  }
  return 0;
}
```

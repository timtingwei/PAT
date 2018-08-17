// Copyright [2018] <mituh>
// 1045. 快速排序(25).cpp    07:55 , 8:25(20), 9:00停止, 9:30发现思路漏洞
/*
1045 快速排序（25 point(s)）

著名的快速排序算法里有一个经典的划分过程：我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 给定划分后的 N 个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？

例如给定 $N = 5$, 排列是1、3、2、4、5。则：

1 的左边没有元素，右边的元素都比它大，所以它可能是主元；
尽管 3 的左边元素都比它小，但其右边的 2 比它小，所以它不能是主元；
尽管 2 的右边元素都比它大，但其左边的 3 比它大，所以它不能是主元；
类似原因，4 和 5 都可能是主元。
因此，有 3 个元素可能是主元。

输入格式：

输入在第 1 行中给出一个正整数 N（≤10
​5
​​ ）； 第 2 行是空格分隔的 N 个不同的正整数，每个数不超过 10
​9
​​ 。

输出格式：

在第 1 行中输出有可能是主元的元素个数；在第 2 行中按递增顺序输出这些元素，其间以 1 个空格分隔，行首尾不得有多余空格。

输入样例：

5
1 3 2 4 5
输出样例：

3
1 4 5
*/

/*
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, tmp;
  scanf("%d", &N);
  vector<int> v;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    v.push_back(tmp);
  }

  vector<int> ans;
  for (int p = 0; p < N; p++) {
    int i = p-1, j = p+1;
    while (i >= 0 && v[i] <= v[p]) i--;
    while (j < N && v[j] > v[p]) j++;
    if (i == -1 && j == N) {
      ans.push_back(v[p]);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%lu\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}

// case 1, 3 TE, 20分
*/


/*
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, tmp;
  scanf("%d", &N);
  vector<int> v;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    v.push_back(tmp);
  }

  vector<int> ans;
  vector<int> tmp_v = v;
  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++) {
    if (tmp_v[i] == v[i]) {
      int ok = 1;
      for (int j = i-1; j >= 0; j--) {
        if (tmp_v[j] >= tmp_v[i]) {ok = 0; break;}
      }
      if (ok) ans.push_back(v[i]);
    }
  }

  // sort(ans.begin(), ans.end());
  printf("%lu\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
*/

/*
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int const MAXN = 100050;
int ok[MAXN];
int main() {
  int N, tmp;
  scanf("%d", &N);
  memset(ok, 0, sizeof(ok));
  vector<int> v;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    v.push_back(tmp);
  }

  vector<int> ans;
  for (int i = 0; i < N-1; i++) {
    if (v[i] <= v[i+1]) ok[i] = 1;
  }
  ok[N-1] = 1;
  for (int j = N-1; j > 0; j--) {
    if (v[j] > v[j-1] && ok[j]) ans.push_back(v[j]);
  }
  if (ok[0]) ans.push_back(v[0]);

  sort(ans.begin(), ans.end());
  printf("%lu\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}

// case3, 5??? wrong answer..
*/


/*
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, tmp;
  scanf("%d", &N);
  vector<int> v;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    v.push_back(tmp);
  }


  vector<int> ans;
  vector<int> tmp_v = v;
  sort(v.begin(), v.end());
  // 排序后位置不变, 且原数组该位置左边元素均小于它
  for (int i = 0; i < N; i++) {
    if (tmp_v[i] == v[i]) {
      int ok = 1;
      for (int j = i-1; j >= 0; j--) {
        if (tmp_v[j] >= tmp_v[i]) {ok = 0; break;}
      }
      if (ok) ans.push_back(v[i]);
    }
  }

  printf("%lu\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}

// 仍旧超时
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, tmp;
  scanf("%d", &N);
  vector<int> v;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    v.push_back(tmp);
  }

  vector<int> ans;
  vector<int> tmp_v = v;
  sort(v.begin(), v.end());
  int max_i = 0;
  for (int i = 0; i < N; i++) {
    if (tmp_v[i] > tmp_v[max_i]) max_i = i;
    if (tmp_v[i] == v[i] && max_i == i) ans.push_back(tmp_v[i]);
  }

  printf("%lu\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}

/*
5
6 2 4 3 1
1 2 3 4 6

3
1 1 1
1
1
*/


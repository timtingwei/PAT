## Basic-PAT-C++

### 1020 -u

```cpp
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct food {
  double scale, each_scale;
  double cnt;
};

struct cmp {
  bool operator() (const food &f1, const food &f2) {
    return f1.each_scale < f2.each_scale;
  }
};

bool db_equal(const double d1, const double d2) {
  return -0.0005 < d1-d2 && d1-d2 < 0.00005;
}

int main() {
  int N;
  double need; scanf("%d %lf", &N, &need);
  vector<food> v(N);
  priority_queue<food, vector<food>, cmp> q;
  for (int i = 0; i < N; i++) {
    scanf("%lf", &v[i].cnt);
  }
  for (int i = 0; i < N; i++) {
    scanf("%lf", &v[i].scale);
    v[i].each_scale = v[i].scale / v[i].cnt;
    q.push(v[i]);
  }
  double profit = 0.0;
  while (!db_equal(need, 0.0) && !q.empty()) {
    if (q.top().cnt > need) {
      profit += q.top().each_scale * need;
      need = 0;
    } else {  // <= need
      profit += q.top().scale;
      need -= q.top().cnt;
      q.pop();
    }
    if (q.empty()) break;
  }
  printf("%.2lf", profit);
  return 0;
}
```

// Copyright [2018] <mituh>
// priority-queue.cpp

/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  // begin
  priority_queue<int> q;   // priorit_queue<int, vector<int>, less<int> > q;
  q.push(3);
  q.push(4);
  q.push(1);
  cout << q.top() << endl;
  return 0;
}
*/

/*
int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  // begin
  priority_queue<int, vector<int>, greater<int> > q;
  q.push(3);
  q.push(4);
  q.push(1);
  cout << q.top() << endl;
  return 0;
}*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct fruit {
  string name;
  double price;
};

struct cmp {
  bool operator () (fruit f1, fruit f2) {
    return f1.price < f2.price;    // 竟然是反着来的
  }
};

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  // begin
  // 水果价格从高到低
  priority_queue<fruit, vector<fruit>, cmp> q;
  fruit f1, f2, f3;
  f1.name = "peach"; f1.price = 13.22;
  f2.name = "apple"; f2.price = 15.31;
  f3.name = "pear";  f3.price = 11.42;
  q.push(f1);
  q.push(f2);
  q.push(f3);
  cout << q.top().name << " " << q.top().price << endl;
  q.pop();
  cout << q.top().name << " " << q.top().price << endl;
  q.pop();
  cout << q.top().name << " " << q.top().price << endl;
  q.pop();
  return 0;
}

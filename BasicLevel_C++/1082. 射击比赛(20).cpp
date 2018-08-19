// Copyright [2018] <mituh>
// 1082. 射击比赛(20).cpp    05:35->05:52
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node{
  string id;
  double delta;
};
int main() {
  int N; cin >> N;

  Node max_n, min_n;
  max_n.delta = 0; min_n.delta = 100;
  while (N--) {
    string id; int x, y;
    cin >> id >> x >> y;
    x = abs(x); y = abs(y);
    double delta = sqrt(x*x + y*y);
    if (delta > max_n.delta) {
      max_n.delta = delta;
      max_n.id = id;
    }
    if (delta < min_n.delta) {
      min_n.delta = delta;
      min_n.id = id;
    }
  }
  cout << min_n.id << " " << max_n.id << endl;
  return 0;
}

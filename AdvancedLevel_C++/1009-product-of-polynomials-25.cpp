// Copyright [2018] <mituh>
// 1009-product-of-polynomials-25.cpp   04:08， 4:35, 05:05, 05:15
/*
1009 Product of Polynomials(25)

This time, you are supposed to find A×B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

where K is the number of nonzero terms in the polynomial, N​i and aNi(i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10, 0≤NK<⋯<N2<N1≤1000.

Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output:
3 3 3.6 2 6.0 1 1.6
*/
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
bool cmp(unordered_map it1, auto it2) {
  return (it1->first) > (it2->first);
}
*/
struct Node {
  int n;
  double a;
};

bool cmp(Node n1, Node n2) {
  return n1.n > n2.n;
}

int main() {
  unordered_map<int, double> poly1, poly2, ans;
  vector<Node> v;
  int N, M;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int n; double a; scanf("%d %lf", &n, &a);
    auto it = poly1.find(n);
    if (it != poly1.end()) {
      it->second += a;
    } else {
      poly1[n] = a;
    }
  }
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    int n; double a; scanf("%d %lf", &n, &a);
    auto it = poly2.find(n);
    if (it != poly2.end()) {
      it->second += a;
    } else {
      poly2[n] = a;
    }
  }

  for (auto it1 = poly1.begin(); it1 != poly1.end(); it1++) {
    for (auto it2 = poly2.begin(); it2 != poly2.end(); it2++) {
      int n = it1->first + it2->first;
      double a = it1->second * it2->second;
      auto it_ans = ans.find(n);
      if (it_ans != ans.end()) {
        it_ans->second += a;
      } else {
        ans[n] = a;
      }
    }
  }
  for (auto it = ans.begin(); it != ans.end(); it++) {
    if (it->second-0.0 < -0.0005 || it->second-0.0 > 0.0005) {   // case1
      v.push_back(Node{it->first, it->second});
    }
  }
  sort(v.begin(), v.end(), cmp);
  printf("%lu", v.size());
  for (int i = 0; i < v.size(); i++) {
    printf(" %d %.1lf", v[i].n, v[i].a);
  }
  // for (auto it = ans.begin(); it != ans.end(); it++) {
  //   printf(" %d %.1lf", it->first, it->second);
  // }
  return 0;
}





## PAT-甲级

### 1005 Spell It Right(20) -u

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

#### Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (≤10
​100
​​ ).

#### Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

#### Sample Input:
12345

#### Sample Output:
one five


#### Solution:
```cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

char num[200];
int main() {
  string dict[10] = {"zero", "one", "two", "three", "four",
                   "five", "six", "seven", "eight", "nine"};
  scanf("%s", num);
  int sum = 0;
  for (int i = 0; i < strlen(num); i++) {
    sum += num[i]-'0';
  }
  string s = to_string(sum); int flag = 0;
  for (char ch : s) {
    if (flag) cout << " ";
    cout << dict[ch - '0'];
    flag = 1;
  }
  return 0;
}
```


### 1006 Sign In and Sign Out(25) -uw

At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:
Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.

Output Specification:
For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

Sample Output:
SC3021234 CS301133
*/


```cpp
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
  char id[20];
  char in_time[15];
  char out_time[15];
};

bool cmp1(Node n1, Node n2) {
  return strcmp(n1.in_time, n2.in_time) < 0;
}

bool cmp2(Node n1, Node n2) {
  return strcmp(n1.out_time, n2.out_time) > 0;
}

vector<Node> v;

int main() {
  int M; scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    Node n;
    scanf("%s %s %s", n.id, n.in_time, n.out_time);
    v.push_back(n);
  }
  sort(v.begin(), v.end(), cmp1);
  printf("%s ", v[0].id);
  sort(v.begin(), v.end(), cmp2);
  printf("%s", v[0].id);
  return 0;
}
```


### 1008 Elevator(20) -uw

The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:
For each test case, print the total time on a single line.

Sample Input:
3 2 3 1

Sample Output:
41

```cpp
#include <cstdio>

int main() {
  int N; scanf("%d", &N);
  int floor = 0, time = 0;
  for (int i = 0; i < N; i++) {
    int t; scanf("%d", &t);
    time += (t > floor) ? (t-floor)*6 : (floor-t)*4;
    floor = t;
  }
  time += N * 5;
  printf("%d", time);
  return 0;
}
```


### 1009 Product of Polynomials(25) -uw

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

```cpp
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
```





### 1011 World Cup Betting(20) -uw

With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.

Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds are given as the following:
 W    T    L
1.1  2.5  1.7
1.2  3.1  1.6
4.1  1.2  1.1

To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1×3.1×2.5×65%−1)×2=39.31 yuans (accurate up to 2 decimal places).

Input Specification:
Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.

Output Specification:
For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.

Sample Input:
1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1

Sample Output:
T T W 39.31

```cpp
#include <cstdio>

char chs[3] = {'W', 'T', 'L'};
int main() {
  int flag = 0;
  double sum = 1;
  for (int i = 0; i < 3; i++) {
    double arr[3];
    scanf("%lf %lf %lf", &arr[0], &arr[1], &arr[2]);

    int pos = arr[0] > arr[1] ? arr[0] > arr[2] ? 0 : 2 : arr[1] > arr[2] ? 1 : 2;
    if (flag) printf(" ");
    printf("%c", chs[pos]);
    flag = 1;

    sum *= arr[pos];
  }
  sum = (sum * 0.65 - 1) * 2;
  printf(" %.2lf", sum);
  return 0;
}
```

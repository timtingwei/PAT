// Copyright [2018] <mituh>
// 1068. 万绿丛中一点红(20).cpp  11:26 -> 12:07->12:30->1:10
/*
1068. 万绿丛中一点红（20 point(s)）

对于计算机而言，颜色不过是像素点对应的一个 24 位的数值。现给定一幅分辨率为 M×N 的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，并且该点的颜色与其周围 8 个相邻像素的颜色差充分大。

输入格式：

输入第一行给出三个正整数，分别是 M 和 N（≤ 1000），即图像的分辨率；以及 TOL，是所求像素点与相邻点的颜色差阈值，色差超过 TOL 的点才被考虑。随后 N 行，每行给出 M 个像素的颜色值，范围在 [0,2
​24
​​ ) 内。所有同行数字间用空格或 TAB 分开。

输出格式：

在一行中按照 (x, y): color 的格式输出所求像素点的位置以及颜色值，其中位置 x 和 y 分别是该像素在图像矩阵中的列、行编号（从 1 开始编号）。如果这样的点不唯一，则输出 Not Unique；如果这样的点不存在，则输出 Not Exist。

输入样例 1：

8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
输出样例 1：
(5, 3): 16711680

输入样例 2：
4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0

输出样例 2：
Not Unique

输入样例 3：
3 3 5
1 2 3
3 4 5
5 6 7

输出样例 3：
Not Exist
*/

/*
debug:

Error1:
4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0
(3, 2): 3

// 充分大并不意味着最大..


3 3 5
1 2 3
3 4 5
5 6 7
Not Unique
*/


// case5
/*
1 1 2
2
*/


#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
struct Node {
  int x;
  int y;
  int color;
  int cnt;
};   // bug01

const int MAXN = 16777300;     // pow(2, 24) + 50;  // bug02
const int MAXM = 1100;
Node dup_color[MAXN];
int a[MAXM][MAXM];

int grid[9][3] = {{-1, -1}, {-1, 0}, {-1, 1},        // bug03, 不能定义成move
                  {0 , -1},          {0, 1},
                  {1,  -1}, {1 , 0}, {1, 1}};

void test_printf_show(vector<Node> v) {
  for (int i = 0; i < v.size(); i++) {
    printf("x = %d, y = %d, color = %d\n", v[i].x, v[i].y, v[i].color);
  }
  printf("\n");
}

int main() {
  int M, N, TOL;
  scanf("%d %d %d", &M, &N, &TOL);
  // memset(dup_color, 0, sizeof(dup_color));  // memset导致空间不足case1,2,3..
  // memset(a, 0, sizeof(a));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int id; scanf("%d", &id);
      a[i][j] = id;
      if (dup_color[id].cnt == 0) {
        dup_color[id].color = id;
        dup_color[id].x = i; dup_color[id].y = j;
      }
      dup_color[id].cnt++;
    }
  }
  if (M == 1 && N == 1) {
    printf("(1, 1): %d\n", a[0][0]);
    return 0;
  }
  vector<Node> v; vector<Node> max_v;
  for (int i = 0; i < MAXN; i++) {
    if (dup_color[i].cnt == 1) {
      v.push_back(dup_color[i]);
    }
  }
// test_printf_show(v);
  int max_d = 0;
  for (int iv = 0; iv < v.size(); iv++) {
    int i = v[iv].x, j = v[iv].y, color = v[iv].color;   // 难道是色彩均超过TOL?
    int delta = 0, ok = 1;
    for (int k = 0; k < 8; k++) {
      int x = i + grid[k][0], y = j + grid[k][1];
      if (0 <= x && x < M && 0 <= y && y < N) {
        int color_b = a[x][y];
// printf("delta = %d\n", abs(color_b-color));
        int dd = abs(color_b-color);
        if (dd > TOL) {                                  // 单个超过TOL
          delta += dd;                          // bug03:充分大,不是最大
        } else {
          ok = 0;
        }
      }
    }
// printf("\n");
    if (ok && delta != 0) {        // to?
// printf("delta total = %d\n", delta);
      max_v.push_back(v[iv]);
    }
    // if (delta > max_d) {
    //   max_d = delta; max_v.clear(); max_v.push_back(v[iv]);
    // } else if (delta == max_d) {
    //   max_v.push_back(v[iv]);
  }
// test_printf_show(max_v);
  if (max_v.size() == 1) {
    // printf("(%d, %d): %d\n", max_v[0].x+1, max_v[0].y+1, max_v[0].color);
    printf("(%d, %d): %d\n", max_v[0].y+1, max_v[0].x+1, max_v[0].color);
  } else if (max_v.size() == 0) {
    printf("Not Exist\n");
  } else {
    printf("Not Unique\n");
  }
  return 0;
}


// copyright [2018] <mituh>
// 1005. 继续(3n+1)猜想 (25).cpp
/*
  思路:
  1, 每个n, 生成所需计算的数组an
  2, 遍历n, n在其他数组an中一旦出现的就不是关键字, 没找到就是关键字
 */
#include <stdio.h>
#include <string.h>
int a[105][105];
int a_cnt[105];
int b[105];    // 输入的不同n存放的地方
int ans[105];
int ans_cnt = 0;

int main() {
  int k;
  if (scanf("%d", &k) == 1) {
    // 1, 每个n, 生成所需计算的数组an
    for (int i = 0; i < k; i++) {
      scanf("%d", &b[i]);
      int n = b[i];
      int cnt = 0;
      a[i][cnt++] = n;
      // printf("%d ", n);
      while (n != 1) {
        if (n%2) {
          n = (3*n+1) / 2;
        } else {
          n /= 2;
        }
        a[i][cnt++] = n;
        // printf("%d ", n);
      }
      // printf("\n");
      a_cnt[i] = cnt;
    }

    // 2, 遍历b, b在a的其他数组中一旦出现的就不是关键字, 没找到就是关键字
    for (int i = 0; i < k; i++) {
      int find = 0;
      for (int j = 0; j < k; j++) {
        if (i == j) continue;  // 不检查自身数组
        for (int x = 0; x < a_cnt[j]; x++) {
          if (b[i] == a[j][x]) {find = 1; break;}
        }
        if (find) break;
      }
      if (!find) ans[ans_cnt++] =  b[i];  // 唯一的出现, 是关键字
    }

    // 对关键字排序
    for (int i = 0; i < ans_cnt-1; i++) {
      for (int j = i + 1; j < ans_cnt; j++) {
        if (ans[j] > ans[i]) {
          int t = 0;
          t = ans[i]; ans[i] = ans[j]; ans[j] = t;
        }
      }
    }

    // 输出
    for (int i = 0; i < ans_cnt-1; i++) {printf("%d ", ans[i]);}
    printf("%d\n", ans[ans_cnt-1]);
  }

  return 0;
}

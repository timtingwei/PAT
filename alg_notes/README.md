# 《算法笔记》

## 2.5

### 2.5.7 sscanf 和 sprintf

sscanf  分解字符数组, 从 字符数组 ->读入-> 其他变量
```cpp
sscanf(str, "%d/%lf,%s", &n, &db, str2);
```

sprintf 打印到字符串, 将 其他变量 ->写入-> 字符数组
```cpp
sprintf(str, "%s:%.2f", name, score);
```

还支持正则表达式

## 4.1 排序

## 4.6 two pointers
### 4.6.1 什么是two pointers
#### 求递增数列中两个数之和为M的数a, b
```cpp
/*
给定一个递增的正整数数列和一个整数M, 求序列中的两个不同位置的数a和b, 使得他们的和恰好为M, 输出所有满足条件的方案
*/


/*
// 朴素版本 O(n^2)
#include <cstdio>
int main() {
  int a[] = {1, 3, 4, 5, 7, 2};
  int n = 6;
  int M = 8;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (a[i] + a[j] == M) printf("%d %d\n", a[i], a[j]);
    }
  }  // O(n^2)

  return 0;
}
*/


#include <cstdio>
int main() {
  int a[] = {1, 2, 3, 4, 5, 7}; int n = 6;
  int M = 8;

  int i = 0, j = n - 1;
  while (i < j) {
    if (a[i] + a[j] == M) {
      printf("%d %d\n", a[i], a[j]);
      i++; j--;
    } else if (a[i] + a[j] < M) {
      i++;
    } else {
      j--;
    }
  }
  return 0;
}

```
#### 合并两个递增序列
```cpp
#include <cstdio>
#include <cstring>

int merge(int a[], int b[], int c[], int n, int m) {
  int i = 0, j = 0, cnt = 0;
  while (i < n && j < m) {
    c[cnt++] = a[i] < b[j] ? a[i++]:b[j++];
  }
  while (i < n) c[cnt++] = a[i++];
  while (j < m) c[cnt++] = b[j++];

  return cnt;
}

int main() {
  int a[] = {1, 3, 4, 7}; int n = 4;
  int b[] = {2, 3, 5, 6, 8, 9}; int m = 6;
  // int a[] = {1, 2, 3}; int n = 3;
  // int b[] = {4, 5, 6, 7, 8}; int m = 5;
  int c[20]; memset(c, 0, sizeof(c));

  int cnt = merge(a, b, c, n, m);
  
  for (int i = 0; i < cnt; i++) {
    printf("%d ", c[i]);
  }
  printf("\n");
  return 0;
}
```

广义two pointers是利用问题和数列的特性, 用两个下标i, j对序列进行扫描(可以同向,也可以反向), 以较低的复杂(一般是O(n), 合起来扫描一遍, 或者如合并一样O(n+m))解决问题。
### 4.6.2 归并排序
### 4.6.3 快速排序

先实现一个two pointers确定排序, 并确定分割点的函数

```cpp
int Partition(int A[], int left, int right) {
  int temp = A[left];
  while (left < right) {
    while (left < right && temp < A[right]) right--;
    A[left] = A[right];
    while (left < right && A[left] <= temp) left++;
    A[right] = A[left];
  }
  A[left] = temp;
  return left;
}
```

然后写出快速排序的递归函数, 主要会忘记left < right的边界条件
```cpp
void quickSort(int A[], int left, int right) {
  if (left < right) {
    pos = Partition(A, left, right);
    quickSort(A, left,  pos - 1);
    quickSort(A, pos+1, right);
  }
}
```


快速排序算法当序列中元素的排列比较随机时, 效率最高, 但是当序列中元素接近有序时, 达到最坏的O(n^2)复杂度。
主要原因是, 主元pos没有把当前的数列划分成两个长度接近的区间。
即使能够使得两个长度接近, 最坏时间复杂度也是O(n^2), 但是可以通过`随机算法`达到期望的O(nlogn)的复杂度


#### 生成随机数的朴素方法:

```cpp
#include <stdlib>
#include <time>

int main() {
  srand((unsigned)time(NULL));
  int a = 10, b = 90;
  for (int i = 0; i < 10; i++) {
    printf("%d ", rand() % (b-a+1) + a);      // 生成[a, b]范围的随机数
  }
  return 0;
}
```

`rand() % (b-a+1) + a`这种方法针对于左右端点相差不超过RAND_MAX的区间的随机数


#### 生成大范围的随机数的一种方法

`(int)(round(1.0*rand()/RAND_MAX*(hi-lo) + lo))`

#### 根据上面两种随机数的做法, 修改Partition函数

根据之前的随机函数, 生成p是在left到right中随机的一个数, 也就是索引。
交换p和left所指向的元素, 之后仍旧按照头元素分割数列。
```cpp
int Partition_random(int A[], int left, int right) {
  int p = (int)round(1.0*rand()/RAND_MAX*(right-left) + left);
  swap(A, left, p);
  int temp = A[left];
  while (left < right) {
    while (left < right && temp < A[right]) right--;
    A[left] = A[right];
    while (left < right && A[left] <= temp) left++;
    A[right] = A[left];
  }
  A[left] = temp;
  return left;
}
```


递归的版本又写错了, 这个递归中没有while, 如果递归中还有while的话.. 这个逻辑太嵌套了..
```cpp
void quickSort(int A[], int left, int right) {
  // while (left < right) {
  if (left < right) {
    int pos = Partition_random(A, left, right);
    printf("pos = %d\n", pos);
    quickSort(A, left,    pos - 1);
    quickSort(A, pos + 1, right);
  }
}
```

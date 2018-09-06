## Basic-PAT-C++

### 1062 最简分数(20)

一个分数一般写成两个整数相除的形式：N/M，其中 M 不为0。最简分数是指分子和分母没有公约数的分数表示形式。

现给定两个不相等的正分数 N1/M1和 N2/M2，要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。

#### 输入格式：
输入在一行中按 N/M 的格式给出两个正分数，随后是一个正整数分母 K，其间以空格分隔。题目保证给出的所有整数都不超过 1000。

#### 输出格式：
在一行中按 N/M 的格式列出两个给定分数之间分母为 K 的所有最简分数，按从小到大的顺序，其间以 1 个空格分隔。行首尾不得有多余空格。题目保证至少有 1 个输出。

#### 输入样例：
7/18 13/20 12

#### 输出样例：
5/12 7/12

#### Solution:

// 134WA

/*
2/3 -4/2
2/3 + (-2 0/2) = (-1 2/6)
2/3 - (-2 0/2) = 2 4/6
2/3 * (-2 0/2) = (-1 2/6)
2/3 / (-2 0/2) = 0 4/-12
*/

// debug01

// 34WA

// debug02 long long


```cpp
#include <cstdio>
struct Fraction {
  long long up, down;
};

long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}

void reduction(Fraction &f) {
  if (!f.down) return;  // Inf
  // if (!f.up) f.down = 1; return;  // 0      // debug01
  if (!f.up) {
    f.down = 1; return;
  }
  if (f.down < 0) {   // down<0
    f.up *= -1;
    f.down *= -1;
  }
  long long up_t = f.up, g = 0;
  if (f.up < 0) up_t = -1 * f.up;
  g = gcd(up_t, f.down);
  if (g > 1) {
    f.up /= g;
    f.down /= g;
  }
  // g == 1 ok
}

Fraction add(Fraction a, Fraction b) {
  Fraction f;
  f.up = a.up * b.down + b.up * a.down;
  f.down = a.down * b.down;
  reduction(f);
  return f;
}

Fraction minus(Fraction a, Fraction b) {
  Fraction f;
  f.up = a.up * b.down - b.up * a.down;
  f.down = a.down * b.down;
  reduction(f);
  return f;
}

Fraction multi(Fraction a, Fraction b) {
  Fraction f;
  f.up = a.up * b.up;
  f.down = a.down * b.down;
  reduction(f);
  return f;
}

Fraction divide(Fraction a, Fraction b) {
  Fraction f;
  f.up = a.up * b.down;
  f.down = a.down * b.up;
  reduction(f);
  return f;
}


long long rabs(long long n) {
  return n < 0 ? -n : n;
}

void show(Fraction f) {
  if (!f.down) {
    printf("Inf"); return;
  }
  if (!f.up) {
    printf("0"); return;
  }

  if (f.up < 0) printf("(-");   // (-

  if (f.down == 1) {  // ok->int
    printf("%lld", rabs(f.up));
    if (f.up < 0) printf(")");   // )
    return;
  }

  if (rabs(f.up) < f.down) {     // no int, attetion
    printf("%lld/%lld", rabs(f.up), f.down);
  } else {
    long long a = rabs(f.up) / f.down;
    long long b = rabs(f.up) - a*f.down;
    printf("%lld %lld/%lld", a, b, f.down);
  }
  if (f.up < 0) printf(")");     // )
}

int main() {
  Fraction a, b;
  scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
  reduction(a); reduction(b);
  show(a); printf(" + "); show(b); printf(" = "); show(add(a, b)); printf("\n");
  show(a); printf(" - "); show(b); printf(" = "); show(minus(a, b)); printf("\n");
  show(a); printf(" * "); show(b); printf(" = "); show(multi(a, b)); printf("\n");
  show(a); printf(" / "); show(b); printf(" = "); show(divide(a, b)); printf("\n");
  return 0;
}

```

// Copyright [2018] <mituh>
// 1034. 有理数四则运算(20).cpp
/*
1034 有理数四则运算（20 point(s)）
本题要求编写程序，计算 2 个有理数的和、差、积、商。

输入格式：
输入在一行中按照 a1/b1 a2/b2 的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为 0。

输出格式：
分别在 4 行中按照 有理数1 运算符 有理数2 = 结果 的格式顺序输出 2 个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式 k a/b，其中 k 是整数部分，a/b 是最简分数部分；若为负数，则须加括号；若除法分母为 0，则输出 Inf。题目保证正确的输出中没有超过整型范围的整数。

输入样例 1：
2/3 -4/2

输出样例 1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

输入样例 2：
5/3 0/6

输出样例 2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/


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

// ----- 以上20180907

/*

// 四则运算
// debug01 运算后没有reduction
// debug02 整数部分存在, 小数部分整数为0的情况, 打印错误, abs引用
// debug03 约分时, 若为复数, 分母为正, 分子为负
// debug04 (-1 -1/3) 最简形式是应写成(-1 1/3)
// debug05 整数部分为0
// debug06 结果为双负数的情况
// case3   int需要用long long
#include <cstdio>
#include <cmath>

struct Fraction {
  Fraction(long long a = 0, long long b = 0) : up(a), down(b) {}
  long long up, down;
};

long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}

long long rabs(long long a) {
  return a < 0 ? -a : a;
}


void reduction(Fraction &f) {
  if (f.down == 0) return;
  if ((f.up < 0 && f.down > 0) ||
      (f.down < 0 && f.up > 0)) {    // debug05
    f.up = -rabs(f.up); f.down = rabs(f.down);
  } else if (f.up < 0 && f.down < 0) {            // debug06
    f.up = -f.up; f.down = -f.down;
  } else if (f.up == 0) {
    f.down = 1;
  }

  long long g = gcd(rabs(f.up), rabs(f.down));           // debug03
  f.up /= g; f.down /= g;
}

Fraction add(Fraction f1, Fraction f2) {
  Fraction nf(f1.up*f2.down + f2.up*f1.down,
              f1.down*f2.down);
  reduction(nf);                            // debug01
  return nf;
}

Fraction minus(Fraction f1, Fraction f2) {
  Fraction nf(f1.up * f2.down - f2.up * f1.down,
              f1.down * f2.down);
  reduction(nf);
  return nf;
}

Fraction multi(Fraction f1, Fraction f2) {
  Fraction nf(f1.up * f2.up,
              f1.down * f2.down);
  reduction(nf);
  return nf;
}

Fraction divide(Fraction f1, Fraction f2) {
  Fraction nf(f1.up * f2.down,
              f2.up * f1.down);
  reduction(nf);
  return nf;
}

void print_fraction(Fraction f_rst) {
  if (f_rst.down == 0) {
    printf("Inf");
  } else {
    if (f_rst.up == 0) {
      printf("0"); return;
    }
    if (rabs(f_rst.up) >= f_rst.down) {
      long long a = f_rst.up / f_rst.down;                      // debug02
      long long b = rabs(f_rst.up - f_rst.down * a);            // debug04
      if (f_rst.up < 0) {
        printf("(%lld", a);
        if (b != 0) {
          printf(" %lld/%lld", b, f_rst.down);
        }
        printf(")");
      } else {
        printf("%lld", a);
        if (b != 0) {
          printf(" %lld/%lld", b, f_rst.down);
        }
      }
    } else {
      if (f_rst.up < 0) {
        printf("(%lld/%lld)", f_rst.up, f_rst.down);
      } else {
        printf("%lld/%lld", f_rst.up, f_rst.down);
      }
    }
  }
}

void print_f1f2(Fraction f1, char op, Fraction f2) {
  print_fraction(f1); printf(" %c ", op);
  print_fraction(f2); printf(" = ");
}


int main() {
  char str1[30], str2[30];
  scanf("%s %s", str1, str2);
  long long up1, down1, up2, down2;
  sscanf(str1, "%lld/%lld", &up1, &down1);
  sscanf(str2, "%lld/%lld", &up2, &down2);
  Fraction f1(up1, down1), f2(up2, down2);
  print_f1f2(f1, '+', f2); print_fraction(add(f1, f2));     printf("\n");
  print_f1f2(f1, '-', f2); print_fraction(minus(f1, f2));   printf("\n");
  print_f1f2(f1, '*', f2); print_fraction(multi(f1, f2));   printf("\n");
  print_f1f2(f1, '/', f2); print_fraction(divide(f1, f2));  printf("\n");
  return 0;
}
*/

/*
-3/2 -4/3
(-1 1/2) + (-1 1/3) = (-2 5/6)
(-1 1/2) - (-1 1/3) = (-1/6)
(-1 1/2) * (-1 1/3) = 2
(-1 1/2) / (-1 1/3) = (1 1/-8)
*/


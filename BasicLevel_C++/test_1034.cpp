// Copyright [2018] <mituh>
// 1034. 有理数四则运算(20).cpp
// 四则运算
// debug01 运算后没有reduction
// debug02 整数部分存在, 小数部分整数为0的情况, 打印错误, abs引用
// debug03 约分时, 若为复数, 分母为正, 分子为负
// debug04 (-1 -1/3) 最简形式是应写成(-1 1/3)
// debug05 整数部分为0
// debug06 结果为双负数的情况
#include <cstdio>
#include <cmath>

struct Fraction {
  // Fraction(int a, int b) {
  //   up = a; down = b;
  // }
  Fraction(int a = 0, int b = 0) : up(a), down(b) {}
  int up, down;
};

int gcd(int a, int b) {
// printf("gcd: a = %d, b = %d\n", a, b);
  return !b ? a : gcd(b, a % b);
}

int rabs(int a) {
  return a < 0 ? -a : a;
}

void reduction(Fraction &f) {
  if (f.down == 0) return;
  // printf("f.up = %d, f.down = %d, %d\n", f.up, f.down, f.up/f.down);
  // if (f.up / f.down < 0) {
  if ((f.up < 0 && f.down > 0) ||
      (f.down < 0 && f.up > 0)) {    // debug05
    f.up = -rabs(f.up); f.down = rabs(f.down);
    // printf("--  %d %d\n", f.up, f.down);
  } else if (f.up < 0 && f.down < 0) {            // debug06
    f.up = -f.up; f.down = -f.down;
  } else if (f.up == 0) {
    f.down = 1;
  }

  int g = gcd(rabs(f.up), f.down);           // debug03
  // printf("\nf.down = %d, g = %d\n", f.down, g);
  f.up /= g; f.down /= g;
}

Fraction add(Fraction f1, Fraction f2) {
  Fraction nf(f1.up*f2.down + f2.up*f1.down,
              f1.down*f2.down);
  reduction(nf);                            // debug01
// printf("%d %d\n", nf.up, nf.down);
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
  // printf("%d %d\n", nf.up, nf.down);
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
      int a = f_rst.up / f_rst.down;                      // debug02
      // printf("a = %d\n", a);
      int b = rabs(f_rst.up - f_rst.down * a);            // debug04
      if (f_rst.up < 0) {
        printf("(%d", a);
        if (b != 0) {
          printf(" %d/%d", b, f_rst.down);
        }
        printf(")");
      } else {
        printf("%d", a);
        if (b != 0) {
          printf(" %d/%d", b, f_rst.down);
        }
      }
    } else {
      if (f_rst.up < 0) {
        printf("(%d/%d)", f_rst.up, f_rst.down);
      } else {
        printf("%d/%d", f_rst.up, f_rst.down);
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
  int up1, down1, up2, down2;
  sscanf(str1, "%d/%d", &up1, &down1);
  sscanf(str2, "%d/%d", &up2, &down2);
// printf("%d %d %d %d\n", up1, down1, up2, down2);
  Fraction f1(up1, down1), f2(up2, down2);
  Fraction nf = divide(f1, f2);
  // printf("nf: %d %d\n", nf.up, nf.down);
  print_f1f2(f1, '+', f2); print_fraction(add(f1, f2));     printf("\n");
  print_f1f2(f1, '-', f2); print_fraction(minus(f1, f2));   printf("\n");
  print_f1f2(f1, '*', f2); print_fraction(multi(f1, f2));   printf("\n");
  print_f1f2(f1, '/', f2); print_fraction(nf);  printf("\n");
  return 0;
}


/*
-3/2 -4/3
(-1 1/2) + (-1 1/3) = (-2 5/6)
(-1 1/2) - (-1 1/3) = (-1/6)
(-1 1/2) * (-1 1/3) = 2
(-1 1/2) / (-1 1/3) = (1 1/-8)
*/


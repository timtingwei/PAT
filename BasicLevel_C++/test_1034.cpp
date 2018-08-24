// Copyright [2018] <mituh>
// 1034. 有理数四则运算(20).cpp
// 四则运算
#include <cstdio>
#include <cmath>
using namespace std;
struct Fraction {
  // Fraction(int a, int b) {
  //   up = a; down = b;
  // }
  Fraction(int a = 0, int b = 0) : up(a), down(b) {}
  int up, down;
};

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int rabs(int &a) {
  return a = a < 0 ? -a : a;
}

void reduction(Fraction &f) {
  if (f.down == 0) return;
  if (f.up / f.down < 0) {
    f.up = -rabs(f.up); f.down = rabs(f.down);
  } else if (f.up == 0) {
    f.down = 1;
  }

  int g = gcd(f.up, f.down);
  f.up /= g; f.down /= g;
}

Fraction add(Fraction f1, Fraction f2) {
  Fraction nf(f1.up*f2.down + f2.up*f1.down,
              f1.down*f2.down);
  return nf;
}

Fraction minus(Fraction f1, Fraction f2) {
  Fraction nf(f1.up * f2.down - f2.up * f1.down,
              f1.down * f2.down);
  return nf;
}

Fraction multi(Fraction f1, Fraction f2) {
  Fraction nf(f1.up * f2.up,
              f1.down * f2.down);
  return nf;
}

Fraction divide(Fraction f1, Fraction f2) {
  Fraction nf(f1.up * f2.down,
              f2.up * f1.down);
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
      int a = rabs(f_rst.up) / f_rst.down;
      int b = rabs(f_rst.up) - f_rst.down * a;
      if (f_rst.up < 0) {
        printf("(-%d %d/%d)", a, b, f_rst.down);
      } else {
        printf("%d %d/%d", a, b, f_rst.down);
      }
    } else {
      if (f_rst.up < 0) {
        printf("(-%d/%d)", f_rst.up, f_rst.down);
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
  Fraction f1(up1, down1), f2(up2, down2);
  print_f1f2(f1, '+', f2); print_fraction(add(f1, f2));     printf("\n");
  print_f1f2(f1, '-', f2); print_fraction(minus(f1, f2));   printf("\n");
  print_f1f2(f1, '*', f2); print_fraction(multi(f1, f2));   printf("\n");
  print_f1f2(f1, '/', f2); print_fraction(divide(f1, f2));  printf("\n");
  return 0;
}


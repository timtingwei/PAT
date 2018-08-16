// Copyright [2018] <mituh>

#include <cstdio>

void sort(int a[], int n) {
  int temp = a[0];
  int left = 0, right = n-1;
  int toggle = 0;
  for (;;) {
    if (!toggle) {
      while (a[right] > temp && left < right)
        right--;
      if (left == right) { a[left] = temp; break; }
      a[left] = a[right]; toggle = 1; continue;
    } else {
      while (a[left] <= temp && left < right)
        left++;
      if (left == right) { a[left] = temp; break; }
      a[right] = a[left]; toggle = 0; continue;
    }
  }
}

int main() {
  int a[6] = {5, 3, 9, 6 , 4, 1};
  sort(a, 6);
  for (int i = 0; i < 6; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}

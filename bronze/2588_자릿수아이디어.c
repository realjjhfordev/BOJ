#include <stdio.h>

int main() {
  int n1, n2;
  scanf("%d %d", &n1, &n2);
    
  int n3 = n1 * (n2 % 10);                    // 472 x 5
  int n4 = n1 * ((n2 / 10) % 10);             // 472 x 8
  int n5 = n1 * (n2 / 100);                   // 472 x 3
    int n6 = n1 * n2;
    
    printf("%d\n", n3);
    printf("%d\n", n4);
    printf("%d\n", n5);
    printf("%d\n", n6);
  return 0;
}
/* 2588 곱셈

자릿수 골라내야 할 때는 /, % 를 사용하여 문제해결

int n3 = n1 * (n2 % 10);                    // 472 x 5
int n4 = n1 * ((n2 / 10) % 10);             // 472 x 8
int n5 = n1 * (n2 / 100);                   // 472 x 3
*/
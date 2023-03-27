#include <stdio.h>
// 나머지 값을 배열의 index에 넣어서 counting
int main () 
{
  int count = 0;
  int ary[10];
  int remain[43] = {0, };
    int temp;
    
  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &ary[i]);
    temp = ary[i] % 42;
        remain[temp]++;
  }

  for (int i = 0; i < 43; i++)
  {
        if(remain[i] != 0)
        count++;
    }
  printf("%d", count);
  return 0;
} 

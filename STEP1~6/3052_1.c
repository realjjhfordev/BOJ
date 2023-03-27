#include <stdio.h> 

//나머지 값을 배열에 넣고 원소들끼리 직접 비교하며 counting

int main () 
{
  int count, result = 0;
  int ary[10];
  int ary2[10];

  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &ary[i]);
    ary2[i] = ary[i] % 42;
  }

/*  마지막에 오는 문자는 새로운 문자 (not 중복 ->count) 
    전에 나온 문자(얘 땜에 앞에서 count가 안됐음 -> 여기서 count)
    둘 중 하나임. 따라서 i = 9 일때 무조건 result++가 되어야함
*/
  for (int i = 0; i < 10; i++)
  {
    count = 0;

    for (int j = i+1 ; j < 10; j++) // i = 9일 때 작동 x
    {
      if(ary2[i] == ary2[j]) 
      {
        count++;
      }

    }

    if(count == 0) {result++;}
  }

  
  printf("%d", result);
  return 0;
} 

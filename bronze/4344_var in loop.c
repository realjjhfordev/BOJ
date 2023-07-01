#include <stdio.h>
int main()
{
  int c; // test cases
  int std; // 학생수
  int cnt; // 평균넘는 학생수
  int sum; // 점수 합
  double avg; // 평균

  scanf("%d", &c);

  for (int i = 0; i<c; i++)
  {   
    cnt = 0;
    sum = 0; 
    avg = 0.0;

    scanf("%d", &std);

    int score[std];

    for(int j = 0; j<std; j++) // 점수 입력받기
    {
      scanf("%d", &score[j]);
      sum = sum + score[j];
    }

    avg = (double)sum / std; // 평균

    //비율 = 평균 넘는 애 /  학생 수

    for(int k=0; k<std; k++)
    {
      if(score[k] > avg)
      {
        cnt++;
      }
    }
    printf("%.3lf%%\n", (double)cnt/std*100);
  }
  return 0;
}



/*
1. 반복문 내의 변수선언
2. 배열 선언시 변수로 size 지정 - c99에선 ㄱㅊ, 동적할당 방식으로 해도 됨


→  반복문이 끝나면 해당 반복문에서 선언된 지역변수는 전부 끝남.


for문이 새롭게 시작되면서 변수가 새롭게 선언되는 것. 

(실제로는 효율성을 위해 메모리 공간을 재사용함)
*/
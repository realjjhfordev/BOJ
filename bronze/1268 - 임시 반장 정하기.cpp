#include <bits/stdc++.h>
using namespace std;

int main(void)
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int ary[1001][6] ={0, };
   bool inter[1001][1001] = {false, }; // 같이 반을 한 적이 있는지 체크하는 배열, inter[1][2]가 true인 경우 1번 학생은 2번과 같은 반이었던 적이 있다. -> 당연히 inter[2][1]또한 true가 됨.
  int stu; // 학생수
  int ans; // 임시반장 학생번호
  int max = 0; // 제일 많이 같은 반을 한 경우

  cin >> stu;
  int rep = stu;


    for(int i = 1; i <= stu; i++) // 행(n번째 학생)
    {  
      for(int j = 1; j <= 5; j++) // 열(학년)
        cin >> ary[i][j];
    }
    

    for(int k = 1; k <= stu; k++) // k번 학생이
    {
      for(int l = 1; l <= 5; l++) // l학년 때
      {
        for(int m = stu; m >= k+1; m--) //m번 학생과 같은 반이었는지 체크한다.
        {
          if(ary[k][l] == ary[m][l])
          {
            inter[k][m] = true; // k번 학생은 m번 학생과 같은 반이었던 적이 있다.
            inter[m][k] = true; // k번 학생은 m번 학생과 같은 반이었던 적이 있다.
          }  
        }

      }
    }

for(int i = 1; i <= stu; i++) // 알아볼 학생
{
 int temp = 0;
  for(int j = 1; j <= stu; j++) // 상대 학생
  {
    if(inter[i][j] == true) // 상대 학생과 같은 반이 된 적이 있다면 카운트해준다
      temp++;
  }
  if(temp > max) // 같은 반이었던 적이 있는 학생 최대값 구하기
    {
      max = temp;
      ans = i;
    }
}

if(max == 0) // line 84, 모두 처음보는 사이인 경우 ans값은 바뀌지 않음
  cout << '1'; 

else
cout << ans;

}


/*

5
2 3 1 7 3
4 1 9 6 8
5 5 2 4 4
6 5 2 6 7
8 4 2 2 2

inter
0 0 0 0 0 
0 0 0 1 0 
0 0 0 1 1 
0 1 1 0 1 
0 0 1 1 0 


5 // line 58 example
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5
*/
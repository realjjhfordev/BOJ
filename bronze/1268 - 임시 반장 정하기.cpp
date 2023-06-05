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

for(int i = 1; i <= stu; i++)
{
 int temp = 0;
  for(int j = 1; j <= 5; j++) // 열(학년)
  {
    if(inter[i][j] == true)
      temp++;
  }
  if(temp > max)
    {
      temp = max;
      ans = i;
    }
}

cout << ans;

}






4
3 5 1 5 5     
4 4 3 5 1     
1 2 3 2 2     
1 3 3 2 2 
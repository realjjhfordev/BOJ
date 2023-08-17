#include <bits/stdc++.h>
using namespace std;
int paper[2200][2200];
int cnt[3]; // cnt[0]= -1종이 갯수 cnt[1] = 0종이 갯수 cnt[2] = 1종이 갯수
bool check(int x, int y, int n)
{
  for(int i = x; i < x+n; i++)
    for(int j = y; j < y+n; j++)
     if(paper[x][y] != paper[i][j])
     return false; // 다른 수 섞여있음
  return true; // 같은 수로만 채워짐
}


void solve(int x, int y, int z)
{
  if(check(x,y,z)) cnt[paper[x][y]+1]++; //base case. 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
 // if n == 1, line 17은 항상 성립한다
  else
  {
    z /= 3;

    for(int i = 0; i < 3; i++) // 행
      for(int j = 0; j < 3; j++) // 열
        solve(x+z*i, y+z*j, z);
  }
}



int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n; 
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> paper[i][j];

  solve(0,0,n);

  cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2];
}  

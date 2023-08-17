#include <bits/stdc++.h>
using namespace std;
int n;
string video[70];

bool check(int x, int y, int z)
{
   for(int i = x; i < x+z; i++)
    for(int j = y; j < y+z; j++)
      if(video[x][y] != video[i][j]) return false;

    return true;
}

void func(int x, int y, int z)
{

 if(check(x, y, z)) cout << video[x][y]; // base case, 잘라진 종이가 모두 같은 색으로 칠해져 있는 경우(1x1 크기의 정사각형 칸이 된 경우를 포함한다.)

 else
 {
   cout << '(';
   z /= 2;

   for(int i = 0; i < 2; i++)
   {
    for(int j = 0; j < 2; j++)
      { 
        func(x+z*i, y+z*j, z);
        if(i == 1 && j == 1) cout << ')';
      }
    }

 } 

}

int main()
{ 
  
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  
  for(int i = 0; i < n; i++)
        cin >> video[i];

  func(0, 0, n);

}


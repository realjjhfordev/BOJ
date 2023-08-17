#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n) // n개의 원판을 a번 기둥에서 b번 기둥으로 이동
{
  if (n == 1)
  {
    cout << a << ' ' << b << '\n';
    return;
  }

  func(a, 6-a-b, n-1); // n-1개의 원판을 a,b가 아닌 기둥으로 이동
  func(a, b, 1); // n번째 원판을 a기둥에서 b기둥으로 이동
  func(6-a-b, b, n-1); // a,b기둥이 아닌 기둥에서 b기둥으로 이동
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;

  cin >> n;

  cout << (1<<n)-1 << '\n';
  func(1, 3, n);
}  

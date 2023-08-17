#include <bits/stdc++.h>
using namespace std;


int func1(int n)
{
  if (n == 0) return 0;
  cout << 'n' << ' ';
  func1(n-1);
}
//n부터 1까지 출력하는 함수

int func2(int n)
{
  if (n == 0) return 0;
  return n+func2(n-1);
}
// n부터 1까지의 합을 출력하는 함수
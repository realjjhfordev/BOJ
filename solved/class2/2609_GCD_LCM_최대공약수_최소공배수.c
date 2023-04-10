#include <bits/stdc++.h>
using namespace std;

int gcd_func(int a, int b)
{ 
  int r;

  if(a < b)
    swap(a, b);
  while(b != 0)
  {
  r = a % b;
  a = b;
  b = r;
  }
  return a; // 최대공약수
}


int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

int a, b, gcd, lcm;

cin >> a >> b;

gcd = gcd_func(a, b);// Greatest Common Divisor, 최대공약수
lcm = (a * b) / g;


cout << gcd << "\n" << lcm << "\n";

return 0;
}



/*
유클리드 알고리즘은 2개의 자연수 또는 정식(整式)의 최대공약수를 구하는 알고리즘의 하나이다.
2개의 자연수 a, b에 대해서 a를 b로 나눈 나머지를 r이라 하면(단, a>b)
a와 b의 최대공약수는 b와 r의 최대공약수와 같다. 
이 성질에 따라, b를 r로 나눈 나머지 r'를 구하고, 다시 r을 r'로 나눈 나머지를 구하는 과정을 반복하여 
나머지가 0이 되었을 때 나누는 수가 a와 b의 최대공약수이다!!

gcd * lcm = a * b

*/
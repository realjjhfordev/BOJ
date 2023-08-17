#include <bits/stdc++.h>
using namespace std;

//전공평점은 전공과목별 (학점 × 과목평점)의 합을 학점의 총합으로 나눈 값이다.

using ll = long long; // typedef long long ll

ll temp;

ll pow(ll a, ll b, ll c)
{
  if(b == 1) return a % c;
  temp = pow(a, b/2, c);
  temp = temp * temp % c;
  if(b % 2 == 0) return temp;
  else return temp * a % c;
}


int main()
{
  ll a, b, c;

  cin >> a >> b >> c;
  cout << pow(a, b, c);

}
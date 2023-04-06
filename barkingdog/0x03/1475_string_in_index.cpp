#include <bits/stdc++.h>
using namespace std;


int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
 int ary[10] = {0, };
 string n;
 int max;

 cin >> n;

 for(int i = 0; i < n.size(); i++) // 글자들 체크
 {
  if(n[i] == '6')
    ary[9]++;    // 6는 9에 몰아줌.
  else
    ary[n[i]-'0']++;
 }

 ary[9] = (ary[9]+1)/2;

 max = ary[0];

 for(int j = 1; j <= 9; j++)
 {
  if(ary[j] > max)
      max = ary[j];
 }

  cout << max;


}


/* 

line 18 ~ 21 -> 인덱스 부분의 n[i]는 정수가 아니고 string임에 주의할 것.


*/
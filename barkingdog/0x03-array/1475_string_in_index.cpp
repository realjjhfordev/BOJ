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

 ary[9] = (ary[9]+1)/2; // (a[6]+a[9])/2를 올림한 값이 6, 9에 대한 필요한 세트의 수이므로 (a[6]+a[9]+1)/2을 계산, 
                        // 여기서는 a[6]에 갈 값을 a[9]에 몰아줬으므로 (ary[9]+1)/2

 max = ary[0];

 for(int j = 1; j <= 9; j++) // max함수로 최대값을 구해도 좋음, max(max, ary[idx])
 {
  if(ary[j] > max)
      max = ary[j];
 }

  cout << max;


}


/* 

line 18 ~ 21 -> 인덱스 부분의 n[i]는 정수가 아니고 string임에 주의할 것.


*/
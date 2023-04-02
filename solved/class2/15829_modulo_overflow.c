#include <bits/stdc++.h>
using namespace std;


int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int len;
  long long r = 1;
  int m = 1234567891;
  string str;
  
  long long res = 0;

  cin >> len >> str;
  

  for(int i = 0; i < len; i++)
  {
    
    res = res + (((str[i]-'`') * r) % m); 
    res = res % m;
    r = r * 31 % m;
  }

  cout << res % m;


}



/*
코딩테스트를 풀다보면 결과 값이 매우 큰 경우 값의 나머지를 구하라는 문제가 자주 출제된다.
단순히 결과 값에 모듈러 연산을 수행하면 이미 결과값이 너무 커져서 오버플로우가 발생하거나 연산에 시간이 오래 걸리는 경우바 발생한다. 따라서 이럴때 연산 과정 중간에 모듈러 연산을 적용해야 한다.
31의 제곱수를 계산할때 overflow가 나는 문제를 해결해야 하는 문제이다.

나머지 연산의 법칙중 분배법칙을 이용해서 풀면 된다.

REFERENCE
https://codejin.tistory.com/68?category=913904
https://finger-ineedyourhelp.tistory.com/10
https://guccin.tistory.com/m/162

*/
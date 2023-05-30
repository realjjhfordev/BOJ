#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

int tc;

// a^b == data의 갯수

cin >> tc;

while(tc--)
{
  int a, b, rep;
  int ans = 1;

  cin >> a >> b;
  
  while(b--)
  {
    ans *= a;
    ans %= 10; // 일의자리만 남기기
  }

  if(ans != 0)
    cout << ans << "\n";
  else 
    cout << "10\n";
}

}




/*
1의 자리를 체크하면 되는 문제.
1의 자리 수를 구하는 불변의 법칙
어떤 수던 간에 10으로 나눌 경우 일의자리수가 나머지로 남고 나머지 자리수들은 몫으로 들어가게된다.

1234 / 10

몫 123
나머지 4

알고리즘을 할때 이 부분을 인지하고 있으면 도움이 된다.

*/
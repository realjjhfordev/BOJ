#include <bits/stdc++.h>
using namespace std;

int main(void)
{

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;


  if(n == 1)
  {
    return 0;
  }

  while(n != 1)
  {
    for(int i = 2; i <= n; i++)
    {
      if(n % i == 0)
      {
        n = n / i;
        cout << i;
      }
      break;
    }
  }

}

/* 나누어 떨어지는 경우 출력하고 나눗셈을 해준다. 언제까지? 나눠지는 수가 1이 될 때까지!

break문은 결국 '반복문'을 탈출한다

for문 안의 if문에 break가 존재하는 경우 -> break가 작동하면 for문을 벗어나게 된다.
*/
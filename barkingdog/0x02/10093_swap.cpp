#include <bits/stdc++.h>
using namespace std;

int main(void)
{

  ios::sync_with_stdio(0);
  cin.tie(0);

  long long a, b;
  int count = 0;
  int num;

  cin >> a >> b;

  if (a == b)
    cout << '0';

  else if (a >= b)     
    {
      count = a - b - 1;
      cout << count << "\n"; // 사이에 있는 수 출력

      for(long long i = b+1; i < a; i++)
      {
        cout << i << ' ';
      }
    }

  else
   {
      count = b - a - 1;
      cout << count << "\n";

      for(long long i = a+1; i < b; i++)
      {
        cout << i << ' ';
      }
    }

  return 0;
}

/*
swap(a, b)
매개변수 2개의 값을 서로 바꾸는 함수

 */
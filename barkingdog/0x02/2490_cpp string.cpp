#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

/* 배=0 등=1, 배4등0=윷D 배3=걸C 배2=개B 배1=도A 배0=모E */
  int result, input;

  string res = "DCBAE";

  for(int i = 0; i < 3; i++) // 3줄 입력
  {
    result = 0;

    for(int j = 0; j < 4; j++) // 배와 등 입력
      { 
        cin >> input;
        result = result + input; // ex: result가 0이면 윷(D)
      }
    cout << res[result] << '\n';
  }
}

/*

{
  string my_str("abcdefg"); 

-> equal to string my_str = "abcdefg";

  cout << my_str[0]   // 'a' 출력
  cout << my_str[3]   // 'd' 출력

  my_str[3] = 'Z';

  cout << my_str  // 'abcZefg' 출력
  return 0;
}

string class 멤버함수에는

.size
.length
.front
.back
.at
.operator
.compare
등이 존재한다.

https://blockdmask.tistory.com/338 참고




*/
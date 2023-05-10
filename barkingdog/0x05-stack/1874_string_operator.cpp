#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

int n;
stack<int> st;
cin >> n;
string res; // no 인 경우를 대비하여 바로바로 +/-를 출력하지 않고 res에 저장 해두었다가 한꺼번에 출력한다.
int element = 1; // 오름차순으로 넣어야 될 원소

while(n--)
{ 
  int target; // 새로 만들어야 할 수열의 원소
  cin >> target;

  while(target >= element)
  {
    st.push(element);
    element++;
    res += "+\n";
  }

  if(target != st.top())
  {
    cout << "NO";
    return 0;
  }

  st.pop();
  res += "-\n";

} // while loop 종료, NO가 아닌 경우에만 while loop 탈출
cout << res;

}




/*
* string 클래스에 <, >, ==, + 등과 같은 연산자들을 사용할 수 있다.

For **built-in types** `a += b` is exactly the same as `a = a + b` but for classes, those operators are overloaded and call different functions.

In your example `fans = fans + s[i]` creates a temporary string, and assigns (moves) it to `fans`, but `fans += s[i]` does not create that temporary, hence it may be faster.

https://stackoverflow.com/questions/57132337/difference-between-string-s1-and-string-string-s1
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

/* 
<좋은 단어> -> 수식의 괄호 쌍과 유사한 문제유형
top과 같은 단어가 나오면 push는 하지 않고 pop만 해주기
모든 과정을 끝낸 후 스택은 비워져 있어야함.
*/
int n;
int res = 0;
cin >> n;

while(n--)
{ 
 stack<char> st;
  string s;
  cin >> s;

  for(char c:s)
  {
    if(st.empty())
    {
      st.push(c);
    }
    else // stack is not empty
    {
      if(st.top() == c)
        st.pop();
      else
        st.push(c);
    }
  } // for loop

  if(st.empty()) // 모든 과정이 끝난 후 스택이 비어있다면 바른 단어
    res++; 

} // while loop

cout << res;

}
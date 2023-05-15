#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

/* 
닫는 괄호가 나왔을 때
스택이 비어있으면 안됨
스택의 top과 짝이 맞지 않으면 안됨 (top과 짝이 맞을 때마다 pop을 해주므로 항상 서로 맞아야함)
스택의 top과 짝이 맞으면 탑을 pop
모든 과정을 끝낸 후 스택은 비워져 있어야함.
*/
int n;
cin >> n;

while(n--)
{
bool valid = true;
 stack<char> st;
  string s;
  cin >> s;

  for(char c:s)
  {
    if(c == '(')
      st.push(c);
    else // c가 닫는 괄호일 때
    {
      if(st.empty() || st.top() == ')') // stack is empty or st.top과 짝이 맞지 않음
      {
        valid = false;
        break;
      }
      else if(st.top() == '(') // 스택의 top과 짝이 맞으면 탑을 pop
        st.pop();
    }
  
  } // for loop

  if(st.empty() && valid == true) 
    cout << "YES\n";
  else // stack is not empty or valid is false
    cout << "NO\n";


} // while loop

}
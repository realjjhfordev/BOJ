 #include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);


/*
닫는 괄호가 나왔을 때
스택이 비어있으면 안됨
스택의 top과 짝이 맞지 않으면 안됨
스택의 top과 짝이 맞으면 탑을 pop
모든 과정을 끝낸 후 스택은 비워져 있어야함.
*/
while(true)
{
string s;
getline(cin, s); // 문자열 입력
if(s == ".") break;
stack<char> st; // stack에는 문자를 제외한 괄호만 들어간다.
bool valid = true;

  for(char c:s)
  {
    if(c == '[' || c=='(') // 여는 괄호인 경우 스택에 넣는다
      {
        st.push(c);
      }
    else if(c == ')') // 닫는 소괄호인 경우
      { 
        if(st.empty() || st.top() != '(') // 스택이 비어있거나 짝이 맞지 않는 경우
        {  
          valid = false;
          break;
        }
        st.pop();
      }
    else if(c == ']') // 닫는 대괄호인 경우
    {
       if(st.empty() || st.top() != '[') // 스택이 비어있거나 짝이 맞지 않는 경우
        {
          valid = false;
          break;
        }
        st.pop();
    }
  } // for loop

if(!st.empty() || valid == false) // 모든 과정을 끝내고 스택이 비어있거나, 짝이 맞지 않는 경우
  cout << "no\n";
else
  cout << "yes\n";


} // while loop



}
 #include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

int ans = 0; // 더해질 값
int mul = 1; // 곱해질 값

string str;
cin >> str;
stack<char> st; // 올바른 괄호쌍인지 체크 하는 용도

for(int i = 0; i < str.size(); i++)
{
  if(str[i] == '(')
  {
    mul *= 2;
    st.push(str[i]);
  }

  else if(str[i] == '[')
  {
    mul *= 3;
    st.push(str[i]);
  }

  else if (str[i] == ')')
  {
    if(st.empty() || st.top() != '(')// 스택이 빈 경우, st.top이 닫는괄호인 경우, st.top과 짝이 안맞는 경우
    {
      cout << "0";
      return 0;
    }
    else if(str[i-1] == '(')
    {
      ans = ans + mul;
      mul /= 2;
      st.pop();
    }
    else // 바로 옆에 괄호쌍이 있지 않은 경우
    {
      mul /= 2;
      st.pop();
    }
  }

  else if(str[i] == ']')
  {
    if(st.empty() || st.top() != '[') // 스택이 빈 경우, st.top이 닫는괄호인 경우, st.top과 짝이 안맞는 경우
    {
      cout << "0";
      return 0;
    }
    else if(str[i-1] == '[')
    {
      ans = ans + mul;
      mul /= 3;
      st.pop();
    }
    else // 바로 옆에 괄호쌍이 있지 않은 경우
    {
      mul /= 3;
      st.pop();
    }
  }
}

if(st.empty())
  cout << sum;
else 
  cout << 0;

}
/* 여는괄호만 push하고 닫는괄호가 나오면 연산을 한다.
참고하면 좋은 것
[]==[1]
()==(1)
(ab) == 2a+2b, 분배 법칙
*/
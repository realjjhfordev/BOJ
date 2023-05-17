#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

long long answer = 0; // 막대기의 개수
string str;
stack<char> st;

cin >> str; // 괄호 입력

for(int i = 0; i < str.size(); i++)
{
  if(str[i] == '(')
    st.push(str[i]);

  else // 닫는괄호인 경우
  {
    if (str[i-1] == '(') // 레이저 닫는 괄호
    {
      st.pop();
      answer += st.size();
    }
    else // 쇠막대기 닫는 괄호
    {
      st.pop();
      answer++;
    }
  }
}

cout << answer;
}

// 괄호문제는 닫는 괄호가 나왔을 경우에 집중하여 문제를 푼다!
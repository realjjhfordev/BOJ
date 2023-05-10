#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); 

int n;
string s;
stack<char> st;

cin >> n;
cin.ignore(); // cin과 getline이 같이 사용되므로 ignore 필요
while(n--)
{
  bool firstblank = true;
  getline(cin, s); // 문자열 입력받기
  s += ' '; // 마지막 단어 출력을 위
  for(auto c : s)
  {
    st.push(c); // 문자열 스택에 집어넣기
    if(c == ' ')// 공백 나오면 스택 싹 비우기
    { 
     if(firstblank == true) // 첫 공백은 출력하지 않음.
      {
        st.pop();
        firstblank = false;
      }
      while(!st.empty())
      {
        cout << st.top();
        st.pop();
      }
    }
  } 

  cout << "\n";
}

}

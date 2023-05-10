#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

stack<int> st;
int n;
string s;

cin >> n;

while(n--)
{
  cin >> s;

  if(s == "push")
  {
    int put;
    cin >> put;
    st.push(put);
  }

  else if(s == "pop")
  {
    if(st.empty())
      cout << "-1" << "\n";
    else
    { cout << st.top() << "\n";
      st.pop();
    }
  }

  else if(s == "top")
  {
    if(st.empty())
      cout << "-1" << "\n";
    else
      cout << st.top() << "\n";

  }

  else if(s == "empty")
  {
    if(st.empty())
      cout << "1" << "\n";
    else
      cout << "0" << "\n";
  }

  else // size
  {
    cout << st.size() << "\n";
  }

}


}
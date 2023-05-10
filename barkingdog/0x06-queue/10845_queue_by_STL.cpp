#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

queue<int> q;
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
    q.push(put);
  }

  else if(s == "pop")
  {
    if(q.empty())
      cout << "-1" << "\n";
    else
    { cout << q.front() << "\n";
      q.pop();
    }
  }

  else if(s == "front")
  {
    if(q.empty())
      cout << "-1" << "\n";
    else
      cout << q.front() << "\n";

  }

  else if(s == "back")
  {
    if(q.empty())
      cout << "-1" << "\n";
    else
      cout << q.back() << "\n";

  }

  else if(s == "empty")
  {
    if(q.empty())
      cout << "1" << "\n";
    else
      cout << "0" << "\n";
  }

  else // size
  {
    cout << q.size() << "\n";
  }

}


}
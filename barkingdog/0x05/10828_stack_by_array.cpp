#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

const int mx = 1000000;
int stack[mx];
int pos = 0;          // array stack init
string s;

cin >> n;

while(n--)
{
  cin >> s;

  if(s == "push")
  {
    int put;
    cin >> put;
    stack[pos] = put;
    pos++;
  }

  else if(s == "pop")
  {
    if(pos == 0)        // empty stack
      cout << "-1" << "\n";
    else
    { cout << stack[pos-1] << "\n";
      pos--;
    }
  }

  else if(s == "top")
  {
    if(pos == 0)        // empty stack
      cout << "-1" << "\n";

    else
      cout << stack[pos-1] << "\n";

  }

  else if(s == "empty")
  {
    if(pos == 0)
      cout << "1" << "\n";
    else
      cout << "0" << "\n";
  }

  else // size
  {
    cout << pos << "\n";
  }

}


}
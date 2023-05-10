#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

int n;
string s;
list<char> lst;

cin >> n;

while(n--)
{
  cin >> s;

  list<char>::iterator cursor = lst.begin(); // == lst.end(); -> empty list이기 때문.
  
  for(auto c : s)
  {

  if(c == '<') // left
  {
    if(cursor != lst.begin())
      cursor--; // 커서를 좌로 1칸 이동
  }
  else if(c == '>')  // right
  {
    if(cursor != lst.end())
      cursor++; // 커서를 우로 1칸 이동
  }
  else if(c == '-') // backspace
  {
    if(cursor != lst.begin()) // 커서가 맨 앞자리가 아닌 경우
    {
      cursor--;
      cursor = lst.erase(cursor);
    } 
  }

  else // 대소문자, 숫자
  {
    lst.insert(cursor, c);
  }


}//for

for(auto ch : lst) cout << ch;

}//while


}

/*

****list.end()**** (https://cplusplus.com/list)

If the container is [empty](https://cplusplus.com/list::empty), this function returns the same as [list::begin](https://cplusplus.com/list::begin)
Returns an iterator referring to the *past-the-end*
element in the list container.(끝에 달린 더미노드를 가리킴)

Cursor 관련 문제(Cursor 주변에서 insert/delete) → Linked List 활용!

*/

#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

int m;
string init;
cin >> init;

list<char> lst; // stl linked list create
for(auto c : init) lst.push_back(c); // 편집기에 문자열 입력
auto cursor = lst.end(); // cursor(iterator)가 lst의 더미노드(마지막 원소의 한칸 뒤)를 가리키고 있음

cin >> m; // 입력할 명령어의 갯수

while(m--) // m번 반복하여 명령어 실행
{
  char op;
  cin >> op;  // 명령어 입력받기
  if(op == 'L')
  {
    if(cursor != lst.begin())
      cursor--; // cursor(iterator)가 previous element를 가리킴
  }
  else if(op == 'D')
  {
    if(cursor != lst.end())
      cursor++; // cursor(iterator)가 next element를 가리킴
  }
  else if(op == 'P')
  {
    char a;
    cin >> a;
    lst.insert(cursor, a); // cursor의 앞에 a를 추가함 (더미노드 앞에 원소하나 추가, cursor는 그대로 dummy node 가리킴)
  }
  else  // op ==  'B'
  {
    if(cursor != lst.begin())
    {  
      cursor--;
      cursor = lst.erase(cursor);
    } // cursor에 위치한 원소는 제거되고, cursor 다음에 위치한 원소의 위치가 return
  }  
}

for(auto c : lst) cout << c;
}

#include <bits/stdc++.h>
  using namespace std;

  int main(void) 
  {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;

  list<int> lst; // stl linked list create
  cin >> n >> k;

  for(int i = 1; i <= n; i++) // 원을 이루며 앉는다.
  {
    lst.push_back(i);
  }

  list<int>::iterator cursor = lst.begin(); // cursor는 list의 첫 원소를 가리키고 있다. 
  cout << "<";

  while(n--)
  {

    for(int j = 0; j < k-1 ; j++) // 커서 이동
    { 
      if(cursor == lst.end()) cursor = lst.begin(); // cursor가 end에 있는 경우 begin으로 보냄
      cursor++;
    }

   if(cursor == lst.end()) cursor = lst.begin(); // 커서 이동이 다 끝났을 때 cursor가 end에 있는 경우를 방지

    if(n != 0)  //마지막 요소는 , 없이 출력
    {
     cout << *cursor << "," << " ";
    }
    else
      cout << *cursor << ">";
    
    cursor = lst.erase(cursor);

  }


  }
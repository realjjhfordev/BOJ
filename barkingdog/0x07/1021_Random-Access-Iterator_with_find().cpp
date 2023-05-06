#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

deque<int> deq;
int n, m;
int operation = 0;
cin >> n >> m;

for(int i = 1; i <= n; i++) 
    deq.push_back(i); // 덱 초기화 1~n

deque<int>::iterator cursor;


/* target이 begin에 가까운지 end에 가까운지 체크해야함.*/

while(m--)
{ 
  cursor = deq.begin();
  int target;
  cin >> target; // 제거대상
  
  if(*cursor == target) // target이 begin에 바로 위치한 경우
    deq.pop_front();



  else // target을 찾고, begin/end 어느쪽에 가까운지 체크.
  {
   int idx = find(deq.begin(), deq.end(), target) - deq.begin(); // idx : t가 있는 위치의 인덱스

   cursor = cursor + idx; // cursor는 target을 가리키고 있음.

    if(cursor-deq.begin() >= deq.end() - cursor) // begin~cursor 거리 >= cursor~end 거리 , target(cursor)이 end와 더 가깝다. 
    {
       while(deq.end() - cursor) // 3번연산 반복
       {
         deq.push_front(deq.back());
         deq.pop_back();
         operation++;
       }
       deq.pop_front();
    }
    else // target이 begin과 더 가깝다.
    {
     while(cursor-deq.begin()) // 2번연산 반복
       {
         deq.push_back(deq.front());
         deq.pop_front();
         operation++;
       }
       deq.pop_front();
    }

  } // else end

} // while end

cout << operation;


}


/*

InputIterator find (InputIterator first, InputIterator last, const T& val){
 

find() 함수는 일련의 자료구조(Array, Vector, Deque..)내에서 원하는 값을 탐색하는 함수이다.

범위(first부터 last전)안의 원소들 중에서 val과 일치하는 첫 번째 원소의 이터레이터를 리턴한다. 범위 안의 원소를 비교할 때 Operator == 을 사용하며, <string>의 find와는 다른 함수이다.

** 반환받은 인덱스(p)에서 배열의 첫 번째 인덱스(first) myInts를 빼 주면 탐색을 성공한 인덱스의 값을 출력시킬 수 있다. **

_Parameter

first, last : 탐색할 원소의 시작과 끝을 가리키는 이터레이터로, first는 범위 내에 포함되지만 last는 포함되지 않는다.

val : 탐색을 수행할 비교 값.

 

_Return Value

탐색에 성공하면 val과 일치하는 원소들 중 첫 번째 원소의 이터레이터를 리턴한다.

탐색에 성공하지 못하면 last를 리턴한다.

 

*/
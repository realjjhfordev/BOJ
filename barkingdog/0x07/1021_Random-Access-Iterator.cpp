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
   while(*cursor != target) // cursor가 target을 가리키면 반복을 멈춘다.{
      cursor++;
      cout << cursor-deq.begin() << "\n" << deq.end() - cursor << "\n";

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
http://www.soen.kr/lecture/ccpp/cpp4/39-2-4.htm

39line을 보면 -> 반복자 끼리의 연산을 하는데, 이는 deque에서의 반복자가 '임의 접근 반복자'라서 가능한 것이다.

임의 접근 반복자가 +n을 지원할 수 있는 이유는 컨테이너의 요소들이 배열처럼 인접하게 배치되어 있기 때문이다. 
요소의 크기가 일정하고 서로 이웃해 있으므로 이동하고 싶은 거리에 요소 크기를 곱한만큼 이동하기만 하면 즉시 원하는 위치로 이동이 가능하다.
배열을 가리키는 포인터를 생각해 보면 쉽게 이해할 수 있다. 

같은 배열내의 임의 접근 반복자끼리는 뺄셈도 가능하다. 
두 반복자 사이에 있는 요소들이 같은 크기로 모여 있으므로 뺄셈 결과는 구간내의 요소 개수를 나타내는 정수값이다. 
*<포인터끼리의 뺄셈은 두 포인터 사이의 상대적 거리를 나타내는 것과 유사함!!>*

또한 요소들이 선형적으로 배치되어 있으므로 반복자끼리 대소 비교도 가능하다. 
번지값이 큰 반복자가 항상 더 뒤쪽에 있으므로 대소 비교에 의해 반복자의 전후를 명확하게 알 수 있다.
링크에 의해 연결되어 있는 list 컨테이너는 임의 접근이 불가능하므로 양방향 반복자를 제공한다. 
연결 리스트의 노드들이 인접해 있지 않고 메모리 여기 저기에 흩어져 있으므로 +n 연산이 불가능하며 링크를 따라 한칸씩 점진적으로 이동할 수밖에 없다. 
또한 반복자의 번지만으로 전후를 판별할 수 없으므로 대소 비교도 불가능하며 반복자끼리 뺄셈을 통해 구간의 요소 개수를 구할 수도 없다. 
임의 접근이 아닌 반복자로 +n 연산을 하거나 두 반복자의 거리를 구하고 싶다면 다음 두 함수를 사용한다.

*/
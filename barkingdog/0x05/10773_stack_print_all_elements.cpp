#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

int k, n;
long long sum = 0;
stack<int> st;

cin >> k; // 반복횟수

while(k--)
{
  cin >> n;

  if(n != 0)
    st.push(n);
  else
    if(!st.empty())
      st.pop();
}

const int stack_size = st.size();

for(int i = 0; i < stack_size; i++)
{
sum = sum + st.top();
st.pop();
}

cout << sum;

}

/*
특정 위치에 있는 원소의 확인/변경이 원칙적으로 불가능하기에 range based loop가 불가능하다. 
전체 출력을 원한다면 top/pop 반복!

+) queue의 경우도 동일함
Well, the answer is actually pretty simple: there is no function begin() in std::queue and there isn't any overload of std::begin taking a std::queue either. You can have a look at the documentation.
The core problem is that std::queue is not meant to be iterated over. It exists to satisfy other needs. If you really need to iterate over it, you should just use the underlying container (by default std::deque) which supports iteration and for which your code would be valid.
https://stackoverflow.com/questions/20742595/range-based-loop-for-stdqueue

for loop 조건문에 stack.size()를 사용할 경우, 만약 반복문 내에서 
push나 pop과같은 동작 발생시 stack size가 변하므로 조심
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

int n;
int sum = 0;

while(1)
  {
    cin >> n;
    if(cin.eof()) break;
    sum = sum + n;
  }

cout << sum;
}

// 또는 밑의 코드


#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

int n = 0;
int sum = 0;

while(!cin.eof())
  {
    cin >> n;   // cin으로 입력을 받으려 하는데 EOF가 읽히면 입력 받기가 취소되고 cin.eof()가 true가 됩니다. n은 마지막으로 입력했던 값 그대로 유지
    sum = sum + n; // 마지막으로 입력했던 n이 두번 입력됨
  }

cout << sum-n;
}


/*
C++ EOF 처리 방법
https://heestory0324.tistory.com/10

1. cin.eof()

cin.eof()는 eofbit를 검사해서 마지막 입력값에 다다랐으면 true를, 그렇지 않으면 flase를 반환한다.

(ref: https://www.cplusplus.com/reference/ios/ios/eof/)

2. >> 연산자의 반환 값을 이용

while문 조건에 들어있는 cin
cin은 원래 값을 받는 역할을 하지만 조건문 안에 들어있다면
true or false로 값을 가진다. 처음에 int형으로 선언을 해줬기 때문에 
정수를 입력하면 true인 것이다. 만약 비정상적으로 EOF, 'a' 같은 다른 
자료형이 들어간다면 이는 false로 취급한다. 


int main() {

    int a, b;
    
    while (cin >> a >> b) { // cin은 객체를 반환하지만, 예외적으로 while이나 if안에서는 자동으로 bool로 변환됨
    	cout << a + b << "\n";
    }

	return 0;
}

line 63 : cin으로 입력을 받는데 잘못된 값이 들어오면 false을 return함.

*/
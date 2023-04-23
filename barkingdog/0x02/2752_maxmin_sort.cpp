#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[4];
  for(int i=0;i<3;i++){
    cin>>arr[i];
  }
  sort(arr, arr+3);
  for(int i=0;i<3;i++){
    cout<<arr[i]<<" ";
  }
}
/* 정수의 man min 값 구하기

int a, b, c;
int d, e, f;
cin >> a >> b >> c;
d = min({a,b,c}); // a, b, c 중 가장 작은 값
f = max({d,e,f}); // 가장 큰 


정렬하기
sort function

배열의 경우
  sort(arr, arr+3);


// 첫번째 인자는 시작지점 = 배열의 포인터
// 두번째 인자는 끝나는지점 + 1; 


벡터의 경우



    vector<int> a(100);

초기화를 했다고 가정
첫번째 인자는 시작지점 = iterator의 begin()
두번째 인자는 끝나는지점 + 1 = iterator의 end()
    sort(a.begin(), a.end());    
}

sort() 사용하기(비교함수 이용하기)

    때로는 직접 비교함수를 추가해줘야하는 경우가 있다 사용법은 위와 동입하며 함수만 3번째 인자로 추가해주면 된다.
    Point라는 구조체를 정렬한다고 가정해보자.

#include <iostream>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

// const와  &를 통해서 레퍼런스로 받아오는걸 잊지말자!
// x순으로 정렬하고 x값이 같으면 y순으로 각각 오른차순으로 정렬
bool cmp(const Point &p1, const Point &p2){
    if(p1.x < p2.x){
        return true;
    }
    else if(p1.x == p2.x){
        return p1.y < p2.y;
    }
    else{
        return false;
    }
}

int main (){

    Point a[100];

    // 초기화를 했다고 가정

    // 정렬
    // 첫번째 인자는 시작지점 = 배열의 포인터
    // 두번째 인자는 끝나는지점 + 1 = a(배열의 포인터) + 배열의 크기
    sort(a, a+100, cmp);
}
*/
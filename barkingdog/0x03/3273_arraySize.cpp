#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
int cnt = 0; //정답

int n; //  1 ≤ n ≤ 100000   수열의 크기
int x; //  1 ≤ x ≤ 2000000  

cin >> n; int ary[n]; 

for(int i = 0; i < n; i++) // 수열에 포함되는 수, 1 <= a <=  1000000
{
  cin >> ary[i];
}
cin >> x;
bool res[2000000] = {0, }; // x-element checker     




for(int j = 0; j < n; j++)
{
  if( (ary[j] < x) && (res[x-ary[j]] != 0)) // 원소가 x보다 작아야 원소+원소 = x를 만족하는 원소쌍이 존재함
    cnt++;
  res[ary[j]] = true;
}

cout << cnt;

}




/*
보통 프로그래밍 문제를 풀 때에는 동적할당을 하는 방식이 아닌 

나올 수 있는 최대크기의 배열 크기로 정적할당하여 사용하는 것이 일반적입니다.

N이 최대 1000까지라고 문제에서 주어진다면 정적으로

int ar[1000];

과 같이 선언하여 작성하시면 됩니다.

보통은 크기에 딱 맞게보다 

int ar[1010];

다음과 같이 코너캐이스를 위해 여유있게 사이즈를 늘려 선언해서 사용합니다.
*/
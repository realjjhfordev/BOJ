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
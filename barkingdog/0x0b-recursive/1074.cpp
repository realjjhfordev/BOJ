#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c)
{
  int half = 1 << (n-1); // 2^(n-1)
  if(n == 0) return 0; // base case

  if(r < half  && c < half) return func(n-1, r, c); //1 
  if(r < half  && c >= half) return half*half+func(n-1, r, c-half); //2
  if(r >= half && c < half) return 2*half*half+func(n-1, r-half, c); //3
  if(r >= half && c >= half) return 3*half*half+func(n-1, r-half, c-half); //4
}

int main()
{ 
  int n, r, c;
  cin >> n >> r >> c;
  cout << func(n, r, c);
}

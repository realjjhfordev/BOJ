#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int x, y, w, h;
  int to_axis;
  int to_border;

  cin >> x >> y >> w >> h;

  if(w-x >= h-y) // border
    to_border = h-y;
  else 
    to_border = w-x;

  if(x-0 >= y-0) // axis
    to_axis = y;
  else
    to_axis = x;

  if(to_axis >= to_border) //nearer
    cout << to_border;
  else
    cout << to_axis;

}

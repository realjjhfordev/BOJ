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

  to_border = min(w-x, h-y);

  to_axis = min(x, y);

  cout << min(to_border, to_axis)

}

#include <bits/stdc++.h>
using namespace std;

vector<int> dy;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<int> Q;
  int building[1000002];
  fill(building, building+1000002, -1);
  int f, s, g, u, d;

  cin >> f >> s >> g >> u >> d;
  building[s] = 0;
  Q.push(s);
  dy.push_back(u); dy.push_back(-d); // dy[0] == up, dy[1] == down

  while(!Q.empty())
  {
    auto cur = Q.front(); Q.pop();

    for(int dir = 0; dir < 2; dir++)
    {
      int ny = cur + dy[dir];

      if(ny <= 0 || ny > f) continue; // 방문하려고 하는 곳이 0층 이하이거나 f층 초과한 경우 패스
      if(building[ny] != -1) continue; // 방문한 적이 있는 경우

      building[ny] = building[cur] + 1;
      Q.push(ny);
    }
  }
  if(building[g] == -1) // 목표로 하는 층에 엘리베이터로 방문할 수 없는 경우
    cout << "use the stairs";
  else
    cout << building[g]; 

}
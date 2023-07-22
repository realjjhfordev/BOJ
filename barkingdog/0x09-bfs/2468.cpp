#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair 함에서 first, second를 줄여서 쓰기 위해서 사용

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int rain[102][102];
int vis[102][102];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int, int>> Q;
  int sqsize; // 정사각형의 한 변의 길이
  vector<int> v; // 비의 양 별 잠기지 않는 지역의 갯수
  int lowest = 101; // 가장 낮은 지대의 높이
  int largest = 0; // 가장 높은 지대의 높이
  int area = 0; // 안전지대의 갯수

  cin >> sqsize;
  
  for(int i = 0; i < sqsize; i++) // 지역 높이 데이터 입력
  {
     for(int j = 0; j < sqsize; j++)
      {
        cin >> rain[i][j];
        if(rain[i][j] < lowest)
          lowest = rain[i][j];
        if(rain[i][j] > largest)
          largest = rain[i][j];
      }
  }
 
  for(int rep = lowest-1; rep < largest; rep++) // 내리는 비의 양, largest 만큼 올 경우는 제외함 (안전영역 없음)
  {
    area = 0;

    for(int ci = 0; ci < sqsize; ci++)  // rep가 ++됨에 따라 초기화
      for(int cj = 0; cj < sqsize; cj++)
        vis[ci][cj] = rain[ci][cj];

    for(int i = 0; i < sqsize; i++) // 시작점 찾기
  {
    for(int j = 0; j < sqsize; j++)
    { 
      
      if(vis[i][j] <= rep) continue; // 방문한곳(-1) 패스, 비오면 잠기는 곳 패스
      
      area++;
      vis[i][j] = -1; // 방문체크
      Q.push({i, j});

      while(!Q.empty()) // 안전지대들에 대해 bfs를 실행
      { 
        
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(nx < 0 || ny < 0 || nx >= sqsize || ny >= sqsize) continue;
          if(vis[nx][ny] <= rep) continue;

          vis[nx][ny] = -1; // 방문체크
          Q.push({nx,ny});
        }
      }
    }
  }
  v.push_back(area); // 비가 rep만큼 올 때 안전지대의 갯수 삽입

  }

    sort(v.begin(), v.end());
    cout << v.back();

}
// rep가 lowest - 1에서 시작해야 하는 이유
// lowest == largest 인 경우, lowest보다 적은 비가 오는 경우에 안전지대가 1구역 있을 수 있으므로 제대로된 최대값을 구할 수 없음.
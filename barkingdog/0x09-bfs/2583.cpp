#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair 함에서 first, second를 줄여서 쓰기 위해서 사용
int board[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, k; // m행, n열, k개의 직사각형

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> area; // 영역의 넓이
  int sector = 0; // 영역의 갯수
  queue<pair<int, int>> Q;
  pair<int, int> leftunder; // 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과
  pair<int, int> rightupper; // 오른쪽 위 꼭짓점의 x, y좌표값
  cin >> m >> n >> k;
  fill(&board[0][0], &board[m-1][n], -1);

  for(int l = 0; l < k; l++) // 직사각형 색칠하기
  {
     cin >> leftunder.X >> leftunder.Y >> rightupper.X >> rightupper.Y;
    for(int i =leftunder.Y; i < rightupper.Y; i++) // 행
     for(int j = leftunder.X; j < rightupper.X; j++) // 열 
        board[i][j] = 0;
  }
 
// bfs 시작점 찾기

  for(int i = 0; i < m; i++) // 행
  {
     for(int j = 0; j < n; j++) // 열
    {
      if(board[i][j] == -1) // 색칠되지 않은 부분이라면 bfs를 합니다
      {
        int areatemp = 0;
        board[i][j] = 0; // 방문표시
        Q.push({i, j});
        sector++;

        while(!Q.empty())
        { 
          areatemp++;
          auto cur = Q.front(); Q.pop();
          for(int dir = 0; dir < 4; dir++)
          {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(board[nx][ny] == 0) continue;

            board[nx][ny] = 0; // 방문표시
            Q.push({nx, ny});
          }
        } // bfs end
        area.push_back(areatemp);
      }
    }    
  }

  sort(area.begin(), area.end());
  cout << sector << '\n';
  
  for(int i = 0; i < area.size(); i++)
    cout << area[i] << ' ';
}


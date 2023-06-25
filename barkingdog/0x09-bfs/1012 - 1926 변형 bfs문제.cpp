#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int tc;

int m, n, k; // 가로길이, 세로길이, 배추 갯수/ 열, 행
int x, y; // 배추갯수, 배추 x좌표, 배추 y좌표

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int, int>> Q;

  cin >> tc;

  while(tc--)
  {
    
    cin >> m >> n >> k;

    int res = 0; // 결과값 초기화 시켜주기
    for(int i = 0; i < n; i++)  // 보드값 0으로 초기화 시켜주기
      fill(board[i], board[i]+m, 0);

    while(k--)
    {
      cin >> x >> y; // x == 열, y == 행
      board[y][x] = -1; // 배추가 심어진 곳은 -1로 표시한다.
    }


    // (i,j)가 시작점이 될 수 있는지 체크. 배추가 심어져 있어야 하고 방문한 적이 없어야 함(-1)
    for(int i = 0; i < n; i++) // 행
    {
      for(int j = 0; j < m; j++) // 열 
      {
        if(board[i][j] != -1) continue; // (i,j)가 시작점이 될 수 있는지 체크. 배추가 심어져 있어야 하고 방문한 적이 없어야 함(-1)
        
        res++; // 벌레 수
        Q.push({i,j}); // 시작점이 될 수 있으면 bfs 초기세팅. queue에 넣고 값을 1로 수정한다.
        board[i][j] = 1; // 배추 심어진 곳 1로 변경

        while(!Q.empty()) // bfs start
        {
          auto cur = Q.front(); Q.pop();

          for(int dir = 0; dir < 4; dir++)
          {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] != -1) continue;

            board[nx][ny] = 1; // 배추 심어진 곳 1로 변경
            Q.push({nx,ny});
          }
          
        } // bfs end
      }

    }

    cout << res << '\n';
  }


}


/*
about BFS
1. 시작하는 지점을 큐에 push하고 방문했다는 표시를 남김.
2. 큐에서 행렬(좌표)값이 저장된 원소를 꺼내고, 해당 지점의 상하좌우로 인접한 칸에 대하여 3번 진행
3. 해당 칸을 이전에 방문했다면 아무 동작도 하지 않는다, 만약 방문한 적이 없다면 방문표시를 남기고 해당 칸의 좌표를 큐에 삽입한다.
4. 큐가 빌 때까지 2번을 반복한다.
모든 칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(n)이 된다.

board, visit, n/m, dx/dy, pair queue, pair current, nx/ny

시작점 찾는 문제. 이중 for문을 이용하여 시작점이 될 수 있는 부분을 찾고 그 부분에서 bfs를 돌려준다. 끝나면 다시 시작점 찾기.
*/
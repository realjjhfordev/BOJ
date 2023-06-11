#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair 함에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502]; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n,m; // 행렬, i는 행 j는 열
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  int mx = 0; // 그림의 최대 넓이값
  int num = 0; // 그림 수

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> board[i][j]; // 보드에 그림그리기

  for(int i = 0; i < n; i++) // 이중 for문으로 시작점 (i,j)찾기, 시작점이 되려면 방문한 적 x, 색칠(1)되어 있어야 함
  {
    for(int j = 0; j < m; j++)
    {
      if( vis[i][j] == 1 || board[i][j] == 0) continue; // continue -> 다음 열로 넘어간다.
      num++; // 그림수 증가

      queue<pair<int,int>> Q; // 좌표를 담을 큐 설정

      vis[i][j] = 1; //(i,j)를 시작점으로 삼고 BFS를 준비한다. 
      Q.push({i,j});

      int area = 0; // 그림의 넓이

      while(!Q.empty()) // BFS start
      {
        area++; // queue에 있는 원소 하나를 불러올 때마다 area는(그림의 크기) 1씩 커진다.
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(nx >= n || ny >= m || nx < 0 || ny < 0) continue; // 범위를 벗어난 경우 -> 넘어가고 다른 인접 칸 체크
          if(vis[nx][ny] == 1 || board[nx][ny] == 0) continue; // 방문 한 적 있거나 그림칸이 아닌(0) 경우 -> 넘어가고 다른 인접 칸 체크

          vis[nx][ny] = 1; // 인접 칸에 방문표시
          Q.push({nx,ny}); // 큐에 삽입
        }
      } // bfs end, while 문에서 빠져나온 후 이중 for 문으로 돌아가 새로운 bfs 시작지점을 찾는다.

      mx = max(mx, area); // area가 mx보다 큰 경우 mx에 area 대입. 그림의 크기가 가장 큰 경우를 구하는 함수
    }

  }
   cout << num << '\n' << mx;


}


/*
about BFS
1. 시작하는 지점을 큐에 push하고 방문했다는 표시를 남김.
2. 큐에서 행렬(좌표)값이 저장된 원소를 꺼내고, 해당 지점의 상하좌우로 인접한 칸에 대하여 3번 진행
3. 해당 칸을 이전에 방문했다면 아무 동작도 하지 않는다, 만약 방문한 적이 없다면 방문표시를 남기고 해당 칸의 좌표를 큐에 삽입한다.
4. 큐가 빌 때까지 2번을 반복한다.
모든 칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(n)이 된다.

board, visit, n/m, dx/dy, pair queue, pair current, nx/ny


1926
상하좌우로 연결된 그림의 크기를 알아내라. -> queue에 있는 원소 하나를 불러올 때마다 area는(그림의 크기) 1씩 커진다.
도화지에 있는 모든 그림을 찾아내라. -> 이중 for문을 사용하여 적절한 시작지점을 골라(그림의 일부면서, 아 방문한 적이 없는 부분) bfs를 시작한다.
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] ={1, 0, -1, 0};
int dy[4] ={0, 1, 0, -1};

int main()
{
 int n, m; // 행과 열의 수
 cin >> n >> m;
 int dist[n][m]; // 방문여부와 동시에 시작점으로부터의 거리를 저장하는 2차원 배열

 string board[n]; // 입력데이터가 공백으로 구분되어있지 않아서 스트링사용 board[n][m] -> n행에있는 원소에서 m번째 글자를 가져옴

  for(int i = 0; i < n; i++) // n줄 작성
    cin >> board[i];

  for(int i = 0 ; i < n; i++) // dist 전부 -1로 초기화하면 방문여부와 시작점으로 부터의 거리 모두 기록할 수 있다
    fill(dist[i], dist[i]+m, -1); //dist[0] == dist[0][0], dist[1] == dist[1][0], dist[0]+1 == dist[0][1]  
    //dist[i] 부터 dist[i]+m 직전까지(dist[i]+m은 포함하지 않음) -1로 초기화

  queue<pair<int,int>> Q;

  Q.push({0, 0});
  dist[0][0] = 0; // bfs 시작을 위한 준비단계

  while(!Q.empty()) // bfs start
  {
    auto cur = Q.front(); Q.pop(); // auto cur == pair<int, int> cur
    for(int dir = 0; dir < 4; dir++) // 인접한 칸에 대하여 방문
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) // 범위 체크
      if(board[nx][ny] != '1' || dist[nx][ny] != -1 ) // 보드에서 1인지, 방문 여부 체크
      dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 방문을 한다는 표시를 함과 동시에 시작점으로 부터의 거리를 삽입
      Q.push({nx, ny});
    }
  }

  cout << dist[n-1][m-1] + 1;

}


/*
about BFS
1. 시작하는 지점을 큐에 push하고 방문했다는 표시를 남김.
2. 큐에서 행렬(좌표)값이 저장된 원소를 꺼내고, 해당 지점의 상하좌우로 인접한 칸에 대하여 3번 진행
3. 해당 칸을 이전에 방문했다면 아무 동작도 하지 않는다, 만약 방문한 적이 없다면 방문표시를 남기고 해당 칸의 좌표를 큐에 삽입한다.
4. 큐가 빌 때까지 2번을 반복한다.
모든 칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(n)이 된다.
board, visit, n/m, dx/dy, pair queue, pair current, nx/ny
*/


/*
16~18 ex1

string 배열

board[0] "101111"
board[1] "101010"
board[2] "101011"
board[3] "111011"

board[0][0] -> 1
board[0][1] -> 0 ...
*/
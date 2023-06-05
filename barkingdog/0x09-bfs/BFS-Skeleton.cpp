#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair 함에서 first, second를 줄여서 쓰기 위해서 사용

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

 bool vis[502][502]; // 해당 칸 방문여부를 저장하는 변
 int n = 7, m = 10; // n = 행의 수, m = 열의 수
 int dx[4] = {1, 0, -1, 0};
 int dy[4] = {0, 1, 0, -1}; // 상하좌우에 있는 칸을 쉽게 접근하기 위해 사용하는 변수

int main(void){

  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int,int>> Q; // int값 한 쌍(한 지점, 좌표)을 저장하는 큐 선언
  vis[0][0] = 1; // (0, 0)을 방문했다
  Q.push({0,0}) // 큐에 시작점인 (0, 0) 삽입
  while(!Q.empty())
  {
    pair<int,int> cur = Q.front(); Q.pop(); // cur = 현재 위치를 저장하는 변수, 큐에서 좌표값을 가져온 뒤 큐에서 제거해준다.
     for(int dir = 0; dir < 4; dir++) // cur에서 인접한 상하좌우 칸을 살펴볼 것이다.  
     {
      int nx = cur.X + dx[dir]
      int ny = cur.Y + dx[dir] // cur에서 인접한 상하좌우칸의 좌표가 nx, ny에 들어간다.

      //예외처리
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // board 범위 밖일 경우(행은 n, 열은 m줄 존) 넘어감
      if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우 넘어감
      
      vis[nx][ny] = 1; // 예외처리에 걸리지 않는 경우! (nx, ny)를 방문했다고 명시해주고
      Q.push({nx,ny}); // 인접했던 그 칸의 좌표값을 큐에 넣어준다.
     }
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
*/
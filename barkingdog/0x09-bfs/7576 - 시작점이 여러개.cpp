#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair 함에서 first, second를 줄여서 쓰기 위해서 사용

int tomato[1002][1002]; // 맥스값은 1000이지만 넉넉하게 1002로 준다
int n, m; // 행렬
int dist[1002][1002]; // 익는 데 까지 남은 일
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int,int>> Q;
  cin >> m >> n;

  for(int i = 0; i < n; i++) // 행
  	for(int j = 0; j < m; j++) // 열
  	{
		cin >> tomato[i][j];
		if(tomato[i][j] == 1) // 익은 토마토
			Q.push({i,j}); 
		if(tomato[i][j] == 0) // 익지 않은 토마토
			{
				dist[i][j] = -1; // 안익은 토마토를 익은토마토와 토마토가 없는 상황과 구분하기 위해
			}
  	}	


  	while(!Q.empty()) // bfs start
  	{
  		auto cur = Q.front(); Q.pop();
  		for(int dir = 0; dir < 4; dir++)
  		{
  			int nx = cur.X + dx[dir];
  			int ny = cur.Y + dy[dir];

  			if(nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
  			if(dist[nx][ny] != -1) continue; // 아직 방문한 적이 없는 & 안익은 토마토를 방문한다(bfs 한다)

  			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
  			Q.push({nx,ny});
  		}

    }


 	int ans = 0;

 	for(int i = 0; i < n; i++)
 	{
 		for(int j = 0; j < m; j++)
 		{
 			if(dist[i][j] == -1)
 				{
 					cout << "-1";
 					return 0;
 				}
 			if(dist[i][j] > ans)
 			{
 				ans = dist[i][j];
 			}
 		}

 	}

 	cout << ans;


}


/*bfs의 시작점이 여러개 -> 일단 '모든 시작점을 큐에 넣고' 똑같이 BFS를 돌면 끝 */
/*
안익은 토마토가 bfs가 끝난 이후에도 익지 못한 경우 -> dist가 -1인 경우가 있는지 확인한다
저장될 때부터 모든 토마토가 익어있는 상황-> bfs 생략, line 51로 바로 넘어옴 -> ans는 그대로 0, 0출력
정답은 dist에서 가장 큰 수를 출력하면 된다.
*/

/*
about BFS
1. 시작하는 지점을 큐에 push하고 방문했다는 표시를 남김.
2. 큐에서 행렬(좌표)값이 저장된 원소를 꺼내고, 해당 지점의 상하좌우로 인접한 칸에 대하여 3번 진행
3. 해당 칸을 이전에 방문했다면 아무 동작도 하지 않는다, 만약 방문한 적이 없다면 방문표시를 남기고 해당 칸의 좌표를 큐에 삽입한다.
4. 큐가 빌 때까지 2번을 반복한다.
모든 칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(n)이 된다.
board, visit, n/m, dx/dy, pair queue, pair current, nx/ny
*/
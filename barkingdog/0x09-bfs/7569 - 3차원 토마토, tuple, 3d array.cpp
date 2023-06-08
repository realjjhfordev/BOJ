#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair 함에서 first, second를 줄여서 쓰기 위해서 사용
int tomato[102][102][102]; // 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸
int dist[102][102][102]; 

int dx[6] = {0, 0, 0, 0, 1, -1}; // 행
int dy[6] = {0, 0, 1, -1, 0, 0}; // 열
int dz[6] = {1, -1, 0, 0, 0, 0}; // 면
//상하좌우앞뒤

int m, n, h; // 가로, 세로, 높이

int main (void)
{
	queue<tuple<int, int, int>> Q;
	cin >> m >> n >> h; // 열,행,면

	for(int i = 0; i < h; i++) // 면, 높이(깊이)
		for(int j = 0; j < n; j++) // 행, 가로
			for(int k = 0; k < m; k++) // 열, 세로
			{
				cin >> tomato[i][j][k];
				if(tomato[i][j][k] == 0) // 안익토와 익토/토마토x칸을 구분하기 위해, 방문 체크를 하기 위해 -1로 초기화
					dist[i][j][k] = -1; // dist 값이 -1 == 안익토, 방문한 적 x
				if(tomato[i][j][k] == 1)
					Q.push({i, j, k}); // 익토의 좌표값을 queue에 push
			}

	while(!Q.empty()) 	//bfs start
	{
	 auto cur = Q.front(); Q.pop(); // i, j, k 면, 행, 열
	 for(int dir = 0; dir < 6; dir++)
	 {
	 	int nx = get<1>(cur) + dx[dir]; // 행
	 	int ny = get<2>(cur) + dy[dir]; // 열
	 	int nz = get<0>(cur) + dz[dir]; // 면

	 	if(nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
	 	if(dist[nz][nx][ny] != -1) continue;

	 	dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
	 	Q.push({nz, nx, ny});
	 }

	}

	int ans = 0;

	for(int i = 0; i < h; i++) // 면, 높이(깊이)
		for(int j = 0; j < n; j++) // 행, 가로
			for(int k = 0; k < m; k++) // 열, 세로
			{
				if(dist[i][j][k] > ans)
					ans = dist[i][j][k];

				if(dist[i][j][k] == -1)
				{
					cout << "-1";
					return 0;
				}
			}

	cout << ans;


}




/*
3개 쌍의 자료를 다룰 때에는 STL Tuple을 사용한다.

3차원배열 -> ary[면][행][열]
*/






/*bfs의 시작점이 여러개 -> 일단 '모든 시작점을 큐에 넣고' 똑같이 BFS를 돌면 끝 */
/*
안익은 토마토가 bfs가 끝난 이후에도 익지 못한 경우 -> dist가 -1인 경우가 있는지 확인한다

저장될 때부터 모든 토마토가 익어있는 상황-> bfs 생략, line 51로 바로 넘어옴 -> ans는 그대로 0, 0 출력
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
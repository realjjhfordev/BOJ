#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 

int ary[200002]; // 아무리 많이 벗어나도 음수이거나 20만 이상(100000*2)을 벗어나지는 않음

int dx[3] = {1, -1, 2}; // 앞, 뒤, 현위치 * 2 순간이동

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  fill(ary, ary + 200002, -1); // -1로 초기화하여 방문 해야할 곳 & 방문여부 체크
  int n, k;

  cin >> n >> k; // n == 수빈
  ary[n] = 0; // 수빈이가 있는 곳의 값을 0으로 설정한다 (방문했음!)

  queue<int> Q;
  Q.push(n); // 수빈의 위치를 큐에 넣는다
  
  while(!Q.empty()) // bfs start
  {
    int nx;
    
    auto curX = Q.front(); Q.pop(); // queue에서 좌표 가져오기

    for(int dir = 0; dir < 3; dir++) // 탐색
    {
      if(dir != 2)
        nx = curX + dx[dir]; // 앞으로 갔다 뒤로 갔다 curX*2 순간이동
      else // dir == 2, 2배 순간이동 
        nx = curX * dx[dir];

      if(nx < 0 || nx > 200001) continue; // 아무리 많이 벗어나도 음수이거나 20만 이상(100000*2)을 벗어나지는 않음. 
                                          //음수번째 칸을 들리는 경우는 무조건 최단거리가 아님.
      if(ary[nx] != -1) continue; // 방문한 적이 있다면 패스
      
      ary[nx] = ary[curX] + 1;
      Q.push(nx);
    }

  }

cout << ary[k];


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
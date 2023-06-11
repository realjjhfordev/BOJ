#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int r, c; // 입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1
          // ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.
string board[1002]; // 행의 max 수만큼 선
int fire[1002][1002];
int jihoon[1002][1002];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c; // row and column

  queue<pair<int, int>> Q1; // fire bfs queue
  queue<pair<int, int>> Q2; // jihoon vfs queue

  for (int i = 0; i < r; i++) // input data
    cin >> board[i];

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) 
    {
      if (board[i][j] == 'J' || board[i][j] == '.')  // 불과 지훈이가 지나갈 수 있는 공간들을 -1로 초기화 합니다. 지훈이가 있는 공간도 -1로 초기화 하는데, 이는 fire bfs에서만 사용합니다. (지훈이가 있는 곳에도 불이 옮겨붙을 수 있도록)
      {
        jihoon[i][j] = -1;
        fire[i][j] = -1;
      }
      if (board[i][j] == 'F')
        Q1.push({i, j}); // 불의 위치 -> Q1
      if (board[i][j] == 'J')
        Q2.push({i, j}); // 지훈의 위치 -> Q2
    }

  while (!Q1.empty()) // FIRE BFS, 불이 지나갈 수 있는 공간에서 퍼지는 데 걸리는 시간들을 계산
  {
    auto cur = Q1.front();
    Q1.pop(); // pair<int,int> cur

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir]; // 행
      int ny = cur.Y + dy[dir]; // 열

      if (nx < 0 || ny < 0 || nx >= r || ny >= c)
        continue;
      if (fire[nx][ny] != -1)
        continue;

      fire[nx][ny] = fire[cur.X][cur.Y] + 1;
      Q1.push({nx, ny});
    }

  } // fire bfs end

  auto cur2 = Q2.front();
  jihoon[cur2.X][cur2.Y] = 0; // line 28에서 지훈이의 위치를 0으로 설정합니다 (원상복구)

  while (!Q2.empty()) // jihoon bfs start
  {
    cur2 = Q2.front();
    Q2.pop(); // pair<int,int> cur

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur2.X + dx[dir]; // 행
      int ny = cur2.Y + dy[dir]; // 열

      if ((nx < 0 || ny < 0 || nx >= r || ny >= c)) 
      {
        cout << jihoon[cur2.X][cur2.Y] + 1;
        return 0;
      } // 행렬범위를 벗어나면 탈출에 성공한 것

      if (jihoon[nx][ny] != -1)
        continue; // 지날 수 있는 공간들만 탐색하고, 전에 방문한 적이 있다면 패스합니다.
      jihoon[nx][ny] = jihoon[cur2.X][cur2.Y] + 1;

      if (jihoon[nx][ny] >= fire[nx][ny] && fire[nx][ny] != -1) // 이미 경로에 불길이 번진 후라면 값을 0으로 만든 후(방문표시) 좌표를 큐에 넣지 않고 패스합니다. 단 항상 길에 불이 붙는다는 보장이 없으므로 fire가 -1인 경우는(길에 불이 붙지 않은) 제외해줘야 합니다. https://www.acmicpc.net/board/view/94259
      {
        jihoon[nx][ny] = 0;
        continue;
      }
      Q2.push({nx, ny});
    }

  }                     // jihoon bfs end
  cout << "IMPOSSIBLE"; // 탈출에 실패했다.

}
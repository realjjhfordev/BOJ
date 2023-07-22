#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair 함에서 first, second를 줄여서 쓰기 위해서 사용
string board[102]; // 열의 갯수는 정해지지 않음(입력받을 것임)
int vs[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

void bfs(int i, int j) // bfs function
{
  queue<pair<int, int>> Q;
  Q.push({i, j});

  while(!Q.empty()) // bfs로 flood fill
  {
   auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if(vs[nx][ny] != -1 || board[i][j] != board[nx][ny] ) continue; // 2번째 조건 Flood fill 새로운 표현 주목!! 인접칸과 같지 않은 경우 건너뜀!
      vs[nx][ny] = 0;
      Q.push({nx, ny});
    }
   } // bfs end  
}

  int area_count(int area) // area count function, 구분되는 영역들의 갯수를 센다
  {
    for(int i = 0; i < n; i++) // 행
  {
    for(int j = 0; j < n; j++) // 열
    {
      if(vs[i][j] != -1) continue; 

      //시작점을 찾았다면 bfs를 시작해주자.
      area++;
      vs[i][j] = 0;
      bfs(i, j);
    }
  }
    return area;
  }


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int area = 0;
  int jrsy_area = 0;
  cin >> n;

  for(int i = 0; i < n; i++)
    fill(vs[i], vs[i] + n, -1); // vs array를 -1로 초기

  for(int i = 0; i < n; i++)
    cin >> board[i]; // 1행씩 그림입력


 //적록색약이 아닌 사람이 보는 영역
  area = area_count(area);
     

  for(int i = 0; i < n; i++)
    fill(vs[i], vs[i] + n, -1); // 적록색약 구하기 위해 초기화

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(board[i][j] == 'G') board[i][j] = 'R';

  //적록색약인 사람이 보는 영역
  jrsy_area = area_count(jrsy_area);

cout << area << ' ' << jrsy_area;

}

// line 25의 2번째 조건에서 Flood fill에 대한 새로운 표현 주목!! 인접칸과 같지 않은 경우 건너뜀!